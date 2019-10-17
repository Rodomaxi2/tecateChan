#ifndef Lineas_h
#define Lineas_h

#include "Arduino.h"

class Lineas
{
  public:
    int pinA, pinB, EN;
    
    Motor(int _EN, int _pinA, int _pinB);
    void adelante();
    void atras();
    void parar();
};

#endif