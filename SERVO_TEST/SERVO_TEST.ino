/*
  GIWIL GIDWANI
  SERVO TEST
  28/8/2018
*/
  
#include <Servo.h>

Servo servo;

int servoPos;

void setup(){
  servo.attach(10);
  servoPos=0;    
}

void loop(){
  if(servoPos==90)
    servoPos=0;
  servoPos++;
  servo.write(servoPos);
  delay(50);
}
