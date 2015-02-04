#ifndef B777_H
#define B777_H

#include <QObject>
#include "panel.h"

class B777 : public Panel
{
    Q_OBJECT
public:
    explicit B777(QObject *parent = 0);
    
    void button1(quint8 direction);
    void button2(quint8 direction);
    void button3(quint8 direction);
    void button4(quint8 direction);
    void button5(quint8 direction);
    void button6(quint8 direction);
    void button7(quint8 direction);
    void button8(quint8 direction);

    void button9(quint8 direction);
    void button10(quint8 direction);

    void button11(quint8 direction);
    void button12(quint8 direction);
    void button13(quint8 direction);
    void button14(quint8 direction);

    void encoder1(quint8 direction);
    void encoder2(quint8 direction);
    void encoder3(quint8 direction);
    void encoder4(quint8 direction);
    void encoder5(quint8 direction);
    void encoder6(quint8 direction);


signals:
    
public slots:

private:
    uint speed;
    uint heading;
    int vs;
    int altitude;

    static const quint16 range[];
    uint range_index;
    
    QString mode[4];
    uint mode_index;

    qint8 lvor;
    qint8 rvor;

};

#endif // B777_H
