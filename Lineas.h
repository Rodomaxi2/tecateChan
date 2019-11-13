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


	//esta funcion necesita pruebas
	/*
	bool detectar()
	{
	    valor = analogRead(analogico); //esta funcion detecta brillo y  regresara false
	    if(valor < 800)
	    {
	        return true;
	    }
	    else
	    {
	        return false;
	    }
	}
	*/


	//Esta funcion trabaja correctamente
	bool detectarS()
	{
	    valor = analogRead(analogico); //si esta funcion detecta oscuridad regresara true
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
