#ifndef Ultrasonico_h
#define Ultrasonico_h

#include "Arduino.h"

class Ultrasonico
{
	public:
		int trigger, echo; //pines para el disparador y el echo respectivamente


		Ultrasonico(int _trigger, int _echo)
		{
			trigger = _trigger;
			echo = _echo;

		  pinMode(trigger, OUTPUT);//pin como salida
		  pinMode(echo, INPUT);//pin como entrada 
		  digitalWrite(trigger, LOW);//inicializamos el pin con 0
		}

		Ultrasonico()
		{
			trigger = 0;
			echo = 0;

		  pinMode(trigger, OUTPUT);//pin como salida
		  pinMode(echo, INPUT);//pin como entrada 
		  digitalWrite(trigger, LOW);//inicializamos el pin con 0
		}

		Ultrasonico* asignar(Ultrasonico *from)
		{
			Ultrasonico *rtn = new Ultrasonico(from ->trigger, from-> echo);
			return rtn;
		}

		float distancia()
		{
			float t, d;//timepo en que demora en llegar el eco y distancia en cm
			digitalWrite(trigger,HIGH);
			delayMicroseconds(10); //enviamos un pulso de 10 us
			digitalWrite(trigger, LOW);
			t = pulseIn(echo, HIGH);//obtenemos el anch del pulso
			d = t/59;//escalamo el tiempo a una distancia en cm
			return d;
		}
};

#endif
