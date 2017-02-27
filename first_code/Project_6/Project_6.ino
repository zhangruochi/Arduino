//项目六 —— 亮度调节器
int potPin = 0;                   //电位器连接到模拟0
int ledPin = 10;                  //LED连接到数字10

void setup() {
   pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);    //读取模拟口0的值       
  //通过map()把0~1023的值转换为0~255
  int outputValue = map(sensorValue, 0, 1023, 0, 255);   
  analogWrite(ledPin, outputValue);   //给LED写入对应值        
  delay(2);                     
}

