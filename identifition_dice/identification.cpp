#include <identification.h>

ident_points::ident_points(Mat srcImage)
{
	resize(srcImage,srcImage,Size(600,600*srcImage.rows/srcImage.cols));
	src=srcImage.clone();
	src1=srcImage.clone();
	Mat kernel=(Mat_<double>(3,3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src,src,src.depth(),kernel);
	Mat dst;
	vector<vector<Point>> contours;
	find_allcontours(src,dst,contours,150,1);
	find_contoursList(contours,rectList,contoursList);
	if(rectList.size()<5)
	{
		cout<<"方法1识别失败"<<endl;
		Mat src2=src1.clone();
		cvtColor(src2,hsv,CV_BGR2HSV);
		for(int j=0;j<hsv.cols;j++)
			for(int i=0;i<hsv.rows;i++)
			{
				hsv.at<Vec3b>(i,j)[2]=hsv.at<Vec3b>(i,j)[2]*2/3;
			}
		cvtColor(hsv,src2,CV_HSV2BGR);
		src1=src2.clone();
		Mat kernel=(Mat_<double>(3,3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
		filter2D(src2,src2,src.depth(),kernel);
		contours.clear();
		rectList.clear();
		contoursList.clear();
		find_allcontours(src2,dst,contours,150,1);
		find_contoursList(contours,rectList,contoursList);
		if(rectList.size()!=5)
		{
			cout<<"方法2成功";
		}
	}
	else
	{
		cout<<"方法1成功"<<endl;
	}
	comminute_picture();
	handle_per_dice();
	draw_histimage();
	draw_rect_region();
}
void ident_points::find_allcontours(Mat &src,
		                  Mat &dst,
		                  vector<vector<Point>> &contour,
						  uchar color,
						  uchar way)
{
	inRange(src,Scalar(color,color,color),Scalar(255, 255, 255), dst);
	Mat element2=getStructuringElement(MORPH_RECT,Size(3,3));
	if(way==1)
	{
		morphologyEx(dst, dst,MORPH_ERODE,element2);
	}
	else if(way==2)
	{
		morphologyEx(dst, dst,MORPH_DILATE,element2);
	}
    contourimage=dst.clone();
	findContours(dst,contour,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> contour1 = contour;
	for(unsigned int i=0;i<contour.size();i++)
	{
		convexHull(contour[i],contour1[i],true);         //寻找凸包，来防止外围轮廓无法闭合
		drawContours(src,contour,i,Scalar(255,250,250),2,8);
	}
	contour = contour1;
}
void ident_points::find_contoursList(vector<vector<Point>> &src_contours,
		                   vector<Rect> &dst_rectList,
						   vector<vector<Point>> &dst_contoursList)
{
	   vector<double> areaList;
		for (unsigned int i = 0; i < src_contours.size(); i++) 
		{
			double area =contourArea(src_contours[i]);
			Rect rect =boundingRect(src_contours[i]);
			cout<<area<<endl;
			cout<<"****"<<rect;
		    if (abs(rect.width - rect.height) > 20 || rect.width > 200 || rect.height > 200) 
			{
				src_contours.erase(src_contours.begin()+i);//此函数会减少迭代器的中成员个数，因此指向会变
				i--;
				continue;
			}                        
			if (area >4000)
			{
				dst_rectList.push_back(rect);
				dst_contoursList.push_back(src_contours[i]);
				areaList.push_back(area);
				cout<<"///////"<<area<<endl;
			}
		}
}
void ident_points::comminute_picture()
{
	for (unsigned int i = 0; i < rectList.size(); i++) 
		{
			Mat getOneDice;
			Rect rect = rectList[i];
			Mat mask = Mat::zeros(src.size(),CV_8UC1);
			drawContours(mask,contoursList,i,Scalar(255,255,255),CV_FILLED);
			src1.copyTo(getOneDice, mask);
			diceList.push_back(getOneDice);
    }
}

int ident_points::get_totalnumber()
{
    int total=0;
       for(unsigned int i=0;i<diceNumber.size();i++)
       {
           total+=diceNumber[i];
       }
       return total;
}
void ident_points::handle_per_dice()
{
	for(unsigned int j = 0;j<diceList.size();j++) 
	{
		//对每个骰子面分别处理
		Mat dice = diceList[j];
		inRange(dice,Scalar(160,160,160),Scalar(255, 255, 255), dice);
		Mat dice1=remove_background(dice,diceList[j]); //获得红色点的图
        cvtColor(dice1,dice1,CV_BGR2GRAY);
		Mat kerne3 = getStructuringElement(MORPH_RECT,Size(7,7));
		Mat kerne2 = getStructuringElement(MORPH_RECT,Size(7,7));
		morphologyEx(dice1, dice1,MORPH_ERODE, kerne3);
		morphologyEx(dice1, dice1,MORPH_DILATE, kerne2);
		threshold(dice1, dice1,20, 255,THRESH_BINARY);
		vector<vector<Point>> contours2;
		Point posite;
		findContours(dice1,contours2,RETR_EXTERNAL,CHAIN_APPROX_NONE);
		if(contours2.size()!=0)
		{
			Rect rect = boundingRect(contoursList[j]);
			posite.x = rect.x;
			posite.y = rect.y;
			diceNumber.push_back(contours2.size());
			position.push_back(posite);
		}
	}
}
void ident_points::print_points_position()
{
	for(unsigned int i=0; i<diceNumber.size();i++)   
	{
		Point point = position[i];
		int num = diceNumber[i];
		cout<<point<<endl<<num<<endl;
	}
}
Mat ident_points::remove_background(Mat src1,Mat src2)
{
	for(int i=0;i<src1.rows;i++)
		for(int j=0;j<src1.cols;j++)
		{
			if(src1.at<uchar>(i,j)==255)
			{
				src2.at<Vec3b>(i,j)[0]=0;
				src2.at<Vec3b>(i,j)[1]=0;
				src2.at<Vec3b>(i,j)[2]=0;
			}
		}

    return src2;
}

void ident_points::draw_rect_region(void)
{
	for(size_t i=0;i<rectList.size();i++)
	{
		Point p1=Point(rectList[i].x,rectList[i].y);
		Point p2=Point(rectList[i].x+rectList[i].height,rectList[i].y+rectList[i].width);
	    rectangle(src1,p1,p2,Scalar(0,0,255),2);

		string number;
		number.push_back(0x30+diceNumber[i]);
		Point pt=Point(rectList[i].x+rectList[i].height/2,rectList[i].y+rectList[i].width/2);
		putText(src1,number,pt,cv::FONT_HERSHEY_DUPLEX,1, cv::Scalar(0,0,0 ),2);
	}
}

void ident_points::draw_histimage()
{
	//定义变量
	MatND dstHist;
	int dims=1;
	float hranges[]={0,255};
	const float *ranges[]={hranges};
	int size=256;
	int channels=0;

	calcHist(&src1,1,&channels,Mat(),dstHist,dims,&size,ranges);
	int scale=1;
	histimage.create(size*scale,size,CV_8U);

	double minValue=0;
	double maxValue=0;

	minMaxLoc(dstHist,&minValue,&maxValue,0,0);

	int hpt=saturate_cast<int>(0.9*size);
	for(int i=0;i<256;i++)
	{
		float binValue=dstHist.at<float>(i);
		int realValue=saturate_cast<int>(binValue*hpt/maxValue);//让值在0-255之间
		//Point的坐标系与图像坐标系相反
		rectangle(histimage,Point(i*scale,size-1),Point((i+1)*scale-1,size-realValue),Scalar(255));
    }
}

void ident_points::matToimage(QPixmap &pdst1, QPixmap &pdst2, QPixmap &pdst3, QVector<QPixmap> &pdst4)
{
    Mat m1;
    cvtColor(src1,m1,CV_BGR2RGB);
    QImage p1(m1.data,m1.cols,m1.rows,QImage::Format_RGB888);
    pdst1=QPixmap::fromImage(p1);

    QImage p2(contourimage.data,contourimage.cols,contourimage.rows,QImage::Format_Indexed8);
    pdst2=QPixmap::fromImage(p2);

    QImage p3(histimage.data,histimage.cols,histimage.rows,QImage::Format_Indexed8);
    pdst3=QPixmap::fromImage(p3);

    for(size_t i=0;i<diceList.size();i++)
    {
        Mat m4;
        cvtColor(diceList[i],m4,CV_BGR2RGB);
        QImage p=QImage(m4.data,m4.cols,m4.rows,QImage::Format_RGB888);
        QPixmap p1=QPixmap::fromImage(p);
        pdst4.push_back(p1);
    }
}



