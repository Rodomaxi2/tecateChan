#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"


Motor R2(5,6,7);
Motor R1(36, 38, 40);
Motor L2(10,8,9);
Motor L1(28, 30, 32);

SisMotores motores(R1, R2, L1, L2);

Ultrasonico sensor1(49,51);
Ultrasonico sensor2(33,34);
Ultrasonico sensor3(9,52);

SisUltra sensores(sensor1, sensor2, sensor3);

Lineas lineaL(25, A0);
Lineas lineaR(31, A1);
Lineas lineaF(53, A2);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  if(sensores.distancia() > 15.0 /*&& lineaL.detectarAn() && lineaR.detectarAn()*/)
  {
    Serial.println(sensores.distancia());
     motores.adelante();
  }
  else
  {
    Serial.println(sensores.distancia());  
    motores.parar();
  }
 
 
}
