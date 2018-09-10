/*
  GIWIL GIDWANI
  IR_TEST
  10/9/2018
*/

const int INTP=9600;
int IR_PIN=8;

void setup() {
  pinMode(IR_PIN,INPUT);
  Serial.begin(INTP);
}

void loop() {
  int IR_OUTPUT=digitalRead(IR_PIN);
  if(IR_OUTPUT==LOW){
      Serial.println("PING");
    }
  else{
      Serial.println(0);
    }
}
