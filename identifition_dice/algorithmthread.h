#ifndef ALGORITHMTHREAD_H
#define ALGORITHMTHREAD_H

#include <QThread>
#include <QPixmap>
#include <identification.h>
class CAlgorithmThread:public QThread
{
    Q_OBJECT
public:
    explicit CAlgorithmThread(QObject *parent=nullptr);
    void handl_algorithm();
    void set_filelist(QStringList filelist,QList<bool> fileidenlist);

    void run() override;
    ~CAlgorithmThread() override;

signals:
    void finish_algorithm(int dicenumber,int index,QPixmap psrc1,QPixmap psrc2,QPixmap psrc3);
    void finish_all();

private:
    bool handleAlgorithmFlag;
    QStringList fileList;
    QList<bool> fileIdentList;
};

#endif // ALGORITHMTHREAD_H
