#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <identification.h>
#include <QPixmapCache>
class workerthread : public QThread
{
    Q_OBJECT
public:
    //当way=0时，线程做文件读取工作，filelist是当前读取的文件列表
    //当way=1时，线程做图片识别工作，filelist为ui中的文件列表
    explicit workerthread(int way,QObject *parent=nullptr);
    QString get_filename(QString pathname);
    QStringList get_failfilelist();
    QStringList get_succeedfilelist();
    QPixmap get_picture();
    void assign_filelist1vlaue(QStringList filelist);
    void get_identflag(QList<bool> flag);
    void handle_readpicture();
    //识别处理函数
    void identification();

    void run() override;
    ~workerthread() override;//
signals:
    void update_listwidgetitem(int index);
    void finish_readpicture();

    void finish_identification(int dicenumber,int index,
                               QPixmap psrc1,
                               QPixmap psrc2,
                               QPixmap psrc3);
    void finish_allidentification();
private slots:

private:
    int way1;
    QPixmap p;
    QStringList filelist1;
    QStringList failfilelist;
    QStringList succeedfilelist;
    QList<bool> identflag;

    QPixmap histimage; //直方图
    QPixmap labelimage;//标注图
    QPixmap contourimage;//轮廓图
    QVector<QPixmap> segmimage;//分割图
};

#endif // WORKERTHREAD_H
