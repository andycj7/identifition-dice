#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);//最后一列自适应宽度 设置完显示整个表格都是一列
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);   //不能编辑
    ui->tableView->setSelectionBehavior(QTableView::SelectRows);  //一次选中整行
    ui->tableView->setSelectionMode(QTableView::ExtendedSelection);  //单行选中
    ui->tableView->setAlternatingRowColors(true);                 //行间隔色
    ui->tableView->setShowGrid(false);                            //去掉网格线
    ui->tableView->setFocusPolicy(Qt::NoFocus);                   //去掉item选中时虚线框
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("文件名")));
    ui->tableView->setModel(model);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(on_updateshow(QModelIndex)));
}

Form2::~Form2()
{
    delete ui;
    delete model;
}

QString Form2::get_filename(QString pathname)
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

QMap<QString, int> Form2::get_selectedfile()
{
     QMap<QString,int> tempMap;
     QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();
     for(int i=0;i<indexList.size();i++)
     {
         tempMap.insert(fileList[indexList[i].row()],indexList[i].row());
     }
     return tempMap;
}

void Form2::delete_selectedfile(QMap<QString, int> fileMap)
{
    QMap<QString,int>::iterator iter=fileMap.begin();
    for(;iter!=fileMap.end();iter++)
    {
        model->removeRow(iter.value());
        fileList.removeAt(iter.value());
        if(!labelImage.isEmpty())
        {
            labelImage.removeAt(iter.value());
            contourImage.removeAt(iter.value());
            histImage.removeAt(iter.value());
        }
    }
}

void Form2::on_updatefilelist(QString filepath)
{
    fileList.push_back(filepath);
    QString filename=get_filename(filepath);
    model->setItem(fileList.size()-1, 0, new QStandardItem(filename));
    model->item(fileList.size()-1, 0)->setTextAlignment(Qt::AlignLeft);
}

void Form2::on_updateshow(QModelIndex file)
{
    if(labelImage.isEmpty()||contourImage.isEmpty()||histImage.isEmpty())
        return;
    QPixmap p1=labelImage[file.row()];
    p1=p1.scaled(ui->tab->width(),ui->tab->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(p1);

    QPixmap p2=contourImage[file.row()];
    p2=p2.scaled(ui->tab->width(),ui->tab->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(p2);

    QPixmap p3=histImage[file.row()];
    p3=p3.scaled(ui->tab->width(),ui->tab->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->setPixmap(p3);

}


void Form2::on_updateimage(int dicenumber,int index,QPixmap p1, QPixmap p2, QPixmap p3)
{
    labelImage.push_back(p1);
    contourImage.push_back(p2);
    histImage.push_back(p3);

}
