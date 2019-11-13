#ifndef SisMotores_H
#define SisMotores_H

#include "Motor.h"
#include "Arduino.h"

class SisMotores
{

    public:

        Motor L1, L2, R1, R2; //se crean 4 motores con valores de 0 en todos sus pines

        SisMotores(Motor _R1, Motor _R2, Motor _L1, Motor _L2) //Constructor que sobreescribe los valores de los motores
        {
            R1 = _R1;
            R2 = _R2;
            L1 = _L1;
            L2 = _L2;
        }

        void adelante() //Pone en marcha todos los motores
        {
            L1.adelanteM();
            L2.adelanteM();
            R1.adelanteM();
            R2.adelanteM();
        }

        void adelante(int potencia) //Pone en marcha todos los motores
        {
            L1.adelanteM(potencia);
            L2.adelanteM(potencia);
            R1.adelanteM(potencia);
            R2.adelanteM(potencia);
        }

        void atras()
        {
            L1.atras();
            L2.atras();
            R1.atras();
            R2.atras();
        }

        void parar()//detiene todos los motores
        {
            L1.parar();
            L2.parar();
            R1.parar();
            R2.parar();
        }

        void parar(int tiempo)//detiene todos los motores
        {
            L1.parar(tiempo);
            L2.parar(tiempo);
            R1.parar(tiempo);
            R2.parar(tiempo);
        }

        void giroIzq() //gira a la izquierda
        {
            L1.atras();
            L2.atras();
            R1.adelanteM();
            R2.adelanteM();
        }

        void giroDer() //gira a la derecha
        {
            R1.atras();
            R2.atras();
            L1.adelanteM();
            L2.adelanteM();
        }

};


#endif