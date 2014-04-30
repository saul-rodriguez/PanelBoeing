#include "fgtest.h"
#include <wiringPiI2C.h>

#include "hardware_conf.h"

Fgtest::Fgtest(QObject *parent) :
    Mcp23017(parent)
{
    m_ledA7 = 0;
}

int Fgtest::ISR()
{
    int ret,enc,aux;

    ret = wiringPiI2CReadReg8(fd, MCP23017_INTCAPA);
    //qDebug("Derived intcapa value = %X",ret);

    //Find the origin of the interrupt:

    // encoder1?
     enc = ret & 0b00000011;
     aux = enc ^ (porta & 0b00000011);

     if (aux) { //Encoder1 changed, send signal
         //qDebug("Derived xor value = %X, state = %d",aux, enc1);
         //test_trigger();
         //update_enc1(enc1);
         p_encoder1->changestate(enc);
     }

    // encoder2?
     enc = ret & 0b00001100;
     aux = enc ^ (porta & 0b00001100);


     if (aux) { //Encoder1 changed, send signal
         //qDebug("Derived xor value = %X, state = %d",aux, enc1);
         //test_trigger();
         //update_enc1(enc1);
         enc >>= 2;
         p_encoder2->changestate(enc);
     }

     // encoder3?
      enc = ret & 0b00110000;
      aux = enc ^ (porta & 0b00110000);


      if (aux) { //Encoder1 changed, send signal
          //qDebug("Derived xor value = %X, state = %d",aux, enc1);
          //test_trigger();
          //update_enc1(enc1);
          enc >>= 4;
          p_encoder3->changestate(enc);
      }

      // encoder4?
       enc = ret & 0b11000000;
       aux = enc ^ (porta & 0b11000000);


       if (aux) { //Encoder1 changed, send signal
           //qDebug("Derived xor value = %X, state = %d",aux, enc1);
           //test_trigger();
           //update_enc1(enc1);
           enc >>= 6;
           p_encoder4->changestate(enc);
       }


     porta = ret;

     return ret;
}

int Fgtest::ISR2()
{
    int ret,but,aux;

    ret = wiringPiI2CReadReg8(fd, MCP23017_INTCAPB);
    //qDebug("Derived intcapb value = %X",ret);

    //button 1?
    but = ret & BUT1_B;
    aux = but ^ (portb & BUT1_B);

    if (aux) {
        if (but == 0) { //Capture the Falling Edge
            qDebug("button1 pressed");
            emit button1_pressed();
        }
    }

    portb = ret;

    return ret;
}

void Fgtest::set_enc1(RotaryEncoder* pt)
{
    p_encoder1 = pt;
}

void Fgtest::set_enc2(RotaryEncoder* pt)
{
    p_encoder2 = pt;
}

void Fgtest::set_enc3(RotaryEncoder* pt)
{
    p_encoder3 = pt;
}

void Fgtest::set_enc4(RotaryEncoder* pt)
{
    p_encoder4 = pt;
}

void Fgtest::config(quint8 _addr)
{
    open(_addr);
    setTris(PORTB,TRISB);
    setTris(PORTA,TRISA);
    setPullup(PORTA,0xff);
    setPullup(PORTB,0xff);
}

