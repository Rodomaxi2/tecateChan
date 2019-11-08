#ifndef SisLinea_h
#define SisLinea_h

#include "Arduino.h"
#include "Lineas.h"

class SisLinea
{
	public:
		Lineas front, left, right; //se crean los objetos de sensores ultrasonicos
		

		SisLinea(Lineas _front , Lineas _left , Lineas _right)
		{
			front = _front;
			left = _left;
			right = _right;
		}
};

#endif