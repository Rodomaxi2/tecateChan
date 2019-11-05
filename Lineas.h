#ifndef Lineas_h
#define Lineas_h

#include "Arduino.h"

class Lineas
{
  public:
    int pin;
    
    Lineas(int _pin);
    bool detectar();
};


#endif
