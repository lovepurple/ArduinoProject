/*
	Version 1:
		1.配件清单
			a.Arduino Uno
			b.L298N 两块，驱动四个直流电机
			c.降压模块，提供将18650电池组降压到5V，Arduino供电
			d.蓝牙模块
		2.本程序是电机驱动模块使用，作为从机，使用I2C完成两块Arduino通讯
*/

#include "L298N.h"
#include "Wire.h"

/*---------forwardDriver Pin Dedine-----------*/

#define FORWARD_LEFT_ENA 5
#define FORWARD_LEFT_A	 7
#define FORWARD_LEFT_B	 6
#define FOWRARD_RIGHT_ENB 3
#define FORWARD_RIGHT_A 2
#define FORWARD_RIGHT_B 4

/*--------backwardDriver pin define*/
#define BACKWARD_LEFT_ENA 11
#define BACKWARD_LEFT_A   12
#define BACKWARD_LEFT_B	  13
#define BACKWARD_RIGHT_ENB 9
#define BACKWARD_RIGHT_A  8
#define BACKWARD_RIGHT_B  10

L298N forwardDriver(FORWARD_LEFT_ENA, FORWARD_LEFT_A, FORWARD_LEFT_B, FORWARD_RIGHT_A, FORWARD_RIGHT_B, FOWRARD_RIGHT_ENB);
L298N backwardDriver(BACKWARD_LEFT_ENA, BACKWARD_LEFT_A, BACKWARD_LEFT_B, BACKWARD_RIGHT_A, BACKWARD_RIGHT_B, BACKWARD_RIGHT_ENB);

int motorSpeed = 255;
int delayTime = 100;

void moveForward(int speed);
void moveBackward(int speed);
void moveLeft(int speed);
void moveRight(int speed);
void stopMove();

void setup()
{
	Wire.begin(4);
	Wire.onReceive(onReceiveI2CMessage);

}

void onReceiveI2CMessage(int byteCount)
{

}

void loop()
{

	/* add main program code here */
	/*if (Serial.available())
	{
		char serialValue = Serial.read();
		switch (serialValue)
		{
		case 'f':
			moveForward(motorSpeed);
			break;
		case 'b':
			moveBackward(motorSpeed);
			break;
		default:
			stopMove();
			break;
		}
	}
*/
}


void moveForward(int speed)
{
	forwardDriver.forward(speed, delayTime);
	backwardDriver.forward(speed, delayTime);
}

void moveBackward(int speed)
{
	forwardDriver.backward(speed, delayTime);
	//backwardDriver.backward(speed, delayTime);
}

void stopMove()
{
	forwardDriver.full_stop(delayTime);
	//backwardDriver.full_stop(delayTime);
}