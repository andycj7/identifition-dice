#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    showMaxWidget=nullptr;
    image_width=100;
    image_height=150;
    ui->listWidget->setIconSize(QSize(image_width,image_height));
    ui->listWidget->setResizeMode(QListView::Adjust);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setMovement(QListView::Static);
    //设置多选模式 ctrl多选shift多选 但是多出了下划线
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    //消除下划线 下划线主要是启用键盘事件后 StronngFouse
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    ui->listWidget->setSpacing(8);
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_imageshowMax(QListWidgetItem*)));
}

Form1::~Form1()
{
    for(int i=0;i<ui->listWidget->count();i++)
    {
       delete ui->listWidget->item(i);
    }
    if(showMaxWidget!=nullptr)
    {
        delete showMaxWidget;
    }
    delete ui;
}

QString Form1::get_filename(QString pathname)
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

QMap<QString, int> Form1::get_selectedfile()
{
    QList<QListWidgetItem*> p=ui->listWidget->selectedItems();
    QMap<QString,int> tempMap;
    for(int i=0;i<p.size();i++)
    {
        tempMap.insert(fileList[ui->listWidget->row(p.at(i))],ui->listWidget->row(p.at(i)));
    }
    return tempMap;
}

void Form1::delete_selectedfile(QMap<QString, int> fileMap)
{
    QMap<QString,int>::iterator iter=fileMap.begin();
    for(;iter!=fileMap.end();iter++)
    {
        fileList.removeAt(iter.value());
        ui->listWidget->removeItemWidget(ui->listWidget->item(iter.value()));
        delete ui->listWidget->item(iter.value()); //需要释放内存才会更新UI
    }
}

void Form1::on_imageshowMax(QListWidgetItem *item)
{
    if(showMaxWidget!=nullptr)
    {
        delete showMaxWidget;
    }
    showMaxWidget=new Form3();
    int index=ui->listWidget->row(item); //列表结构就只有一行
    showMaxWidget->setpicture(fileList.at(index));
    showMaxWidget->show();
}

//更新UI添加文件槽函数
void Form1::on_updatelistwidget(QString filepath,QPixmap p)
{
    fileList.push_back(filepath);
    QString filename=get_filename(filepath);
    QListWidgetItem *listwidgetitem=new QListWidgetItem(QIcon(p.scaled(image_width,image_height)),filename);
    //单元项的高度和宽度
    listwidgetitem->setSizeHint(QSize(image_width,image_height+24));
    ui->listWidget->insertItem(fileList.size()+1,listwidgetitem);
}

void Form1::on_finishalgorithm(int dicenumber, int index, QPixmap psrc1, QPixmap psrc2, QPixmap psrc3)
{
    //在文件名后面显示识别的点数
    QString filename=ui->listWidget->item(index)->text();
    QString number=QString::number(dicenumber);
    filename.append('-');
    filename.append(number);
    ui->listWidget->item(index)->setText(filename);
}
