#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(QString("骰子识别"));
    QIcon icon(QPixmap(":/timg.jpg"));
    w.setWindowIcon(icon);
    return a.exec();
}
