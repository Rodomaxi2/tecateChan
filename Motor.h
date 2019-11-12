#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    int pinA, pinB, EN; //se declaran las variables basicas
    

    Motor(int _EN = 0, int _pinA = 0, int _pinB = 0) //Constructor que asigna los pines, 0 por defecto
     {
        pinA = _pinA;
        pinB = _pinB;
        EN = _EN;

        //Se configuran los pines como salidas
        pinMode(EN, OUTPUT);
  		pinMode(pinA, OUTPUT);
  		pinMode(pinB, OUTPUT);
     } 

    Motor* asignar(Motor *from)
	{
		Motor *rtn = new Motor(from ->EN, from-> pinA, from->pinB);
		return rtn;
	}

	void adelante() //avanza por tiempo indefinido
	{
		//parar(100);
		//Direccion de motor
		digitalWrite(pinA, HIGH);
		digitalWrite(pinB, LOW);
		analogWrite(EN,255); //velocidad de motor
	}

	void atras() //da marcha atras por tiempo indefinido
	{
		//parar(100);
		//Direccion de motor
		digitalWrite(pinA, LOW);
		digitalWrite(pinB, HIGH);
		analogWrite(EN,128); //velocidad de motor
	}

	void parar() //Detiene el motor por tiempo indefinido
	{
		//Direccion de motor
		digitalWrite(pinA, LOW);
		digitalWrite(pinB, LOW);
		analogWrite(EN, 0); //Velocidad de motor
	}

	void parar(int tiempo) //Funcion parar que recibe un valor que recibe el tiempo que detiene los motores y despues hace un delay por el tiempo indicado
	{
		//Direccion de motor
		digitalWrite(pinA, LOW);
		digitalWrite(pinB, LOW);
		analogWrite(EN, 0); //Velocidad de motor
		delay(tiempo);
	}


	
};

#endif
