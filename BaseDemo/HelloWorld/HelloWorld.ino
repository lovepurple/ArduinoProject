//初始化
void setup() {
  // put your setup code here, to run once:
  //300 1200 2400 4800 9600 14400 19200 28800 38400 57600 115200
  //数值越大传输的越快
  
  Serial.begin(19200);       //打开串口，以9600波特率传输
}

//主循环
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Arduino");

  delay(1000);

}
