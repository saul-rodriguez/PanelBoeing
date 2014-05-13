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
    
};

#endif // B777_H
