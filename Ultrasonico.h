#ifndef Ultrasonico_h
#define Ultrisonico_h

#include "Arduino.h"

class Ultrasonico
{
	public:
		int trigger, echo; //pines para el disparador y el echo respectivamente

		Ultrasonico(int, int);
		float distancia();
};

#endif
