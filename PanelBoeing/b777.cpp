#include "b777.h"

const quint16 B777::range[] = {
    10,
    20,
    40,
    80,
    160,
    320,
    640,
};



B777::B777(QObject *parent) :
    Panel(parent)
{
    speed = 200;
    heading = 360;
    vs = 0;
    altitude = 10000;

    range_index = 0;

    mode_index = 0;
    mode[0] = "APP";
    mode[1] = "VOR";
    mode[2] = "MAP";
    mode[3] = "PLN";

    lvor = 0;
    rvor = 0;
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
        command = "set /instrumentation/afds/inputs/lateral-index 0";
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
    //FLCH

    qDebug("B777 Button8 called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/vertical-index 8";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/vertical-index 0";
    }
    comm->sendData(command);

}

void B777::button9(quint8 direction)
{
    qDebug("B777 Button9, AT R called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/at-armed[1] true";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/at-armed[1] false";
    }
    comm->sendData(command);

}

void B777::button10(quint8 direction)
{
    qDebug("B777 Button10, AT L called");

    QString command;

    if (direction) { //turn on
        command = "set /instrumentation/afds/inputs/at-armed true";
    } else { //turn off
        command = "set /instrumentation/afds/inputs/at-armed false";
    }
    comm->sendData(command);

}

void B777::button11(quint8 direction)
{
    qDebug("B777 Button11, VOR R up called");

    if (rvor >= 1) return;

    rvor++;

    QVariant aux;
    aux = rvor;

    QString command;

    command = "set /instrumentation/efis/inputs/rh-vor-adf ";
    command += aux.toString();

    comm->sendData(command);
}

void B777::button12(quint8 direction)
{
    qDebug("B777 Button11, VOR R down called");

    if (rvor <= -1) return;

    rvor--;

    QVariant aux;
    aux = rvor;

    QString command;

    command = "set /instrumentation/efis/inputs/rh-vor-adf ";
    command += aux.toString();

    comm->sendData(command);
}

void B777::button13(quint8 direction)
{
    qDebug("B777 Button13, VOR L up called");

    if (lvor >= 1) return;

    lvor++;

    QVariant aux;
    aux = lvor;

    QString command;

    command = "set /instrumentation/efis/inputs/lh-vor-adf ";
    command += aux.toString();

    comm->sendData(command);
}

void B777::button14(quint8 direction)
{
    qDebug("B777 Button14, VOR L down called");

    if (lvor <= -1) return;

    lvor--;

    QVariant aux;
    aux = lvor;

    QString command;

    command = "set /instrumentation/efis/inputs/lh-vor-adf ";
    command += aux.toString();

    comm->sendData(command);
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
    disp1.writeint_zeropad(speed,3);

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

    //Update display2
    disp2.writeint_zeropad(heading,3);


    //Send telnet command to FGFS
    QVariant aux(heading);
    QString command = "set /autopilot/settings/heading-bug-deg ";
    command += aux.toString();

    comm->sendData(command);

}

void B777::encoder3(quint8 direction)
{
    //VERTICAL SPEED

     qDebug("B777 encoder3 called");

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

void B777::encoder4(quint8 direction)
{
    //ALTITUDE

     qDebug("B777 encoder4 called");

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
     QString command = "set /autopilot/settings/counter-set-altitude-ft ";
     command += aux.toString();

     comm->sendData(command);


}

void B777::encoder5(quint8 direction)
{
    //Mode
    qDebug("B777 encoder5 called");

    if (direction) { //UP
        if (mode_index < 3) {
            mode_index++;
        } else {
            mode_index = 0;
        }
    } else { //DOWN
        if (mode_index > 0) {
            mode_index--;
        } else {
            mode_index = 3;
        }
    }

    QVariant aux(mode[mode_index]);
    QString command = "set /instrumentation/efis/mfd/display-mode ";
    command += aux.toString();

    comm->sendData(command);

    QVariant aux2(mode_index);
    command = "set /instrumentation/efis/mfd/mode-num ";
    command += aux2.toString();

    comm->sendData(command);

}

void B777::encoder6(quint8 direction)
{
    //Range
    qDebug("B777 encoder6 called");

    if (direction) { //UP
        if (range_index < 6) {
            range_index++;
        } else {
            range_index = 0;
        }

    } else { //DOWN
        if (range_index > 0) {
            range_index--;
        } else {
            range_index = 6;
        }
    }

    //Send telnet command to FGFS
    QVariant aux(range[range_index]);
    QString command = "set /instrumentation/efis/inputs/range-nm ";
    command += aux.toString();

    comm->sendData(command);

}


