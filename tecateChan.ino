#include "Motor.h"
#include "Ultrasonico.h"
#include "Lineas.h"


Motor m1(10,9,8); //ENB INT4 INT3
Motor m2(5,6,7);
Ultrasonico sensor(24,22);
Lineas linea(25);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  if(sensor.distancia() <20.0 and linea.detectar())
  {
     m1.adelante();
  }
  else
  {
    m1.parar(1000);
  }
 
}
