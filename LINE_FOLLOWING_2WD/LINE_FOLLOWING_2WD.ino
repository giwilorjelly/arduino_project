#include <AFMotor.h>


/*
  GIWIL GIDWANI
  LINE_FOLLOWING_2WD
  10/9/2018
*/



AF_DCMotor rightDC(1);

AF_DCMotor leftDC(4);

const int INTP=9600;

const int IR_R=13;

const int IR_L=2;

String currentDirection;

void setup() {
  //setting IR pins
  pinMode(IR_R,INPUT);
  pinMode(IR_L,INPUT);

  currentDirection="null";
  
  Serial.begin(INTP);
  Serial.println("Session Started");

  //setting speed
  rightDC.setSpeed(70);
  leftDC.setSpeed(70);

  


}

void loop() {
  
  int R_OUTPUT=digitalRead(IR_R);
  int L_OUTPUT=digitalRead(IR_L);

  if(R_OUTPUT==LOW&&L_OUTPUT==LOW){
      haltDC();
      currentDirection="halt";
      Serial.println("err: Device not on track"); 
    }
  else if(R_OUTPUT==LOW&&L_OUTPUT==HIGH&&!(currentDirection.equals("left"))){
     Serial.println("turning left");
     currentDirection="left";
     turnLeft();
      
    }
  else if(R_OUTPUT==HIGH&&L_OUTPUT==LOW&&!(currentDirection.equals("right"))){
      Serial.println("turning right");
      currentDirection="right";
      turnRight();
      
    }
  else if(R_OUTPUT==HIGH&&L_OUTPUT==HIGH&&!(currentDirection.equals("front"))){
      Serial.println("moving forward");
      currentDirection="front";
      goForward();
     
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
  Serial.println("called");
  rightDC.run(FORWARD);
  leftDC.run(FORWARD);
}

void goBackward(){
  //defaultSpeed();
  rightDC.run(BACKWARD);
  leftDC.run(BACKWARD);
}

void turnRight(){
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
