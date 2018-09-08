/*
  GIWIL GIDWANI
  BT TEST
  29/8/2018
*/

const int INTP=9600;

void setup() {
  Serial.begin(9600);
  Serial.println("Session Started");
}

void loop() {
 if(Serial.available()>0){
        String data= Serial.readString();
        Serial.println(data);

        if(data.indexOf("change_")>-1){
            Serial.print("Changing speed to: ");
            int v= data.substring(data.indexOf('_')+1,data.length()).toInt();
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
            }
        else if(data.equals("front")){
            goForward();
          }
        else if(data.equals("back")){
            goBackward();
          }
        else if(data.equals("right")){
            turnRight();
          }
        else if(data.equals("left")){
            turnLeft();
          }
        else {
            haltDC();
          }*/        
      }
}
