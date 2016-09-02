//StepperMotor.ino
/*
	使用unl2003 驱动板（Arduino 内置）驱动步进电机
	1. 使用unl 2003 直接把步进电机插到驱动板上就可以
	2. 驱动板上使用5v供电
	3. 驱动板上的1，2，3，4引脚接到arduino数字上
	4. Stepper 是步进电机库
	5. 电机是靠PWM(脉冲信号实现转动)
	6. 驱动板供电一定要看好正负极，不行的话找板子对应的资料
*/

#include "Stepper.h"

const int setsPerRevolution = 30;		//转一圈多少步

Stepper stepper(setsPerRevolution,8,9,10,11);


void setup()
{
	stepper.setSpeed(60);  //60转/min
}

void loop() 
{
	//顺时针转一圈
	stepper.step(2048);
  	delay(500);
/*
  	//反转一圈
  	stepper.step(-setsPerRevolution);
  	delay(500);
*/
}
