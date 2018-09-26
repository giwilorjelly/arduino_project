/*
  GIWIL GIDWANI
  ULTRASONIC_TEST
  13/9/2018
*/

const double vSpeed= 0.0343;

const int trigPin=13;

const int echoPin=2;

const int INTP=9600;

float distance;

long duration;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(INTP);
}

void loop(){
    delay(1000);
    Serial.println(measureDistance());
}

int measureDistance(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH); 
  distance=(duration*vSpeed)/2;

  return(distance);
}
