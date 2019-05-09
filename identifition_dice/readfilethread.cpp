#include "readfilethread.h"

CReadFileThread::CReadFileThread(QObject *parent)
{
}

QString CReadFileThread::get_filename(QString pathname)
{
    int length=pathname.size();
        QString filename="";
        int filename_length=0;
        for(int i=0;i<length;i++){
            
            if(pathname.at(length-i-1)!='/'){
                
                filename_length++;
            }
            else
                break;
        }
        for(int j=0;j<filename_length;j++){
            
            int index=length-filename_length;
            filename.append(pathname.at(index+j));
        }
        return filename;
}

QStringList CReadFileThread::get_failfilelist()
{
   return failFileList;
}

QStringList CReadFileThread::get_succeedfilelist()
{
    return succeedFileList;
}

void CReadFileThread::set_filelist(QStringList filelist)
{
    fileList=filelist;
}

void CReadFileThread::run()
{
    for(int i=0;i<fileList.size();i++){

        QImage pimage(fileList[i]);
        QPixmap p=QPixmap::fromImage(pimage);
        p.load(fileList[i]);
        if(!p.isNull()){

            succeedFileList.push_back(fileList[i]);
            emit update_listwidgetitem(fileList[i],p);
        }
        else{

            failFileList.push_back(fileList[i]);
        }
    }
    emit finish_readfile(succeedFileList,failFileList);
}

CReadFileThread::~CReadFileThread()
{

}
