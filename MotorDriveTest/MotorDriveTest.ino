/*
	L293D 电机驱动板
		驱动马达
*/

#include "AFMotor.h"

AF_DCMotor motor(1);

void moveForward(void);
void moveBackward(void);
void stopMove(void);

void setup() {
	Serial.begin(9600);           // set up Serial library at 9600 bps

	motor.run(RELEASE);
}

void loop()
{
	motor.setSpeed(200);
	motor.run(BACKWARD);

	/*
	if (Serial.available() > 0)
	{
		int code = Serial.read();

		Serial.print(code);

		switch (code)
		{
		case 'F':
			moveForward();
			break;
		case 'B':
			moveBackward();
			break;
		case 'L':
			break;
		case 'R':
			break;
		default:
			stopMove();
			break;
		}
	}
	*/
}

void moveForward()
{
	motor.run(FORWARD);
	motor.setSpeed(255);

}

void moveBackward()
{
	motor.run(BACKWARD);
	motor.setSpeed(255);
}

void stopMove()
{
	motor.run(RELEASE);
}