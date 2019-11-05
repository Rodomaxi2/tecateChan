#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"


Motor R2(5,6,7);
Motor R1(36, 38, 40);
Motor L2(10,8,9);
Motor L1(28, 30, 32);

//SisMotores motores(R1, R2, L1, L2);

Ultrasonico sensor(24,22);
Lineas lineaL(25, A0);
Lineas lineaR(31, A1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  if(sensor.distancia() <20.0 && lineaL.detectarAn() && lineaR.detectarAn())
  {
     R1.adelante();
     L1.adelante();
     R2.adelante();
     L2.adelante();
  }
  else
  {
    R1.parar();
    L1.parar();
    R2.parar();
    L2.parar();
  }
  
 
}
