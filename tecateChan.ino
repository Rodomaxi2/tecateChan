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
Ultrasonico sensorL(11,10);
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
int estado = 0; // 0 parado 1 adelante 2 atras 3 izq 4 der

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
  if(estado!=1)
  {
    motores.parar(100);
    motores.adelante();
    estado = 1;
  }
  
}

void buscar()
{
  if(sensores.distancia(1) < 30 && sensores.distancia(1) > 5)
    ataque();
  else if(sensores.distancia(0) < 30 && sensores.distancia(0) > 5)
    enemigoIzq();
  else if(sensores.distancia(2) < 30 && sensores.distancia(2) > 5)
    enemigoDer();
  else
  {
    
  }
   
}

void enemigoDer() //si se detecta un enemigo a la derecha girara hasta que lo tenga enfrente
{
  while(sensores.distancia(1) > 35)
  {
    if(estado != 4)
    {
      motores.parar();
      motores.giroDer();
      estado = 4;
    }
  }
  ataque();
}

void enemigoIzq()
{
  while(sensores.distancia(1) > 35)
  {
    if(estado != 3)
    {
      motores.parar();
      motores.giroIzq();
      estado = 3;
    }
  }
  ataque();
   
}

void pruebaMotores()
{
  if(lineas.detectar())
  {
    //if(estado != 1)
    {
      buscar();
      /*
      motores.parar(100);
      motores.adelante(100);
      estado = 1;
      */
    } 
  }
  
  else
  {
    if(!lineas.detectarF())
    {
      if(estado != 2)
      {
        motores.parar(100);
        motores.atras();
        delay(200);
        motores.giroDer();
        delay(150);
        estado = 4;
      }
      
    }
    else if(!lineas.detectarL() && lineas.detectarR())
    {
      if(estado != 4)
      {
        motores.parar(100);
        motores.giroDer();
        estado = 4;
      }
      
    }
    else if(!lineas.detectarR() && lineas.detectarL())
    {
      if(estado != 3)
      {
        motores.parar(100);
        motores.giroIzq();
        estado = 3;
      }
    }

    else if(!lineas.detectarR() && !lineas.detectarL())
    {
        motores.parar(100);
        motores.adelante(100);
        estado = 1;
     
    }
    
  }
}
