/*
	Arduino 电压测量模块。使用模拟引脚读出0~1024 范围
	使用LCD显示电压

	!!!!!
	A0 接 +
	GND 接 -


*/

#include "LiquidCrystal.h"

uint8_t analogInputPin = A0;


//模块的两个电阻

float r1 = 30000.0f;
float r2 = 7500.0f;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{

	/* add setup code here */

	pinMode(A0, INPUT);
	//pinMode(13, OUTPUT);
	Serial.begin(9600);
	//lcd.begin(16, 2);
	//lcd.setCursor(0, 0);
	//lcd.clear();
	//lcd.print("hello big shabi");

}

//获取电压
//注意变量的生命周期，出函数之后就没了。跟C#不一样
float getVoltage(float& voltage)
{

	//模拟引脚的数据
	int analogValue = analogRead(analogInputPin);

	//模拟引脚的电压
	float analogVoltage = analogValue * (5.0f / 1023.0f);

	//电流
	float ampere = analogVoltage / r2;


	voltage = (r1 + r2) * ampere;

	return voltage;
}


void loop()
{

	float inputValtage = 0.0f;
	getVoltage(inputValtage);

	lcd.clear();
	lcd.print(inputValtage);
	lcd.print(" V");

	delay(1000);
}

