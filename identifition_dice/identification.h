#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QPixmap>
using namespace cv;
using namespace std;
class ident_points
{
public:
    ident_points(Mat srcImage);
	void find_allcontours(Mat &src,
		                  Mat &dst,
		                  vector<vector<Point>> &contour,
						  uchar color,
						  uchar way);
	void find_contoursList(vector<vector<Point>> &src_contours,
		                   vector<Rect> &dst_rectList,
						   vector<vector<Point>> &dst_contoursList);
	Mat remove_background(Mat src1,Mat src2);
    void handle_per_dice();
	void comminute_picture();
    int get_totalnumber();
	//结果显示的处理
	void print_points_position();
	void draw_rect_region();
	void draw_histimage();
    //1:标注图 2:轮廓图 3:直方图 4:分割图
    void matToimage(QPixmap &pdst1,QPixmap &pdst2,QPixmap &pdst3,QVector<QPixmap> &pdst4);
private:
	Mat src;  //用作处理的图
	Mat src1; //原图
	Mat hsv;
	Mat histimage; //直方图
    Mat contourimage;//轮廓图
	vector<int> diceNumber; //点数
    vector<Point> position; //位置
	vector<Rect> rectList;  //外接矩形列表
	vector<vector<Point>> contoursList;//骰子面轮廓的列表
	vector<Mat> diceList;            //骰子面的列表
};


#endif
