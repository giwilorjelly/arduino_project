

/*
  GIWIL GIDWANI
  AUTO 2WD
  16/9/2018
*/

#include <AFMotor.h>

AF_DCMotor rightDC(1);

AF_DCMotor leftDC(4);

const double vSpeed=0.0343;

const int trigPin=2;

const int echoPin=13;

const int INTP=9600;

long duration;

float distance;

String currentDirection;

void setup() {
  Serial.begin(INTP);
  Serial.println("Session Started");
  currentDirection="";
  
  //setting speed
  rightDC.setSpeed(70);
  leftDC.setSpeed(70);

}

void loop() {
  delay(250);
  distance= measureDistance();
  
  if(distance>55&&!(currentDirection.equals("front"))){
      currentDirection="front";
      goForward();
    }
  else if(distance==0&&!currentDirection.equals("halt")){
      currentDirection="halt";
      haltDC();
   }  
  else if(distance>0&&distance<55&&!currentDirection.equals("turning")){
      currentDirection="turning";
      turnRight();
    }
  

  Serial.print(distance,",");
  Serial.println(currentDirection);  
}

float measureDistance(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  
  return (vSpeed*duration/2);
  
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
  //defaultSpeed();
  rightDC.run(FORWARD);
  leftDC.run(FORWARD);
}

void goBackward(){
  //defaultSpeed();
  rightDC.run(BACKWARD);
  leftDC.run(BACKWARD);
}

void turnRight(){
  //changeSpeed(100);
  rightDC.run(BACKWARD);
  leftDC.run(FORWARD);
}

void turnLeft(){
  //changeSpeed(100);
  rightDC.run(FORWARD);
  leftDC.run(BACKWARD);
}

void changeSpeed(int v){
  rightDC.setSpeed(v);
  leftDC.setSpeed(v);
}
