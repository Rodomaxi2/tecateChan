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

		//estas funciones no coinciden con la descripcion por el cambio en "Lineas.h"
		void detectar() //esta funcion detecta brillo en cualquier sensor y regresara true
		{
			return front.detectar() || left.detectar() || right.detectar();
		}

		void detectarL()
		{
			return left.detectar();
		}

		void detectarF()
		{
			return front.detectar();
		}

		void detectarR()
		{
			return right.detectar();
		}
};

#endif