#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"
#include "SisMotores.h"
#include "SisUltra.h"
#include "SisLinea.h"

//Motores EN pinA pinB
Motor R2(27, 25, 23);
Motor R1(48, 50, 52);
Motor L1(49, 51, 53);
Motor L2(26, 24, 22);

SisMotores motores(R1, R2, L1, L2); //Mmotor R1 R2 L1 L2

//Sensores ultrasonicos
Ultrasonico sensorL(10,11);
Ultrasonico sensorF(7,6);
Ultrasonico sensorR(8,9);

SisUltra sensores(sensorF, sensorL, sensorR); //Orden de los sensores Frente Izquierda Derecha

//Sensores seguilineas
Lineas lineaL(A7);
Lineas lineaR(A9);
Lineas lineaF(A5);

SisLinea lineas(lineaF, lineaL, lineaR); //Orden de los sensores seguilinea Frente Izquierda Derecha

//Funciones de maniobras

void ataque();
void buscar();
void enemigoDer();
void enemigoIzq();
void pruebaMotores();

//############SETUP##########################

void setup() {
  //Serial.begin(9600);

}



//#############Funcionamiento del robot###########################################
void loop() {

  pruebaMotores();
  
 
 
}

//###########Maniobras###########################################################

void ataque()
{
  while(sensores.distancia(1) < 35 && !lineas.detectarF())
  {
    motores.adelante();
  }
  if(lineas.detectarF()){
    motores.atras();
      delay(300);
      motores.parar();
      motores.giroDer();
      delay(300);
      motores.parar();
      motores.adelante();
  }
  motores.parar();
  buscar();
}

void buscar()
{
  //
  if(sensores.distancia(0))
    ataque();
  else if(sensores.distancia(1))
    enemigoIzq();
  else if(sensores.distancia(2))
    enemigoDer();
}

void enemigoDer() //si se detecta un enemigo a la derecha girara hasta que lo tenga enfrente
{
  int i=0;
   while(sensores.distancia(1) > 35 && !lineas.detectar()&&i<300000)
  {
    motores.giroDer();
    i++;
  }
  motores.parar();
  ataque();
}

void enemigoIzq()
{
  while(sensores.distancia(1) > 35 && !lineas.detectar())
  {
    motores.giroIzq();
  }
  motores.parar();
  ataque();
   
}

void pruebaMotores()
{
  motores.parar();
  if(!lineas.detectar())
  {
    motores.adelante();
    
  }
  else
  {
    if(lineas.detectarF())
    {
      motores.atras();
      delay(300);
      motores.parar();
      motores.giroDer();
      delay(300);
      motores.parar();
      motores.adelante();
    }
    else if(lineas.detectarL())
    {
      motores.giroDer();
      delay(300);
      motores.parar();
      motores.adelante();
    }
    else if(lineas.detectarR())
    {
      motores.giroIzq();
      delay(300);
      motores.parar();
      motores.adelante();
    }
  }
}
