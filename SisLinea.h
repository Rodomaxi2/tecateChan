#ifndef SisLinea_h
#define SisLinea_h

#include "Arduino.h"
#include "Lineas.h"

class SisLinea
{
	public:
		Lineas front, left, right; //se crean los objetos de sensores ultrasonicos
		

		SisLinea(Lineas _front , Lineas _left , Lineas _right) //se obtienen los objetos de tipo linea de front , left y right
		{
			front = _front;
			left = _left;
			right = _right;
		}

		bool detectar() //esta funcion detecta brillo en cualquier sensor y regresara true
		{
			return front.detectar() || left.detectar() || right.detectar();
		}

		bool detectarL()
		{
			return left.detectar();
		}

		bool detectarF()
		{
			return front.detectar();
		}

		bool detectarR()
		{
			return right.detectar();
		}
};

#endif