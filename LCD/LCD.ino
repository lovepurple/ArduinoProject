//LCD.ino
/*
	LCD 实验，LCD一共16个引脚
		A、K 引脚是背光的电源正负极，需要3.3V供电
		VDD VSS  分别是电源的正负极，需要5V供电
		D0~D7 是数据传输的引脚，接数字信号pin
		V0 调节对比度，这里串联个电阻之后 直接接地
		RS 命令/数据 选择引脚，电平高-数据操作  电平低-命令操作
		RW 读/写 选择引脚，电平高-读  电平低-写
		E 正脉冲通知把数据读走
*/

#include "LiquidCrystal.h"

LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello World");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
}
