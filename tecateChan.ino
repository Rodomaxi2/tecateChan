#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"
#include "SisLinea.h"

//Motores
Motor R2(5,6,7);
Motor R1(36, 38, 40);
Motor L2(10,8,9);
Motor L1(28, 30, 32);

SisMotores motores(R1, R2, L1, L2);

//Sensores ultrasonicos
Ultrasonico sensorL(2,3);
Ultrasonico sensorF(35,34);
Ultrasonico sensorR(9,52);

SisUltra sensores(sensor1, sensor2, sensor3); //Orden de los sensores Izquierda Frente Derecha

//Sensores seguilineas
Lineas lineaL(A0);
Lineas lineaR(A1);
Lineas lineaF(A2);

SisLinea lineas(lineaF, lineaL, lineaR);

//Funciones de maniobras

void ataque();
void buscar();
void enemigoDer();
void enemigoIzq();

//############SETUP##########################

void setup() {
  Serial.begin(9600);

}



//#############Funcionamiento del robot###########################################
void loop() {
  
  ataque();
  Serial.println(sensores.distancia(1));
 
}

//###########Maniobras###########################################################

void ataque()
{
  while(sensores.distancia(1) < 20 && lineas.detectarF())
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

void enemigoDer() //si se detecta un enemigo a la derecha girara hasta que lo tenga enfrente
{
  while(sensores.distancia(1) > 20 && lineas.detectar())
  {
    motores.giroCerradoDer();
  }
  ataque();
}

void enemigoIzq()
{
  while(sensores.distancia(1) > 20 && )
  {
    motores.giroCerradoIzq();
  }
  ataque();
   
}
