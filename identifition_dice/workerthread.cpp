#include "workerthread.h"
workerthread::workerthread(int way,QObject *parent):
                                way1(way),QThread(parent)
{

}

QString workerthread::get_filename(QString pathname)
{
    int length=pathname.size();
    QString filename="";
    int filename_length=0;
    for(int i=0;i<length;i++)
    {
        if(pathname.at(length-i-1)!='/')
        {
            filename_length++;
        }
        else
            break;
    }
    for(int j=0;j<filename_length;j++)
    {
        int index=length-filename_length;
        filename.append(pathname.at(index+j));
    }
    return filename;
}

QStringList workerthread::get_failfilelist()
{
    return failfilelist;
}

QStringList workerthread::get_succeedfilelist()
{
    return succeedfilelist;
}

QPixmap workerthread::get_picture()
{
    return p;
}

void workerthread::assign_filelist1vlaue(QStringList filelist)
{
    filelist1=filelist;
}

void workerthread::get_identflag(QList<bool> flag)
{
    identflag=flag;
}

void workerthread::handle_readpicture()
{
    for(int i=0;i<filelist1.size();i++)
    {
        QImage pimage(filelist1[i]);
        p=QPixmap::fromImage(pimage);
        p.load(filelist1[i]);
        if(!p.isNull())
        {
            succeedfilelist.push_back(filelist1[i]);
            emit update_listwidgetitem(i);
        }
        else
        {
            failfilelist.push_back(filelist1[i]);
        }
    }
    emit finish_readpicture();
}

void workerthread::identification()
{
    for(int i=0;i<filelist1.size();i++)
    {
        if(!identflag.at(i)) //图片未识别
        {
            QString fname=filelist1.at(i);
            std::string f=fname.toLocal8Bit().toStdString();
            Mat src=cv::imread(f,1);
            ident_points tool(src);
            //分析图片的获取
            tool.matToimage(labelimage,contourimage,histimage,segmimage);
            int total=tool.get_totalnumber();
            emit finish_identification(total,i,
                                       labelimage,
                                       contourimage,
                                       histimage);
        }
        else                //图片已经识别
        {

        }
    }
    emit finish_allidentification();
}

void workerthread::run()
{
    if(way1==0)
    {
        handle_readpicture();
    }
    else if(way1==1)
    {
        identification();
    }
}

workerthread::~workerthread()
{
    quit();
    wait();
}
