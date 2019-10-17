#include "Motor.h"


Motor motor(10,9,8);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  motor.adelante();
  delay(7000);
  motor.atras();
  delay(5000);
  motor.adelante();
  delay(7000);
  motor.parar();
  delay(4000);

}
