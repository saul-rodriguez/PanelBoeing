#include "b777.h"

B777::B777(QObject *parent) :
    Panel(parent)
{
    speed = 0;
    heading = 0;
    vs = 0;
    altitude = 0;
}

void B777::button1(quint8 direction)
{
    qDebug("B777 Button1 called");
}

void B777::button2(quint8 direction)
{
    qDebug("B777 Button2 called");
}

void B777::button3(quint8 direction)
{
    qDebug("B777 Button3 called");
}

void B777::button4(quint8 direction)
{
    qDebug("B777 Button4 called");
}

void B777::button5(quint8 direction)
{
    qDebug("B777 Button5 called");
}

void B777::button6(quint8 direction)
{
    qDebug("B777 Button6 called");
}

void B777::button7(quint8 direction)
{
    qDebug("B777 Button7 called");
}

void B777::button8(quint8 direction)
{
    qDebug("B777 Button8 called");
}

void B777::encoder1(quint8 direction)
{
    qDebug("B777 encoder1 called");

    if (direction == 1) { //UP
        speed++;

    } else { //DOWN
        if (speed > 0)
            speed--;
    }

    //Update display1
    disp1.writeint(speed);

    //Send telnet command to FGFS
    QVariant aux(speed);
    QString command = "set /autopilot/settings/target-speed-kt ";
    command += aux.toString();

    comm->sendData(command);



}

void B777::encoder2(quint8 direction)
{
     qDebug("B777 encoder2 called");
}

void B777::encoder3(quint8 direction)
{
     qDebug("B777 encoder3 called");
}

void B777::encoder4(quint8 direction)
{
     qDebug("B777 encoder4 called");
}
