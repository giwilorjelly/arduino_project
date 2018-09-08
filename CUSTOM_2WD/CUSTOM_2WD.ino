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
  rightDC.setSpeed(100);
  leftDC.setSpeed(100);

}

void loop() {
  if(Serial.available()>0){
        String data= Serial.readString();
        Serial.println(data);

        if(data.indexOf("change_")>-1){
            Serial.print("Changing speed to: ");
            int v= data.substring(data.indexOf('_')+1,data.length()).toInt();
            haltDC();
            changeSpeed(v);
            Serial.println(v);
            
          }
          /*switch(data){
            case "front":goForward();//1
            break;
            case "back":goBackward();//2
            break;
            case "right":turnRight();//4
            break;
            case "left":turnLeft();//3
            break;
            default:haltDC();  
            }*/
        else if(data.equals("front")){
            goForward();
            Serial.println("goForward");
          }
        else if(data.equals("back")){
            goBackward();
            Serial.println("goBackward");
          }
        else if(data.equals("right")){
            turnRight();
            Serial.println("turnRight");
          }
        else if(data.equals("left")){
            turnLeft();
            Serial.println("turnLeft");
          }
        else {
            haltDC();
            Serial.println("STOP");
          }        
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
