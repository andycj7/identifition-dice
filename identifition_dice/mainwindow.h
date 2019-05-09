#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <form2.h>
#include <form1.h>
#include <QContextMenuEvent>
#include "readfilethread.h"
#include "algorithmthread.h"
#include <QMessageBox>
#include <QListWidget>
#include <QMap>
#include <QMutex>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString get_filename(QString pathname);
    void delete_selectedfile(QMap<QString,int> fileMap);

private slots:
    void on_pushButton_clicked();   //识别图像按钮的槽函数

    void on_readFileThreadStart();
    void on_finishReadFile(QStringList succeedFile,QStringList failFile);
    void on_identiThreadFinish(int dicenumber,int index,QPixmap psrc1,QPixmap psrc2,QPixmap psrc3);
    void on_allidentiThreadFinish();
    void on_displayway1Show();
    void on_displayway2Show();
    void on_closeActionHandle();
signals:


private:
    void creat_rightbuttonMenu();
    void contextMenuEvent(QContextMenuEvent *event);  //创建右键菜单
    void initDisplayWay1();
    void initDisplayWay2();


    Ui::MainWindow *ui;
    QStringList fileList;                             //选取的文件列表
    QList<bool> fileIdenList;                         //识别是否成功的文件列表
    QMenu *rightbuttonMenu;                           //右键菜单
    QAction *deleteaction;
    Form1 *displayWay1;
    Form2 *displayWay2;

};

#endif // MAINWINDOW_H
