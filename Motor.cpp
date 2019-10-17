#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int _EN, int _pinA, int _pinB)
     {
        pinA = _pinA;
        pinB = _pinB;
        EN = _EN;
     }

void Motor::adelante()
{
	//Direccion de motor A
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	analogWrite(EN,255); //velocidad de motor A
}

void Motor::atras()
{
	//Direccion de motor A
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	analogWrite(EN,128); //velocidad de motor A
}

void Motor::parar()
{
	//Direccion de motor A
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	analogWrite(EN, 0); //Velocidad de motor A
}