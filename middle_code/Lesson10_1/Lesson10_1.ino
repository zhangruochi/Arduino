#include <Servo.h>             

int sensorPin = 3;          //震动传感器 – Digital 3
Servo myservo;                 
int pos = 0;  

void setup() { 
    Serial.begin(9600);
    pinMode(sensorPin, INPUT);   
    myservo.attach(9);         //舵机 – Digital 9
}

void loop() {
  int sensorState = digitalRead(sensorPin);//读取震动传感器的状态
  Serial.println(sensorState);
  if(!sensorState){  //一旦状态发生变化，舵机加2°，直到加到180°
            pos = pos +2;
            if(pos >=180){      
                pos = 180;                
            } 
            myservo.write(pos);      //写入舵机的角度       
            Serial.println(pos);     //串口同时输出角度值
            delay(100);  
  } else{  //状态不发生变化，舵机减2°，直到减到0°
            pos = pos - 2; 
            if(pos <=0){
                pos = 0;                
            }
            myservo.write(pos);              
            Serial.println(pos);
            delay(100);    
  }
  delay(1);        
}

