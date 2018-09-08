/*
  GIWIL GIDWANI
  CUSTOM 2WD
  29/8/2018
*/

#include <AFMotor.h>

AF_DCMotor rightDC(1);

AF_DCMotor leftDC(4);

const int INTP=9600;

const int sensitivity=200;

void setup() {
  Serial.begin(INTP);
  Serial.println("Session Started");

  //setting speed
  rightDC.setSpeed(200);
  leftDC.setSpeed(200);

}

void loop() {
  if(Serial.available()>0){
        char data= Serial.read();
        Serial.println(data);
          switch(data){
            
            case '1':goForward();
            break;
            case '2':goBackward();
            break;
            case '4':turnRight();
            break;
            case '3':turnLeft();
            break;
            default:haltDC();
            }
            //haltDC();
      }

}
void defaultSpeed(){
  rightDC.setSpeed(200);
  leftDC.setSpeed(200);
}

void haltDC(){
  rightDC.run(RELEASE);
  leftDC.run(RELEASE);
   
}

void goForward(){
  defaultSpeed();
  rightDC.run(FORWARD);
  leftDC.run(FORWARD);
  //delay(sensitivity);
}

void goBackward(){
  defaultSpeed();
  rightDC.run(BACKWARD);
  leftDC.run(BACKWARD);
  //delay(sensitivity);
}

void turnRight(){
  changeSpeed(100);
  rightDC.run(BACKWARD);
  leftDC.run(FORWARD);
  //delay(sensitivity);
}

void turnLeft(){
  changeSpeed(100);
  rightDC.run(FORWARD);
  leftDC.run(BACKWARD);
  //delay(sensitivity);
}

void changeSpeed(int v){
  rightDC.setSpeed(v);
  leftDC.setSpeed(v);
}
