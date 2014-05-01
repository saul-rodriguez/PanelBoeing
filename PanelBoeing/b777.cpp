#include "b777.h"

B777::B777(QObject *parent) :
    Panel(parent)
{
    speed = 200;
    heading = 360;
    vs = 0;
    altitude = 10000;
}

void B777::button1(quint8 direction)
{
    //AUTOPILOT ON/OFF

    qDebug("B777 Button1 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/AP 1";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/AP 0";
    }
    comm->sendData(command);
}

void B777::button2(quint8 direction)
{
    //AUTOTHROTTLE ON/OFF

    qDebug("B777 Button2 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/autothrottle-index 5";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/autothrottle-index  0";
    }
    comm->sendData(command);
}

void B777::button3(quint8 direction)
{
    //HEADING HOLD

    qDebug("B777 Button3 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/lateral-index 1";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/lateral-index  0";
    }
    comm->sendData(command);

}

void B777::button4(quint8 direction)
{
    //VS/FPA

    qDebug("B777 Button4 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/vertical-index 2";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/vertical-index 0";
    }
    comm->sendData(command);

}

void B777::button5(quint8 direction)
{
    //ALTITUDE HOLD

    qDebug("B777 Button5 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/vertical-index 1";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/vertical-index 0";
    }
    comm->sendData(command);

}

void B777::button6(quint8 direction)
{
    //APP

    qDebug("B777 Button6 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/gs-armed 1";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/gs-armed 0";
    }
    comm->sendData(command);
}

void B777::button7(quint8 direction)
{
    //LOC

    qDebug("B777 Button7 called");

    qDebug("B777 Button6 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/loc-armed 1";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/loc-armed 0";
    }
    comm->sendData(command);
}

void B777::button8(quint8 direction)
{
    qDebug("B777 Button8 called");
}

void B777::encoder1(quint8 direction)
{
    // SPEED
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
    // HEADING

    qDebug("B777 encoder2 called");

    if (direction == 1) { //UP
        if (heading >= 360) {
            heading = 1;
        } else {
            heading++;
        }

    } else { //DOWN
        if (heading <= 1) {
            heading = 360;
        } else {
            heading--;
        }
    }

    //Update display1
    disp2.writeint(heading);


    //Send telnet command to FGFS
    QVariant aux(heading);
    QString command = "set /autopilot/settings/heading-bug-deg ";
    command += aux.toString();

    comm->sendData(command);

}

void B777::encoder3(quint8 direction)
{
     qDebug("B777 encoder3 called");
}

void B777::encoder4(quint8 direction)
{
     qDebug("B777 encoder4 called");
}
