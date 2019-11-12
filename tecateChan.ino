#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"
#include "SisLinea.h"

//Motores EN pinA pinB
Motor R2(49, 51, 53);
Motor R1(9, 10, 11);
Motor L1(5, 6, 7);
Motor L2(41, 43, 45);

SisMotores motores(R1, R2, L1, L2);

//Sensores ultrasonicos
Ultrasonico sensorL(100,39);
Ultrasonico sensorF(22,24);
Ultrasonico sensorR(1,60);

SisUltra sensores(sensorL, sensorF, sensorR); //Orden de los sensores Izquierda Frente Derecha

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
void pruebaMotores();

//############SETUP##########################

void setup() {
  Serial.begin(9600);

}



//#############Funcionamiento del robot###########################################
void loop() {

  pruebaMotores();
  /*
  motores.giroCerradoDer();
  delay(5000);
  motores.giroCerradoIzq();
  delay(5000);
  motores.giroAmplioDer();
  delay(5000);
  motores.giroAmplioIzq();
  delay(5000);*/
 
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
  while(sensores.distancia(1) > 20 && lineas.detectar())R2.atras();
  delay(3000);
  L1.adelante();
  delay(3000);
  L2.adelante();
  delay(3000);
  {
    motores.giroCerradoDer();
  }
  ataque();
}

void enemigoIzq()
{
  while(sensores.distancia(1) > 20 && lineas.detectar())
  {
    motores.giroCerradoIzq();
  }
  ataque();
   
}

void pruebaMotores()
{
  if(sensorF.distancia() < 20)
  {
    motores.giroAmplioDer();
  }
  else
  {
    motores.adelante*();
  }
}
