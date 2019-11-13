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

		bool detectar() //esta funcion detecta oscuridad en cualquier sensor y regresara true
		{
			return (front.detectarS() && left.detectarS() && right.detectarS());
		}

		bool detectarL()
		{
			return left.detectarS();
		}

		bool detectarF()
		{
			return front.detectarS();
		}

		bool detectarR()
		{
			return right.detectarS();
		}
};

#endif
