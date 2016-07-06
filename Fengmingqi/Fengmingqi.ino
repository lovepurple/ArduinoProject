//Fengmingqi.ino
/*
	1. 蜂鸣器实验
	2. while(true)
	{
		 digitalWrite(pin, HIGH);
		 delay(2);
		 digitalWrite(pin, LOW);
	     delay(3);
	}
	
	计算频率：  发声时间：0.002s 不发声时间：0.003s 所以一个周期是 0.005s ,频率是 1 / 0.005 = 200Hz
				如果改成：发声0.003s 不发声0.002s 也是200Hz 效果跟上方一样
				频率大就是超声波？
				频率太小就是次声波？

*/

int pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
 unsigned char i,j;

while(true)
{
	 digitalWrite(pin, HIGH);
	 delay(2);
	 digitalWrite(pin, LOW);
     delay(3);
}
/*
 while(true)
 {
     // statement
     digitalWrite(pin, HIGH);
     delay(1);
     digitalWrite(pin, LOW);
     delay(1);
 }
 */

 //发出另一种声音
 // for(int i = 0 ; i < 10000000; ++i)
 // {
 // 	digitalWrite(pin, HIGH);
 // 	// delay(2000);
 // 	// digitalWrite(pin, LOW);
 // 	// delay(100);
 // }
}
