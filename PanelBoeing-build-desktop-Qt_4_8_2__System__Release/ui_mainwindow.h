/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 30 19:00:11 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Connect;
    QLineEdit *lineEdit_port;
    QLineEdit *lineEdit_IP;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_com;
    QPushButton *pushButtonCommand;
    QDial *dialBrightness;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 552);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_Connect = new QPushButton(centralWidget);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));
        pushButton_Connect->setGeometry(QRect(270, 30, 108, 31));
        lineEdit_port = new QLineEdit(centralWidget);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(170, 30, 81, 30));
        lineEdit_IP = new QLineEdit(centralWidget);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(30, 30, 113, 30));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 91, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 10, 78, 20));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 70, 351, 75));
        lineEdit_com = new QLineEdit(centralWidget);
        lineEdit_com->setObjectName(QString::fromUtf8("lineEdit_com"));
        lineEdit_com->setGeometry(QRect(30, 150, 161, 30));
        pushButtonCommand = new QPushButton(centralWidget);
        pushButtonCommand->setObjectName(QString::fromUtf8("pushButtonCommand"));
        pushButtonCommand->setGeometry(QRect(210, 150, 141, 31));
        dialBrightness = new QDial(centralWidget);
        dialBrightness->setObjectName(QString::fromUtf8("dialBrightness"));
        dialBrightness->setGeometry(QRect(40, 190, 81, 61));
        dialBrightness->setMaximum(16);
        dialBrightness->setPageStep(16);
        dialBrightness->setSliderPosition(5);
        dialBrightness->setInvertedAppearance(false);
        dialBrightness->setNotchesVisible(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 210, 101, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_IP, lineEdit_port);
        QWidget::setTabOrder(lineEdit_port, pushButton_Connect);
        QWidget::setTabOrder(pushButton_Connect, textEdit);
        QWidget::setTabOrder(textEdit, lineEdit_com);
        QWidget::setTabOrder(lineEdit_com, pushButtonCommand);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "IP address", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        pushButtonCommand->setText(QApplication::translate("MainWindow", "Telnet Comm", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Brightness", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
