#ifndef FORM3_H
#define FORM3_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();
    void setpicture(QString pathname);

private:
    Ui::Form3 *ui;
    QLabel *imageLabel;
};

#endif // FORM3_H
