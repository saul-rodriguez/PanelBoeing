#include "panel.h"
#include "hardware_conf.h"

#include <wiringPi.h>
#include <qmessagebox.h>

#include "../../Qtraspberrylib/mcp23017_isr.h"

Panel::Panel(QObject *parent) :
    QObject(parent)
{
}

void Panel::export_pins()
{
    //pin (0)17 (ISR)
    system("gpio mode 0 in");
    system("gpio mode 0 up");
    system("gpio edge 0 falling");
    system("gpio export 17 in");

    //pin (1)18 (ISR)
    system("gpio mode 1 in");
    system("gpio mode 1 up");
    system("gpio edge 1 falling");
    system("gpio export 18 in");

    //pin (4)23 (ISR)
    system("gpio mode 4 in");
    system("gpio mode 4 up");
    system("gpio edge 4 falling");
    system("gpio export 23 in");

    //pin (5)24 (ISR)
    system("gpio mode 5 in");
    system("gpio mode 5 up");
    system("gpio edge 5 falling");
    system("gpio export 24 in");

    //pin (5)24 (ISR)
    system("gpio mode 5 in");
    system("gpio mode 5 up");
    system("gpio edge 5 falling");
    system("gpio export 24 in");

}

void Panel::setup_hardware()
{
    export_pins();


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

    //Setup extender 1
    int ret;
    ret = ext1.open(EXT1);
    ret = ext1.setTris(PORTA,TRISA1);
    ret = ext1.setTris(PORTB,TRISB1);
    ret = ext1.setPullup(PORTA,A_PULLUP1);
    ret = ext1.setPullup(PORTB,B_PULLUP1);

    setupMcp23017_isr_ext1(&ext1);
    connect(&ext1,SIGNAL(interrupt_A(quint8)),this,SLOT(ext1_intA(quint8)));
    connect(&ext1,SIGNAL(interrupt_B(quint8)),this,SLOT(ext1_intB(quint8)));

    //Setup extender 2
    ret = ext2.open(EXT2);
    ret = ext2.setTris(PORTA,TRISA2);
    ret = ext2.setTris(PORTB,TRISB2);
    ret = ext2.setPullup(PORTA,A_PULLUP2);
    ret = ext2.setPullup(PORTB,B_PULLUP2);

    setupMcp23017_isr_ext2(&ext2);
    connect(&ext2,SIGNAL(interrupt_B(quint8)),this,SLOT(ext2_intB(quint8)));

    //Setup extender 3
    ret = ext3.open(EXT3);
    ret = ext3.setTris(PORTA,TRISA3);
    ret = ext3.setTris(PORTB,TRISB3);
    ret = ext3.setPullup(PORTA,A_PULLUP3);
    ret = ext3.setPullup(PORTB,B_PULLUP3);

    setupMcp23017_isr_ext3(&ext3);
    connect(&ext3,SIGNAL(interrupt_B(quint8)),this,SLOT(ext3_intB(quint8)));

    //Setup encoders
    connect(&enc1,SIGNAL(encoder_changed(quint8)),this,SLOT(enc1_changed(quint8)));
    connect(&enc2,SIGNAL(encoder_changed(quint8)),this,SLOT(enc2_changed(quint8)));
    connect(&enc3,SIGNAL(encoder_changed(quint8)),this,SLOT(enc3_changed(quint8)));
    connect(&enc4,SIGNAL(encoder_changed(quint8)),this,SLOT(enc4_changed(quint8)));
    connect(&enc5,SIGNAL(encoder_changed(quint8)),this,SLOT(enc5_changed(quint8)));
    connect(&enc6,SIGNAL(encoder_changed(quint8)),this,SLOT(enc6_changed(quint8)));


    //Setup buttons & switches
    connect(&but1,SIGNAL(button_changed(quint8)),this,SLOT(but1_changed(quint8)));
    connect(&but2,SIGNAL(button_changed(quint8)),this,SLOT(but2_changed(quint8)));
    connect(&but3,SIGNAL(button_changed(quint8)),this,SLOT(but3_changed(quint8)));
    connect(&but4,SIGNAL(button_changed(quint8)),this,SLOT(but4_changed(quint8)));
    connect(&but5,SIGNAL(button_changed(quint8)),this,SLOT(but5_changed(quint8)));
    connect(&but6,SIGNAL(button_changed(quint8)),this,SLOT(but6_changed(quint8)));
    connect(&but7,SIGNAL(button_changed(quint8)),this,SLOT(but7_changed(quint8)));
    connect(&but8,SIGNAL(button_changed(quint8)),this,SLOT(but8_changed(quint8)));
    connect(&but9,SIGNAL(button_changed(quint8)),this,SLOT(but9_changed(quint8)));
    connect(&but10,SIGNAL(button_changed(quint8)),this,SLOT(but10_changed(quint8)));
    connect(&but11,SIGNAL(button_changed(quint8)),this,SLOT(but11_changed(quint8)));
    connect(&but12,SIGNAL(button_changed(quint8)),this,SLOT(but12_changed(quint8)));
    connect(&but13,SIGNAL(button_changed(quint8)),this,SLOT(but13_changed(quint8)));
    connect(&but14,SIGNAL(button_changed(quint8)),this,SLOT(but14_changed(quint8)));

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

//Ext2 PORTA interrupt slot
void Panel::ext2_intA(quint8 value)
{
    qDebug("EXT2 PORTA ISR called");
}

//Ext2 PORTB interrupt slot
void Panel::ext2_intB(quint8 value)
{
    qDebug("EXT2 PORTB ISR called");

    //Compare new state of portB with latest state:
    quint8 aux,enc,newstate;
    aux = ext2.portb ^ value; //Find pin that produced interruption
    //qDebug("aux = %x",aux);
    ext2.portb= value;

    enc = aux & ENCODER5;
    if (enc) {
        newstate = (value & ENCODER5) >> 0;
        qDebug("newstate = %x",newstate);
        enc5.change_state(newstate);
    }

    enc = aux & ENCODER6;
    if (enc) {
        newstate = (value & ENCODER6) >> 2;
        qDebug("newstate = %x",newstate);
        enc6.change_state(newstate);
    }

    switch (aux) {
        case(BUT11):
            newstate = (value & BUT11)>>4; //bit 4
            but11.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;
        case(BUT12):
            newstate = (value & BUT12)>>5; //bit 5
            but12.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;
        case(BUT13):
            newstate = (value & BUT13)>>6; //bit 6
            but13.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;
        case(BUT14):
            newstate = (value & BUT14)>>7; //bit 7
            but14.change_state(newstate);
            qDebug("newstate = %x",newstate);
            break;
        default: break;
    }
}

void Panel::ext3_intB(quint8 value)
{
    qDebug("Int in port B, value: %x", value);
    //Compare new state of portB with latest state:
    quint8 aux,enc,newstate;
    aux = ext3.portb ^ value; //Find pin that produced interruption
    qDebug("aux = %x",aux);
    ext3.portb = value;

    switch (aux) {
        case(BUT9):
            newstate = (value & BUT9)>>7; //bit 7
            but9.on_off(newstate);
            qDebug("newstate = %x",newstate);
            break;
        case(BUT10):
            newstate = (value & BUT10)>>6; //bit 6
            but10.on_off(newstate);
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

void Panel::enc5_changed(quint8 direction)
{
    qDebug("Direction enc5 = %d",direction);
    encoder5(direction);
}

void Panel::enc6_changed(quint8 direction)
{
    qDebug("Direction enc6 = %d",direction);
    encoder6(direction);
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

void Panel::but9_changed(quint8 direction)
{
    qDebug("Button 9 pressed");
    if (direction) {
        LED_BUT9_ON;
    } else {
        LED_BUT9_OFF;
    }
    button9(direction);
}

void Panel::but10_changed(quint8 direction)
{
    qDebug("Button 10 pressed");
    if (direction) {
        LED_BUT10_ON;
    } else {
        LED_BUT10_OFF;
    }
    button10(direction);
}

void Panel::but11_changed(quint8 direction)
{
    qDebug("Button 11 pressed");
    if (direction) {
        //LED_BUT10_ON;
    } else {
        //LED_BUT10_OFF;
    }
    button11(direction);
}

void Panel::but12_changed(quint8 direction)
{
    qDebug("Button 12 pressed");
    if (direction) {
        //LED_BUT10_ON;
    } else {
        //LED_BUT10_OFF;
    }
    button12(direction);
}

void Panel::but13_changed(quint8 direction)
{
    qDebug("Button 13 pressed");
    if (direction) {
        //LED_BUT10_ON;
    } else {
        //LED_BUT10_OFF;
    }
    button13(direction);
}

void Panel::but14_changed(quint8 direction)
{
    qDebug("Button 14 pressed");
    if (direction) {
        //LED_BUT10_ON;
    } else {
        //LED_BUT10_OFF;
    }
    button14(direction);
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

void Panel::encoder5(quint8 direction)
{
}

void Panel::encoder6(quint8 direction)
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

void Panel::button9(quint8 direction)
{
}

void Panel::button10(quint8 direction)
{
}

void Panel::button11(quint8 direction)
{
}

void Panel::button12(quint8 direction)
{
}

void Panel::button13(quint8 direction)
{
}

void Panel::button14(quint8 direction)
{
}
