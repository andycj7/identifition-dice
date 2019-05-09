#ifndef READFILETHREAD_H
#define READFILETHREAD_H

#include <QThread>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QMap>
#include <QImage>
#include <QTimer>
class CReadFileThread:public QThread
{
    Q_OBJECT
public:
    explicit CReadFileThread(QObject *parent=nullptr);
    QString get_filename(QString pathname);
    QStringList get_failfilelist();
    QStringList get_succeedfilelist();
    void set_filelist(QStringList filelist);

    void run() override;
    ~CReadFileThread() override;

signals:
    void finish_readfile(QStringList succeedFile,QStringList failFile);
    void update_listwidgetitem(QString filepath,QPixmap p);
    
private:
    QStringList fileList;           //所选取的文件列表
    QStringList succeedFileList;    //读取成功的列表
    QStringList failFileList;       //读取失败的列表
};

#endif // READFILETHREAD_H
