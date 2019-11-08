#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"

//Motores
Motor R2(5,6,7);
Motor R1(36, 38, 40);
Motor L2(10,8,9);
Motor   L1(28, 30, 32);

SisMotores motores(R1, R2, L1, L2);

//Sensores ultrasonicos
Ultrasonico sensor1(49,51);
Ultrasonico sensor2(33,34);
Ultrasonico sensor3(9,52);

SisUltra sensores(sensor1, sensor2, sensor3);

//Sensores seguilineas
Lineas lineaL(A0);
Lineas lineaR(A1);
Lineas lineaF(A2);


//Funciones

void ataque();


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  if(sensores.distancia(1) > 15.0)
  {
    Serial.println(sensores.distancia(1));
     motores.adelante();
  }
  else
  {
    Serial.println(sensores.distancia(1));  
    motores.parar();
  }
 
 
}
