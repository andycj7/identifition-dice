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
	//�����ʾ�Ĵ���
	void print_points_position();
	void draw_rect_region();
	void draw_histimage();
    //1:��עͼ 2:����ͼ 3:ֱ��ͼ 4:�ָ�ͼ
    void matToimage(QPixmap &pdst1,QPixmap &pdst2,QPixmap &pdst3,QVector<QPixmap> &pdst4);
private:
	Mat src;  //���������ͼ
	Mat src1; //ԭͼ
	Mat hsv;
	Mat histimage; //ֱ��ͼ
    Mat contourimage;//����ͼ
	vector<int> diceNumber; //����
    vector<Point> position; //λ��
	vector<Rect> rectList;  //��Ӿ����б�
	vector<vector<Point>> contoursList;//�������������б�
	vector<Mat> diceList;            //��������б�
};


#endif
