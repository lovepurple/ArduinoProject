/*
双Arduino 使用I2C 通讯
1. Arduino Uno ,Nano 的A4 A5引脚是参与I2C的两个引脚（SDA,SCL）
2. Arduino 要共地
3. 使用 Wire.h
*/

#include <Wire.h>

void setup()
{

  /* add setup code here */
	Wire.begin();

}

byte sendByte = 0;

void loop()
{
	Wire.beginTransmission(4);
	//Wire.write(sendByte);
	//Wire.write("wocaonidaye");
	Wire.write("Hello");
	Wire.endTransmission();
	
	//sendByte++;

	delay(100);
}
