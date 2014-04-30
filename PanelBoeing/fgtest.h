#ifndef FGTEST_H
#define FGTEST_H
#include "../../Qtraspberrylib/mcp23017.h"
#include "../../Qtraspberrylib/rotaryencoder.h"

class Fgtest : public Mcp23017
{
    Q_OBJECT

private:
    RotaryEncoder* p_encoder1;
    RotaryEncoder* p_encoder2;
    RotaryEncoder* p_encoder3;
    RotaryEncoder* p_encoder4;

    int m_ledA7;
public:
    explicit Fgtest(QObject *parent = 0);
    int ISR();
    int ISR2();
    void set_enc1(RotaryEncoder* pt);
    void set_enc2(RotaryEncoder* pt);
    void set_enc3(RotaryEncoder* pt);
    void set_enc4(RotaryEncoder* pt);
    void config(quint8 _addr);

signals:
    void button1_pressed();

public slots:

    
};

#endif // FGTEST_H
