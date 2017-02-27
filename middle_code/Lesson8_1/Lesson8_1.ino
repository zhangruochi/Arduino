//项目八 – 火焰报警器
float sinVal;            
int toneVal;  

void setup(){ 
    pinMode(8, OUTPUT);        // 蜂鸣器引脚设置
    Serial.begin(9600);        //设置波特率为9600 bps
}

void loop(){ 
    int sensorValue = analogRead(0);   //火焰传感器连到模拟口，并从模拟口读值
    Serial.println(sensorValue); 
    delay(1);
    if(sensorValue < 1023){        //  如果数据小于1023，说明有火源，蜂鸣器响   
          for(int x=0; x<180; x++){
            //将sin函数角度转化为弧度
            sinVal = (sin(x*(3.1412/180)));
            //用sin函数值产生声音的频率
            toneVal = 2000+(int(sinVal*1000));
            //给引脚8一个
            tone(8, toneVal);
            delay(2); 
     }   
    } else {    // 如果数据大于等于1023，没有火源，关闭蜂鸣器
           noTone(8);          //关闭蜂鸣器 
    }
}  
  


