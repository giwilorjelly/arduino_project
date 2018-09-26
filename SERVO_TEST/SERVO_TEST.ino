/*
  GIWIL GIDWANI
  SERVO TEST
  28/8/2018
*/
  
#include <Servo.h>

Servo servo;

void setup(){
  servo.attach(10); 
}

void loop(){
  for(int i=0;i<=155;i++){
      servo.write(i);
      delay(50);
    }
}
