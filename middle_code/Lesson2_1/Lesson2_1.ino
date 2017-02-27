//项目二 —— 感应灯
int sensorPin = 2;             //传感器连接到数字2
int ledPin =  13;               //LED连接到数字13
int sensorState = 0;           //变量sensorState用于存储传感器状态

void setup() {
  pinMode(ledPin, OUTPUT);         //LED为输出设备
  pinMode(sensorPin, INPUT);      //传感器为输入设备
}

void loop(){
  sensorState = digitalRead(sensorPin);    //读取传感器的值
  
  if (sensorState == HIGH) {       //如果为高，LED亮
    digitalWrite(ledPin, HIGH);  
  } 
  else {                               //否则，LED灭
    digitalWrite(ledPin, LOW); 
  }
}

