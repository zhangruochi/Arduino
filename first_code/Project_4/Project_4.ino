//项目四 —— 声控灯
int soundPin = 0;       //声音传感器接到模拟0
int ledPin =  13;       //LED接到数字13

void setup() {
  pinMode(ledPin, OUTPUT);
 // Serial.begin(9600);    //用于调试
}

void loop(){
  int soundState = analogRead(soundPin);  //读取传感器的值
 // Serial.println(soundState);      //串口打印声音传感器的值

//如果声音值大于10，亮灯，并持续10s，否则关灯
  if (soundState > 10) {           
      digitalWrite(ledPin, HIGH);  
      delay(10000);
  }else{
      digitalWrite(ledPin, LOW);
  }
}

