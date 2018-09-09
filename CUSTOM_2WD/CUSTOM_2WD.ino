

/*
  GIWIL GIDWANI
  CUSTOM 2WD
  29/8/2018
*/

#include <AFMotor.h>

#include <Servo.h>

Servo servo;

AF_DCMotor rightDC(1);

AF_DCMotor leftDC(4);

const int INTP=9600;

const int sensitivity=200;

int servoPos;

void setup() {
  Serial.begin(INTP);
  Serial.println("Session Started");

  //setting speed
  rightDC.setSpeed(100);
  leftDC.setSpeed(100);

  //setting servo
  servo.attach(10);

}

void loop() {
  if(Serial.available()>0){
        String data= Serial.readString();
        Serial.println(data);

            char ch=data.charAt(0);
            switch(ch){
                case 'f':goForward();
                break;
                case 'b':goBackward();
                break;
                case 'l':turnLeft();
                break;
                case 'r':turnRight();
                break;
            }
        if(data.length()>1){
          if(data.indexOf("change_")>-1){
            Serial.print("Changing speed to: ");
            int v= data.substring(data.indexOf('_')+1,data.length()).toInt();
            haltDC();
            changeSpeed(v);
            Serial.println(v);
            
            }
         else if(data.indexOf("servo_")>-1){
            Serial.print("Changing angle to: ");
            int v= data.substring(data.indexOf('_')+1,data.length()).toInt();
            servo.write(v);
            Serial.println(v);
            
            }
         else {
            haltDC();
            //Serial.println("STOP");
            }
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
