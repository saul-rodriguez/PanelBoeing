#include "b787.h"

B787::B787(QObject *parent) :
    Panel(parent)
{
    speed = 200;
    heading = 360;
    vs = 0;
    altitude = 10000;
}


void B787::button1(quint8 direction)
{
    //AUTOPILOT ON/OFF

    qDebug("B787 Button1 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/master 1";
    } else { //turn off
        command = "set /autopilot/panel/master 0";
    }
    comm->sendData(command);
}

void B787::button2(quint8 direction)
{
    //AUTOTHROTTLE ON/OFF

    qDebug("B787 Button2 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/auto-throttle 1";
    } else { //turn off
        command = "set /autopilot/panel/auto-throttle 0";
    }
    comm->sendData(command);
}

void B787::button3(quint8 direction)
{
    //HEADING HOLD

    qDebug("B787 Button3 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/hdg hdg";
    } else { //turn off
        command = "set /autopilot/panel/hdg";
    }
    comm->sendData(command);

}

void B787::button4(quint8 direction)
{
    //VS/FPA

    qDebug("B787 Button4 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/alt vs";
    } else { //turn off
        command = "set /autopilot/panel/alt";
    }
    comm->sendData(command);

}

void B787::button5(quint8 direction)
{
    //ALTITUDE HOLD

    qDebug("B787 Button5 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/alt alt";
    } else { //turn off
        command = "set /autopilot/panel/alt";
    }
    comm->sendData(command);

}

void B787::button6(quint8 direction)
{
    //APP

    qDebug("B787 Button6 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/alt app";
    } else { //turn off
        command = "set /autopilot/panel/alt";
    }
    comm->sendData(command);
}

void B787::button7(quint8 direction)
{
    //LOC

    qDebug("B787 Button7 called");

    qDebug("B787 Button6 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/hdg loc";
    } else { //turn off
        command = "set /autopilot/panel/hdg";
    }
    comm->sendData(command);
}

void B787::button8(quint8 direction)
{
    // FLCH

    qDebug("B787 Button8 called");

    QString command;

    if (direction) { //turn on
        command = "set /autopilot/panel/alt alt";
    } else { //turn off
        command = "set /autopilot/panel/alt";
    }
    comm->sendData(command);
}

void B787::encoder1(quint8 direction)
{
    // SPEED
    qDebug("B787 encoder1 called");

    if (direction == 1) { //UP
        speed++;

    } else { //DOWN
        if (speed > 0)
            speed--;
    }

    //Update display1
    disp1.writeint_zeropad(speed,3);

    //Send telnet command to FGFS
    QVariant aux(speed);
    QString command = "set /autopilot/settings/target-speed-kt ";
    command += aux.toString();

    comm->sendData(command);

}

void B787::encoder2(quint8 direction)
{
    // HEADING

    qDebug("B787 encoder2 called");

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

    //Update display2
    disp2.writeint_zeropad(heading,3);


    //Send telnet command to FGFS
    QVariant aux(heading);
    QString command = "set /autopilot/settings/heading-bug-deg ";
    command += aux.toString();

    comm->sendData(command);

}

void B787::encoder3(quint8 direction)
{
    //VERTICAL SPEED

     qDebug("B787 encoder3 called");

     if (direction) {
         if (vs < 6000) {
            vs += 100;
         }
     } else {
         if (vs > -8000) {
            vs -= 100;
         }
     }

     //Update display3
     disp3.writeint_zeropad(vs,4);


     //Send telnet command to FGFS
     QVariant aux(vs);
     QString command = "set /autopilot/settings/vertical-speed-fpm ";
     command += aux.toString();

     comm->sendData(command);
}

void B787::encoder4(quint8 direction)
{
    //ALTITUDE

     qDebug("B787 encoder4 called");

     if (direction) { //UP
         altitude += 100;
     } else {   //DOWN
         if (altitude > 0) {
            altitude -= 100;
         }
     }

     disp4.writeint_zeropad(altitude,5);

     //Send telnet command to FGFS
     QVariant aux(altitude);
     QString command = "set /autopilot/settings/target-altitude-ft ";
     command += aux.toString();

     comm->sendData(command);


}


