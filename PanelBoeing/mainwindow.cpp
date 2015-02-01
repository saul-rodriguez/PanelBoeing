#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_IP->setText("192.168.0.13");
    ui->lineEdit_port->setText("5401");

    ui->pushButton_Connect->setEnabled(false);

    //fgpanel = &panel_777;
    //fgpanel = &panel_787;

    //connect(fgpanel,SIGNAL(telMes(QString)),this,SLOT(telnetMes(QString)));
    ui->comboBox->addItem("Boeing777");
    ui->comboBox->addItem("Boeing787");


    fgpanel = NULL;
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


void MainWindow::on_pushButtonSelectProfile_clicked()
{
    //fgpanel = &panel_777;
    QString profile = ui->comboBox->currentText();

    if (profile == "Boeing777") {
        qDebug("Boeing777 selected");
        panel_777 = new B777(this);
        fgpanel = panel_777;
    }

    if (profile == "Boeing787") {
        qDebug("Boeing787 selected");
        panel_787 = new B787(this);
        fgpanel = panel_787;
    }


    fgpanel->setup_hardware();

    connect(fgpanel,SIGNAL(telMes(QString)),this,SLOT(telnetMes(QString)));

    ui->pushButtonSelectProfile->setEnabled(false);
    ui->pushButton_Connect->setEnabled(true);
}
