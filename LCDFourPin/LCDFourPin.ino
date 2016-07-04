//LCDFourPin.ino

/*
	4 pin 的led实验

	1. D4~D7 分别接数字信号 5 4 3 2
	2. A- 背光正极 3.3V  K-背光接地
	3. E- ledEnable 接数字pin 11
	4. RW 接地
	5. RS 接数字 pin 12
	6. V0 调节对比度，接电位器，用于调节对比度
	7. VDD LED正极，接5V
	8. VSS 接地

	lcd.print() lcd.write()区别 ：print() 转换成了ASC II ，write()直接输出的数字
*/

//使用LED驱动库LiquidCrystal
#include "LiquidCrystal.h"

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
	lcd.begin(16,2);		//每行16个字符，一共两行
	//lcd.print("Hell Arduino!!!");

	//串口写入
	Serial.begin(9600);

}

void loop() {

	if(Serial.available())
	{	
		//等一会
		delay(500);

		lcd.clear();
		
		lcd.setCursor(0,0);
		lcd.autoscroll();
		while(Serial.available() > 0){
		    // statement
		    //lcd.write(Serial.read());
			char chInput = Serial.read();
			lcd.print(chInput);
		}

	}
/*
  lcd.blink();
  lcd.setCursor(5,1);		//设置光标的位置也就是下个字符从哪开始
  lcd.print(millis() / 1000);
*/
}
