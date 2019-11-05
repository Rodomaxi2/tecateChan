#ifndef Lineas_h
#define Lineas_h

#include "Arduino.h"

class Lineas
{
  public:
    int pin, analogico, valor;
    
    Lineas(int _pin , int _analogico);
    Lineas(int _pin);
    bool detectar();
    bool detectarAn();
};


#endif
