#include "form3.h"
#include "ui_form3.h"

Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
    setMinimumSize(500,600);
    imageLabel=new QLabel(this);
}

Form3::~Form3()
{
    delete ui;
    delete imageLabel;
}

void Form3::setpicture(QString pathname)
{
    QImage image(pathname);
    //QImage p=image.scaled(400,400*image.height()/image.width());
    imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(imageLabel);
}
