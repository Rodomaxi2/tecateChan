#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    int pinA, pinB, EN;
    
    Motor(int _EN, int _pinA, int _pinB);
    void adelante();
    void atras();
    void parar();
};

#endif