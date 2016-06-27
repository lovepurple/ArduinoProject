//点亮板子上的LED

void setup() {
  // put your setup code here, to run once:

  //设置pin13 为输出模式
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);      //设置LED 开
  delay(1000);

  digitalWrite(13,LOW);     //设置LED 关
  delay(1000);
  
}
