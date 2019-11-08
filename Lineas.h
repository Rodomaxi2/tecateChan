#ifndef Lineas_h
#define Lineas_h

#include "Arduino.h"

class Lineas
{
  public:
    int analogico, valor;

	Lineas(int _analogico)
	{
	    analogico = _analogico;
	    pinMode(analogico, INPUT);
	}

	Lineas()
	{
	    analogico = 0;
	    pinMode(analogico, INPUT);
	}

	bool detectar()
	{
	    valor = analogRead(analogico); //esta funcion detecta brillo y  regresara true
	    if(valor < 800)
	    {
	        return false;
	    }
	    else
	    {
	        return true;
	    }
	} 

};


#endif
