//项目三 —— 小台灯
int buttonPin = 2;               //按钮连接到数字2
int ledPin = 13;                 //LED连接到数字13

int ledState = HIGH;             // ledState记录LED状态
int buttonState;                  // buttonState记录按键状态
int lastButtonState = LOW;      // lastbuttonState记录按键前一个状态

long lastDebounceTime = 0; 
long debounceDelay = 50;         //去除抖动时间

void setup() {
  pinMode(buttonPin, INPUT); 
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop() {
  //reading用来存储buttonPin的数据
  int reading = digitalRead(buttonPin);
  
  // 一旦检测到数据发生变化，记录当前时间
  if (reading != lastButtonState) {
    	lastDebounceTime = millis();
  } 
  
  // 等待50ms，再进行一次判断，是否和当前button状态相同
  // 如果和当前状态不相同，改变button状态
  // 同时，如果button状态为高（也就是被按下），那么就改变LED的状态
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
          ledState = !ledState;
      }
    }
  }
  
  digitalWrite(ledPin, ledState);
   
   // 改变button前一个状态值
  lastButtonState = reading;
}


