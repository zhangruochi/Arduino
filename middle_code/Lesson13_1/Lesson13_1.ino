int latchPin = 8;  //数字口8连接到74HC595芯片的使能引脚
int clockPin = 3;  //数字口3连接到74HC595芯片的时钟引脚
int dataPin = 9;   //数字口9连接到74HC595芯片的数据引脚
int buttonPin = 2; // 按钮连接到数字口2 

//代表数字0~9
byte Tab[]={
0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int number;
long randNumber;
void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    randomSeed(analogRead(0));   //设置一个随机数产生源模拟口0
}

void loop(){
    randNumber = random(10);   //产生0~9之间的随机数
    showNumber(randNumber);    //显示该随机数

    //一旦有按键按下，显示该数，并保持到松开为止
    while(digitalRead(buttonPin) == HIGH){  
       delay(100);
    } 
}

//该函数用于数码管显示
void showNumber(int number){
     digitalWrite(latchPin, LOW);
     shiftOut(dataPin, clockPin, MSBFIRST, Tab[number]);
     digitalWrite(latchPin, HIGH);
     delay(80);
}

