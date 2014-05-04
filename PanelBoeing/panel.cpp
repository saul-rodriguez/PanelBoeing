#include "panel.h"
#include "hardware_conf.h"

#include <wiringPi.h>
#include <qmessagebox.h>

#include "../../Qtraspberrylib/mcp23017_isr.h"

Panel::Panel(QObject *parent) :
    QObject(parent)
{
}

void Panel::setup_hardware()
{
    wiringPiSetupSys();

    //Setup displays
    brightness = BRIGHTNESS;

    disp1.open(DISP1);
    disp1.setBlinkRate(0);
    disp1.setBrightness(brightness);
    disp1.writeint(1);

    disp2.open(DISP2);
    disp2.setBlinkRate(0);
    disp2.setBrightness(brightness);
    disp2.writeint(2);

    disp3.open(DISP3);
    disp3.setBlinkRate(0);
    disp3.setBrightness(brightness);
    disp3.writeint(3);

    disp4.open(DISP4);
    disp4.setBlinkRate(0);
    disp4.setBrightness(brightness);
    disp4.writeint(4);

    //Setup extender 1 and 2
    int ret;
    ret = ext1.open(EXT1);
    ret = ext1.setTris(PORTA,TRISA1);
    ret = ext1.setTris(PORTB,TRISB1);
    ret = ext1.setPullup(PORTA,A_PULLUP1);
    ret = ext1.setPullup(PORTB,B_PULLUP1);

    setupMcp23017_isr_ext1(&ext1);
    connect(&ext1,SIGNAL(interrupt_A(quint8)),this,SLOT(ext1_intA(quint8)));
    connect(&ext1,SIGNAL(interrupt_B(quint8)),this,SLOT(ext1_intB(quint8)));

    ret = ext2.open(EXT2);
    ret = ext2.setTris(PORTA,TRISA2);
    ret = ext2.setTris(PORTB,TRISB2);
    ret = ext2.setPullup(PORTA,A_PULLUP2);
    ret = ext2.setPullup(PORTB,B_PULLUP2);

    //Setup encoders
    connect(&enc1,SIGNAL(encoder_changed(quint8)),this,SLOT(enc1_changed(quint8)));
    connect(&enc2,SIGNAL(encoder_changed(quint8)),this,SLOT(enc2_changed(quint8)));
    connect(&enc3,SIGNAL(encoder_changed(quint8)),this,SLOT(enc3_changed(quint8)));
    connect(&enc4,SIGNAL(encoder_changed(quint8)),this,SLOT(enc4_changed(quint8)));

    //Setup buttons & switches
    connect(&but1,SIGNAL(button_changed(quint8)),this,SLOT(but1_changed(quint8)));
    connect(&but2,SIGNAL(button_changed(quint8)),this,SLOT(but2_changed(quint8)));
    connect(&but3,SIGNAL(button_changed(quint8)),this,SLOT(but3_changed(quint8)));
    connect(&but4,SIGNAL(button_changed(quint8)),this,SLOT(but4_changed(quint8)));
    connect(&but5,SIGNAL(button_changed(quint8)),this,SLOT(but5_changed(quint8)));
    connect(&but6,SIGNAL(button_changed(quint8)),this,SLOT(but6_changed(quint8)));
    connect(&but7,SIGNAL(button_changed(quint8)),this,SLOT(but7_changed(quint8)));
    connect(&but8,SIGNAL(button_changed(quint8)),this,SLOT(but8_changed(quint8)));

    //Setup telnet object
    comm = new QtTelnet;

    //comm->message(
    connect(comm, SIGNAL(message(QString)),this, SLOT(telnetMessage(QString)));
    connect(comm, SIGNAL(connectionError(QAbstractSocket::SocketError)),
            this, SLOT(telnetConnectionError(QAbstractSocket::SocketError)));
}

void Panel::setDispBrightness(quint8 br){
    disp1.setBrightness(br);
    disp2.setBrightness(br);
    disp3.setBrightness(br);
    disp4.setBrightness(br);
}

void Panel::telnetMessage(const QString &msg)
{
    qDebug("Message received");
    emit telMes(msg);
}

void Panel::telnetConnectionError(QAbstractSocket::SocketError)
{
    QMessageBox msg;
    msg.setText("Connection Error, Start FGFS with --telnet=5401");
    msg.exec();
}


//Ext1 PORTA interrupt slot
void Panel::ext1_intA(quint8 value)
{
    qDebug("Int in port A, value: %x", value);

    //Compare new state of portA with latest state:
    quint8 aux,enc,newstate;
    aux = ext1.porta ^ value; //Find pin that produced interruption
    //qDebug("aux = %x",aux);
    ext1.porta = value;

    enc = aux & ENCODER1;
    if (enc) {
        newstate = (value & ENCODER1) >> 0;
        qDebug("newstate = %x",newstate);
        enc1.change_state(newstate);
    }

    enc = aux & ENCODER2;
    if (enc) {
        newstate = (value & ENCODER2) >> 2;
        qDebug("newstate = %x",newstate);
        enc2.change_state(newstate);
    }

    enc = aux & ENCODER3;
    if (enc) {
        newstate = (value & ENCODER3) >> 4;
        qDebug("newstate = %x",newstate);
        enc3.change_state(newstate);
    }

    enc = aux & ENCODER4;
    if (enc) {
        newstate = (value & ENCODER4) >> 6;
        qDebug("newstate = %x",newstate);
        enc4.change_state(newstate);
    }

    //ext1.readPort(PORTA);
}

//Ext1 PORTB interrupt slot
void Panel::ext1_intB(quint8 value)
{
    qDebug("Int in port B, value: %x", value);
    //Compare new state of portB with latest state:
    quint8 aux,enc,newstate;
    aux = ext1.portb ^ value; //Find pin that produced interruption
    qDebug("aux = %x",aux);
    ext1.portb = value;

    switch (aux) {
        case(BUT1):
            newstate = (value & BUT1)>>0;
            but1.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT2):
            newstate = (value & BUT2)>>1;
            but2.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT3):
            newstate = (value & BUT3)>>2;
            but3.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT4):
            newstate = (value & BUT4)>>3;
            but4.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT5):
            newstate = (value & BUT5)>>4;
            but5.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT6):
            newstate = (value & BUT6)>>5;
            but6.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT7):
            newstate = (value & BUT7)>>6;
            but7.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        case(BUT8):
            newstate = (value & BUT8)>>7;
            but8.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;

        default: break;
    }

}

//Encoders slots
void Panel::enc1_changed(quint8 direction)
{
    qDebug("Direction enc1 = %d",direction);
    encoder1(direction);

}

void Panel::enc2_changed(quint8 direction)
{
    qDebug("Direction enc2 = %d",direction);
    encoder2(direction);
}

void Panel::enc3_changed(quint8 direction)
{
    qDebug("Direction enc3 = %d",direction);
    encoder3(direction);
}

void Panel::enc4_changed(quint8 direction)
{
    qDebug("Direction enc4 = %d",direction);
    encoder4(direction);
}

//Button slots:

void Panel::but1_changed(quint8 direction)
{
    qDebug("Button 1 pressed");
    if (direction) {
        LED_BUT1_ON;
    } else {
        LED_BUT1_OFF;
    }
    button1(direction);
}

void Panel::but2_changed(quint8 direction)
{
    qDebug("Button 2 pressed");
    if (direction) {
        LED_BUT2_ON;
    } else {
        LED_BUT2_OFF;
    }
    button2(direction);
}

void Panel::but3_changed(quint8 direction)
{
    qDebug("Button 3 pressed");
    if (direction) {
        LED_BUT3_ON;
    } else {
        LED_BUT3_OFF;
    }
    button3(direction);
}

void Panel::but4_changed(quint8 direction)
{
    qDebug("Button 4 pressed");
    if (direction) {
        LED_BUT4_ON;
    } else {
        LED_BUT4_OFF;
    }
    button4(direction);
}

void Panel::but5_changed(quint8 direction)
{
    qDebug("Button 5 pressed");
    if (direction) {
        LED_BUT5_ON;
    } else {
        LED_BUT5_OFF;
    }
    button5(direction);
}

void Panel::but6_changed(quint8 direction)
{
    qDebug("Button 6 pressed");
    if (direction) {
        LED_BUT6_ON;
    } else {
        LED_BUT6_OFF;
    }
    button6(direction);
}

void Panel::but7_changed(quint8 direction)
{
    qDebug("Button 7 pressed");
    if (direction) {
        LED_BUT7_ON;
    } else {
        LED_BUT7_OFF;
    }
    button7(direction);
}

void Panel::but8_changed(quint8 direction)
{
    qDebug("Button 8 pressed");
    if (direction) {
        LED_BUT8_ON;
    } else {
        LED_BUT8_OFF;
    }
    button8(direction);
}

/*********************
 * Virtual functions *
 *********************/
void Panel::encoder1(quint8 direction)
{
}

void Panel::encoder2(quint8 direction)
{
}

void Panel::encoder3(quint8 direction)
{
}

void Panel::encoder4(quint8 direction)
{
}

void Panel::button1(quint8 direction)
{
}

void Panel::button2(quint8 direction)
{
}

void Panel::button3(quint8 direction)
{
}

void Panel::button4(quint8 direction)
{
}

void Panel::button5(quint8 direction)
{
}

void Panel::button6(quint8 direction)
{
}

void Panel::button7(quint8 direction)
{
}

void Panel::button8(quint8 direction)
{
}
