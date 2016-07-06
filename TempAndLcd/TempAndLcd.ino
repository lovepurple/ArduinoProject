//TempAndLcd.ino
/*
	Lcd 与 温度传感器结合实验
	1. 温度传感器使用的是LM35 有三个引脚
	2. 温度传感器接到模拟信号引脚
	3. 将模拟输出转化为温度
		模拟输出电压是0~5 之间，对应模拟口的读数是1~1024 ，也就是所有的模拟口输出analogRead 是1~1024，映射为电压是0~5V
		所以每一份是 5 / 1024 =0.0048828125 
			analogRead(pin) * 0.0048828125 
		电压每升高1℃，电压增加10毫伏
		1℃ = 0.01V
		所以：
			输出的温度 = analogRead(pin) * 0.0048828125 / 0.01
*/

#include "LiquidCrystal.h"

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() 
{
	lcd.begin(16,2);
	
}

void loop() 
{
	lcd.clear();
	lcd.setCursor(3,0);			//行一个参数是column,第二个是row
	lcd.print("hello world");

	lcd.setCursor(0,1);

	float tempVal = analogRead(4);
	float displayTemp = tempVal * 0.0048828125 * 100;

	lcd.print((long)displayTemp / 10);
	lcd.print(".");
	lcd.print((long)displayTemp % 10);
	lcd.print((char)223);
	lcd.print("C");
	delay(2000);
}
