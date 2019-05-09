#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QScrollArea>
#include <QMenu>
#include <QContextMenuEvent>
#include <QListWidgetItem>
#include <form3.h>
#include <QMap>
#include <QStringList>
#include <QMutex>
namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();

    QString get_filename(QString pathname);
    QMap<QString,int> get_selectedfile();
    void delete_selectedfile(QMap<QString,int> fileMap);

signals:

private slots:
    void on_imageshowMax(QListWidgetItem *);
    void on_updatelistwidget(QString filepath,QPixmap p);
    void on_finishalgorithm(int dicenumber,int index,QPixmap psrc1,QPixmap psrc2,QPixmap psrc3);

private:
    Ui::Form1 *ui;
    Form3 *showMaxWidget; //放大显示窗口
    int image_width;
    int image_height;
    QStringList fileList;
};

#endif // FORM1_H
