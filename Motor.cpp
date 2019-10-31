#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int _EN, int _pinA, int _pinB)
     {
        pinA = _pinA;
        pinB = _pinB;
        EN = _EN;

        //Se configuran los pines como salidas
        pinMode(EN, OUTPUT);
  		pinMode(pinA, OUTPUT);
  		pinMode(pinB, OUTPUT);
     }

void Motor::adelante()
{
	//parar(100);
	//Direccion de motor
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	analogWrite(EN,255); //velocidad de motor
}

void Motor::atras()
{
	//parar(100);
	//Direccion de motor
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	analogWrite(EN,128); //velocidad de motor
}

void Motor::parar()
{
	//Direccion de motor
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	analogWrite(EN, 0); //Velocidad de motor
}

void Motor::parar(int tiempo)
{
	//Direccion de motor
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	analogWrite(EN, 0); //Velocidad de motor
	delay(tiempo);
}
