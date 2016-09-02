// MotorDriver.h

#ifndef _MOTORDRIVER_h
#define _MOTORDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct Motor
{
	int motorIndex;
	int inA;
	int inB;
	int pwn;
};

class MotorDriver
{
public:
	MotorDriver(int motorNum);
	
	void addMotor(int motorIndex, int inA, int inB, int pwn);

	void forward();
	void forward(int speed, int delayTime);
	void backward();
	void backward(int speed, int delayTime);
	void turnLeft();
	void turnLeft(int speed, int delayTime);
	void turnRight();
	void turnRight(int speed, int delayTime);
	void stop(int delayTime);

private:
	int speed = 255;

};

#endif

