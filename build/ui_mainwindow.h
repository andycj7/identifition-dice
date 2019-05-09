/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionclose;
    QAction *action2;
    QAction *action1;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuopen;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(626, 492);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"         background: rgb(232, 241, 252);\n"
"}\n"
"#listWidget{\n"
"background: rgb(173, 202, 232);\n"
"}\n"
"#menuBar{\n"
"        background: rgb(187, 212, 238);\n"
"        border: 1px solid rgb(111, 156, 207);\n"
"        border-left: none;\n"
"        border-right: none;}\n"
"QMenuBar::item {\n"
"        border: 1px solid transparent;\n"
"        padding: 5px 10px 5px 10px;\n"
"        background: transparent;\n"
"}\n"
"QMenuBar::item:enabled {\n"
"        color: rgb(2, 65, 132);\n"
"}\n"
"QMenuBar::item:!enabled {\n"
"        color: rgb(155, 155, 155);\n"
"}\n"
"QMenuBar::item:enabled:selected {\n"
"        border-top-color: rgb(111, 156, 207);\n"
"        border-bottom-color: rgb(111, 156, 207);\n"
"        background: rgb(198, 224, 252);\n"
"}\n"
"QMenu {\n"
"        border: 1px solid rgb(111, 156, 207);\n"
"        background: rgb(232, 241, 250);\n"
"}\n"
"QMenu::item {\n"
"        height: 22px;\n"
"        padding: 0px 25px 0px 20px;\n"
"}\n"
"QMenu::item:enabled {\n"
"        col"
                        "or: rgb(84, 84, 84);\n"
"}\n"
"QMenu::item:!enabled {\n"
"        color: rgb(155, 155, 155);\n"
"}\n"
"QMenu::item:enabled:selected {\n"
"        color: rgb(2, 65, 132);\n"
"        background: rgba(255, 255, 255, 200);\n"
"}\n"
"QMenu::separator {\n"
"        height: 1px;\n"
"        background: rgb(111, 156, 207);\n"
"}\n"
"QMenu::indicator {\n"
"        width: 13px;\n"
"        height: 13px;\n"
"}\n"
"QProgressBar{\n"
"        border: none;\n"
"        text-align: center;\n"
"        color: white;\n"
"        background: rgb(173, 202, 232);\n"
"}\n"
"QProgressBar::chunk {\n"
"        background: rgb(16, 135, 209);\n"
"}\n"
"\n"
"QProgressBar#progressBar {\n"
"        border: none;\n"
"        text-align: center;\n"
"        color: white;\n"
"        background-repeat: repeat-x;\n"
"}\n"
"QProgressBar#progressBar::chunk {\n"
"        border: none;\n"
"        background-repeat: repeat-x;\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,0%);\n"
"    margin:0px,0px,0px,0px;\n"
""
                        "    padding-top:9px;\n"
"    padding-bottom:9px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,25%);\n"
"    border-radius:4px; \n"
"    min-height:20;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,50%);  \n"
"    border-radius:4px;\n"
"    min-height:20;\n"
"}\n"
"/*\346\214\211\351\222\256*/\n"
"QPushButton{\n"
"        border-radius: 4px;\n"
"        border: none;\n"
"        width: 75px;\n"
"        height: 25px;\n"
"}\n"
"QPushButton:enabled {\n"
"        background: rgb(120, 170, 220);\n"
"        color: white;\n"
"}\n"
"QPushButton:!enabled {\n"
"        background: rgb(180, 180, 180);\n"
"        color: white;\n"
"}\n"
"QPushButton:enabled:hover{\n"
"        background: rgb(100, 160, 220);\n"
"}\n"
"QPushButton:enabled:pressed{\n"
"        background: rgb(0, 78, 161);\n"
"}\n"
"\n"
"QPushButton#blueButton {\n"
"        color: white;\n"
"}\n"
"QPushButton#blueButton:enabled {\n"
"        background: rgb(0"
                        ", 78, 161);\n"
"        color: white;\n"
"}\n"
"QPushButton:!enabled {\n"
"        background: rgb(180, 180, 180);\n"
"        color: white;\n"
"}"));
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QString::fromUtf8("action2"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        horizontalLayout->addWidget(progressBar);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 30));
        menuopen = new QMenu(menuBar);
        menuopen->setObjectName(QString::fromUtf8("menuopen"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuopen->menuAction());
        menuBar->addAction(menu->menuAction());
        menuopen->addAction(actionopen);
        menuopen->addAction(actionclose);
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(action1);
        menu_2->addAction(action2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionclose->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        action2->setText(QApplication::translate("MainWindow", "\346\226\271\345\274\2172", nullptr));
        action1->setText(QApplication::translate("MainWindow", "\346\226\271\345\274\2171", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\350\257\206\345\210\253\347\202\271\346\225\260", nullptr));
        menuopen->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\216\222\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
