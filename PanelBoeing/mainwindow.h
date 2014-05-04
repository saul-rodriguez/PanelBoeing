#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "panel.h"
#include "b777.h"
#include "b787.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_Connect_clicked();
    void telnetMes(QString msg);

    void on_pushButtonCommand_clicked();

    void on_dialBrightness_valueChanged(int value);

    void on_pushButtonSelectProfile_clicked();

private:
    Ui::MainWindow *ui;

    Panel *fgpanel;
    B777 *panel_777;
    B787 *panel_787;
};

#endif // MAINWINDOW_H
