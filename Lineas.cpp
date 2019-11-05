#include "Arduino.h"
#include "Lineas.h"

Lineas::Lineas(int _pin)
     {
        pin = _pin;
        pinMode(pin, INPUT);
     }

bool Lineas::detectar()
{

	int value = 0;
  value = digitalRead(pin);
  if(value == LOW)
  {
    return true;
  }

  else
  {
    return false;
  }
}     
