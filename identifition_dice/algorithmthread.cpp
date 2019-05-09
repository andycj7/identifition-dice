#include "algorithmthread.h"

CAlgorithmThread::CAlgorithmThread(QObject *parent)
{
    handleAlgorithmFlag=0;
}

void CAlgorithmThread::handl_algorithm()
{
    for(int i=0;i<fileList.size();i++)
    {
        if(fileIdentList[i]==false)
        {
            QString fname=fileList.at(i);
            std::string f=fname.toLocal8Bit().toStdString();
            Mat src=cv::imread(f,1);
            ident_points tool(src);
            //分析图片的获取
            QPixmap labelimage,contourimage,histimage;
            QVector<QPixmap> segmimage;
            tool.matToimage(labelimage,contourimage,histimage,segmimage);
            int total=tool.get_totalnumber();
            emit finish_algorithm(total,i,labelimage,contourimage,histimage);
        }
    }
    emit finish_all();
}

void CAlgorithmThread::set_filelist(QStringList filelist,QList<bool> fileidentlist)
{
    fileList=filelist;
    fileIdentList=fileidentlist;
}


void CAlgorithmThread::run()
{
    handl_algorithm();
}

CAlgorithmThread::~CAlgorithmThread()
{

}
