#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QSplitter>
#include <QDebug>
#include <QStandardItemModel>
namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();

    QString get_filename(QString pathname);
    QMap<QString,int> get_selectedfile();
    void delete_selectedfile(QMap<QString,int> fileMap);

private slots:
    void on_updatefilelist(QString filepath);
    void on_updateshow(QModelIndex file);
    void on_updateimage(int dicenumber,int index,QPixmap p1,QPixmap p2,QPixmap p3);

signals:
    void update_filelist(QStringList filelist);

private:
    Ui::Form2 *ui;
    QStringList fileList;
    QVector<QPixmap> labelImage;
    QVector<QPixmap> contourImage;
    QVector<QPixmap> histImage;
    QStandardItemModel* model;
};

#endif // FORM2_H
