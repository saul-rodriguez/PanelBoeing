#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_IP->setText("192.168.0.10");
    ui->lineEdit_port->setText("5401");

    fgpanel = &panel_777;

    connect(fgpanel,SIGNAL(telMes(QString)),this,SLOT(telnetMes(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Connect_clicked()
{
        QString IP = ui->lineEdit_IP->text();
        qDebug(IP.toAscii());
        QString s_port = ui->lineEdit_port->text();

        int port = s_port.toInt();
        qDebug("port = %d",port);

        fgpanel->comm->connectToHost(IP,port);
        fgpanel->comm->sendData("ls");
        fgpanel->comm->sendData("data");
        //t->sendData("data");
        //t->sendData("data");
}

void MainWindow::telnetMes(QString msg) {
    ui->textEdit->setText(msg);
}

void MainWindow::on_pushButtonCommand_clicked()
{
    QString command;

    command = ui->lineEdit_com->text();
//    qDebug(command);

    fgpanel->comm->sendData(command);

}

void MainWindow::on_dialBrightness_valueChanged(int value)
{
    fgpanel->setDispBrightness(value);
}
