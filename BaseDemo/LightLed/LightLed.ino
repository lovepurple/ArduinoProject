//点亮面包板上的LED

int pinNo = 7;      //使用7pin口
int INTERVAL = 100;


/**
 * loop 主循环，就相当一个while(true) 所以在使用变量的时候 要注意变量的生命周期
 *  负极接的是GND 正极接的是pin口，这个不属于串口，可以不需要Serial 
 *  这里为了调试方便打印log
 */

int flag = 0;

void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pinNo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag == 0 || flag == 1)
  {
    INTERVAL = 300;
  }
  else if (flag == 2)
  {
    INTERVAL = 1000;
  }

  Serial.println(flag);
  digitalWrite(pinNo, HIGH);
  delay(INTERVAL);

  digitalWrite(pinNo, LOW);
  delay(INTERVAL);

  Serial.println(flag);
  
  flag += 1;
  if (flag > 2)
  {
    flag = 0;
  }

}



