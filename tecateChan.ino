#include "Motor.h"
#include "Ultrasonico.h"


Motor m1(10,9,8);
Motor m2(5,6,7);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  m1.adelante();
  delay(7000);
  m1.atras();
  delay(5000);
  m1.adelante();
  delay(7000);
  m1.parar();
  delay(4000);

}
