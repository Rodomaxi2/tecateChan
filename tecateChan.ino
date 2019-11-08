#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"

//Motores
Motor R2(5,6,7);
Motor R1(36, 38, 40);
Motor L2(10,8,9);
Motor L1(28, 30, 32);

SisMotores motores(R1, R2, L1, L2);

//Sensores ultrasonicos
Ultrasonico sensor1(2,3);
Ultrasonico sensor2(35,34);
Ultrasonico sensor3(9,52);

SisUltra sensores(sensor1, sensor2, sensor3);

//Sensores seguilineas
Lineas lineaL(A0);
Lineas lineaR(A1);
Lineas lineaF(A2);


//Funciones

void ataque();
void buscar();
void enemigoDer();
void enemigoIzq();


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  
  ataque();
  Serial.println(sensores.distancia(1));
 
}

void ataque()
{
  while(sensores.distancia(1) < 20)
  {
    motores.adelante();
  }
  motores.parar();
  buscar();
}

void buscar()
{
  //
}

void enemigoDer()
{
  while(sensores.distancia(1) > 20)
  {
    motores.giroCerradoDer();
  }
  ataque();
}

void enemigoIzq()
{
  while(sensores.distancia(1) > 20)
  {
    motores.giroCerradoIzq();
  }
  ataque();
   
}
