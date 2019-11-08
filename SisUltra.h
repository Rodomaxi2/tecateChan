#ifndef SisUltra_h
#define SisUltra_h

#include "Arduino.h"
#include "Ultrasonico.h"

class SisUltra
{
	public:
		Ultrasonico front, left , right; //se crean los objetos de sensores ultrasonicos
		

		SisUltra(Ultrasonico _front , Ultrasonico _left , Ultrasonico _right)
		{
			front = _front;
			left = _left;
			right = _right;
		}

		float distancia(int sensor) //funcion que regresa la distancia de acuerdo al parametro que se pase 0=left, 1=front, 2=right
		{
			switch(sensor)
			{
				case 0: return left.distancia(); break;
				case 1: return front.distancia(); break;
				case 2: return right.distancia(); break;
				default: return 0; break;
			}
		}

};

#endif
