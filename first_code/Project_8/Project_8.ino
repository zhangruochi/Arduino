#include <Servo.h>    
Servo myservo;
int LED = 3;                      //设置LED灯为数字引脚3
int val = 0;                      //设置模拟引脚0读取光敏二极管的电压值
int pos = 0;
int light =0;

void setup(){
     pinMode(LED,OUTPUT);         // LED为输出模式
     Serial.begin(9600);         // 串口波特率设置为9600
     myservo.attach(9);
     myservo.write(0); 
}

void loop(){
     val = analogRead(0);         // 读取电压值0~1023
     Serial.println(val);         // 串口查看电压值的变化
     if(val<40){                 // 一旦小于设定的值，LED灯关闭
          pos = pos +2;
          if(pos >= 90){      
              pos = 90;              
          }
          myservo.write(pos);      //写入舵机的角度
          delay(100);
          light = map(pos,0,90,0,255);
          analogWrite(LED,light);   
     }else{                  
          pos = pos -2;
          if(pos <= 0){
             pos = 0;
          }
          myservo.write(pos);      //写入舵机的角度  
          delay(100);     
          light = map(pos,0,90,0,255);
          analogWrite(LED,light); 
     }
}

