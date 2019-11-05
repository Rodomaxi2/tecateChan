#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"


Motor R1(10,9,8); //ENB INT4 INT3
Motor R2(36, 38, 40);
Motor L1(5,6,7);
Motor L2(28, 30, 32);

//SisMotores motores(R1, R2, L1, L2);

//Ultrasonico sensor(24,22);
Lineas linea(25);

void setup() {
  // put your setup code here, to run once:

}

void loop() {

  R1.adelante();
  R2.adelante();
  L1.adelante();
  L2.adelante();

  /*
  if(sensor.distancia() <20.0 and linea.detectar())
  {
     R1.adelante();
  }
  else
  {
    R1.parar(1000);
  }
  */
 
}
