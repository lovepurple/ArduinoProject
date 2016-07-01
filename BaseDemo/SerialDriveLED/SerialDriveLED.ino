//通过串口输入命令点亮不同的LED灯

int minPinIndex = 2;
int maxPinIndex = 7;

void setup() {
  // put your setup code here, to run once:
  for (int i = minPinIndex; i <= maxPinIndex ; ++i)
  {
    pinMode(i, OUTPUT);
  }

  //打开串口
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeat

  //执行的过程中，如果串口继续输入数据会 攒着 然后依次执行
  char val = Serial.read();

  //返回串口缓冲区里的剩余字符个数，最多能缓冲128个字节  也就是128 /1024 K
  Serial.println(Serial.available());

  if (val != -1)
  {
    //ASCII 转换
    int pinNum =val -48 ;

    if (pinNum >= 2 || pinNum <= 7)
    {
      for(int j = 0 ; j < 10;++j)
      {
        digitalWrite(pinNum, HIGH);
        delay(1000);
        digitalWrite(pinNum, LOW);
        delay(500);
      }
    }

  }



}
