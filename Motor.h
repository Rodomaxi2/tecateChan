#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    int pinA, pinB, EN; //se declaran las variables basicas
    
    Motor(int _EN, int _pinA, int _pinB);
    Motor();
    void adelante();
    void atras();
    void parar();
    void parar(int);
};

#endif
