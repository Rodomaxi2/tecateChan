#include "Arduino.h"
#include "Ultrasonico.h"

Ultrasonico::Ultrasonico(int _trigger, int _echo)
{
	trigger = _trigger;
	echo = _echo;

	Serial.begin(9600);//inicia la comunicacion
  	pinMode(trigger, OUTPUT);//pin como salida
  	pinMode(echo, INPUT);//pin como entrada 
  	digitalWrite(trigger, LOW);//inicializamos el pin con 0
}

float Ultrasonico::distancia()
{
	int t;//timepo en que demora en llegar el eco
    int d;//distancia en cm
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10); //enviamos un pulso de 10 us
    digitalWrite(trigger, LOW);
    t = pulseIn(echo, HIGH);//obtenemos el anch del pulso
    d = t/59;//escalamo el tiempo a una distancia en cm
    Serial.print("Distancia");
    Serial.print(d);//enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
    delay(100);//hacemos una pausa de 10 ms
}