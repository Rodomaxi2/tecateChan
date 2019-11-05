#ifndef SisMotores_H
#define SisMotores_H

#include "Motor.h"

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
            L1.adelante();
            L2.adelante();
            R1.adelante();
            R2.adelante();
        }


};


#endif