#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form1.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(800,600);
    initDisplayWay2();
    initDisplayWay1();
    creat_rightbuttonMenu();
    connect(ui->actionopen,SIGNAL(triggered(bool)),this,SLOT(on_readFileThreadStart()));
    connect(ui->action1,SIGNAL(triggered(bool)),this,SLOT(on_displayway1Show()));
    connect(ui->action2,SIGNAL(triggered(bool)),this,SLOT(on_displayway2Show()));
    connect(ui->actionclose,SIGNAL(triggered(bool)),this,SLOT(on_closeActionHandle()));
    ui->pushButton->setEnabled(false);
    ui->actionclose->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(displayWay1!=nullptr)
        delete displayWay1;
    if(displayWay2!=nullptr)
        delete displayWay2;
    delete deleteaction;
    delete rightbuttonMenu;
}

QString MainWindow::get_filename(QString pathname)
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

void MainWindow::delete_selectedfile(QMap<QString, int> fileMap)
{
    QMap<QString,int>::iterator iter=fileMap.begin();
    for(;iter!=fileMap.end();iter++)
    {
        fileList.removeAt(iter.value());
        fileIdenList.removeAt(iter.value());
    }
}

void MainWindow::on_displayway1Show()
{
    if(displayWay1->close())
    {
        displayWay2->close();
        displayWay1->show();
    }
}

void MainWindow::on_displayway2Show()
{
    if(displayWay2->close())
    {
        displayWay1->close();
        displayWay2->show();
    }
}

//开始读取线程槽函数
void MainWindow::on_readFileThreadStart()
{
    QStringList tempFileList=QFileDialog::getOpenFileNames(nullptr,"Select one or more files to open",QDir::currentPath(),"Images (*.png *.xpm *.jpg)");
    if(tempFileList.empty()==1)
    {
        return;//应该要有个空文件的通知
    }
    CReadFileThread *readpicturethread=new CReadFileThread();
    connect(readpicturethread,SIGNAL(update_listwidgetitem(QString,QPixmap)),displayWay1,SLOT(on_updatelistwidget(QString,QPixmap)));
    connect(readpicturethread,SIGNAL(update_listwidgetitem(QString,QPixmap)),displayWay2,SLOT(on_updatefilelist(QString)));
    connect(readpicturethread,SIGNAL(finish_readfile(QStringList,QStringList)),this,SLOT(on_finishReadFile(QStringList,QStringList)));
    connect(readpicturethread,SIGNAL(finished()),readpicturethread,SLOT(deleteLater()));
    readpicturethread->set_filelist(tempFileList);
    ui->actionclose->setEnabled(false);
    ui->actionopen->setEnabled(false);
    readpicturethread->start();
}
//结束线程槽函数
void MainWindow::on_finishReadFile(QStringList succeedFile,QStringList failFile)
{
   //图片读取成功的文件载入列表
   fileList.append(succeedFile);
   //取出图片未识别
   for(int i=0;i<succeedFile.size();i++)
   {
       fileIdenList.push_back(false);
   }
   //显示未读取成功的文件名
   if(!failFile.empty())
   {
       QString text;
       for(int i=0;i<failFile.size();i++)
       {
           text.append(failFile[i]);
           text.append("\n");
       }
       QMessageBox::information(this,tr("Fail"),text,QMessageBox::Yes,QMessageBox::Yes);
   }
   if(!fileList.empty())
   {
       ui->actionclose->setEnabled(true);
       ui->pushButton->setEnabled(true);
   }
   ui->actionopen->setEnabled(true);
}

//识别按钮槽函数
void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setValue(0);
    ui->pushButton->setEnabled(false);
    ui->actionclose->setEnabled(false);
    ui->actionopen->setEnabled(false);
    CAlgorithmThread *identification=new CAlgorithmThread();
    identification->set_filelist(fileList,fileIdenList);
    connect(identification,SIGNAL(finish_algorithm(int,int,QPixmap,QPixmap,QPixmap)),this,SLOT(on_identiThreadFinish(int,int,QPixmap,QPixmap,QPixmap)));
    connect(identification,SIGNAL(finish_algorithm(int,int,QPixmap,QPixmap,QPixmap)),displayWay1,SLOT(on_finishalgorithm(int,int,QPixmap,QPixmap,QPixmap)));
    connect(identification,SIGNAL(finish_algorithm(int,int,QPixmap,QPixmap,QPixmap)),displayWay2,SLOT(on_updateimage(int,int,QPixmap,QPixmap,QPixmap)));
    connect(identification,SIGNAL(finish_all()),this,SLOT(on_allidentiThreadFinish()));
    connect(identification,SIGNAL(finished()),identification,SLOT(deleteLater()));
    identification->start();
}
void MainWindow::on_identiThreadFinish(int dicenumber, int index, QPixmap psrc1, QPixmap psrc2, QPixmap psrc3)
{
    fileIdenList[index]=true;
    //更新进度条
    int value=(index+1)*100/fileList.size();
    ui->progressBar->setValue(value);
}

void MainWindow::on_allidentiThreadFinish()
{
    ui->pushButton->setEnabled(true);
    ui->actionclose->setEnabled(true);
    ui->actionopen->setEnabled(true);
    ui->progressBar->setValue(100);
}

void MainWindow::on_closeActionHandle()
{
    QMap<QString,int> tempMap;
    if(displayWay1->isVisible())
    {
        tempMap=displayWay1->get_selectedfile();
    }
    else if(displayWay2->isVisible())
    {
        tempMap=displayWay2->get_selectedfile();
    }
    delete_selectedfile(tempMap);
    displayWay1->delete_selectedfile(tempMap);
    displayWay2->delete_selectedfile(tempMap);
}

//右键菜单的实现
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    //把鼠标右键事件的全局坐标，转化为listwidget窗口的相对坐标
    QPoint i=ui->centralWidget->mapFromGlobal(event->globalPos());
    //listwidget的窗口区域
    QRect rect(QPoint(0,0),ui->centralWidget->size());
    //判断鼠标是否在区域中
    if(rect.contains(i))
    {
        rightbuttonMenu->exec(event->globalPos());
    }
}

void MainWindow::initDisplayWay1()
{
    displayWay1=new Form1(this);
    ui->verticalLayout->insertWidget(0,displayWay1);
}

void MainWindow::initDisplayWay2()
{
    displayWay2=new Form2(this);
    ui->verticalLayout->insertWidget(0,displayWay2);
    displayWay2->close();
}
//创建右键菜单
void MainWindow::creat_rightbuttonMenu()
{
    rightbuttonMenu=new QMenu();
    deleteaction=new QAction(tr("delete"),rightbuttonMenu);
    rightbuttonMenu->addAction(deleteaction);
    connect(deleteaction,SIGNAL(triggered(bool)),this,SLOT(on_closeActionHandle()));
}

