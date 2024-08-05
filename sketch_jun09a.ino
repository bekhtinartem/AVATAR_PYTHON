#include <Servo.h> 
#include <String.h>
int servoPin_spin = 5, servoPin_up=4, servoPin_front=3, servoPin_cleaching=2;
// Создаем объект
Servo Servo1_spin, Servo1_up, Servo1_front, Servo1_cleaching;

void setup() {
  Servo1_spin.attach(servoPin_spin);
  Servo1_up.attach(servoPin_up);
  Servo1_front.attach(servoPin_front);
  Servo1_cleaching.attach(servoPin_cleaching);
  Serial.begin(115200); 
}

void loop(){
  
  
  if (Serial.available() >3) {
    int x=Serial.read();
    int y=Serial.read();
    int z=Serial.read();
    int pos=Serial.read();
    //pos-=48;
 
    Serial.println(pos);
    
    Servo1_spin.write(150-x);
    //delay(100);
    //Servo1_spin.write(45);
    Servo1_up.write(90+y);
    //delay(100);
    Servo1_front.write(45+z);
    //delay(100);
    
    if(pos==0){
      Servo1_cleaching.write(20);
      //delay(100);
    }else{
      Servo1_cleaching.write(70);
      //delay(100);
    }
  }
  
 }
