//RremoteControlServo.ino
/*	
	使用红外控制舵机
	1. 红外库IRremote.h
	2. 使用HEX(十六进制)输出可以发现，当一直按住的时候输出的是FFFF FFFF 也就是输出的是一个int长度
	3. 在 servo.write(0) 的时候 可能出现舵机吱吱响的情况，是因为舵机质量问题，达不到指定的角度，所以需要限制一下舵机角度的范围
*/

#include "IRremote.h"
#include "Servo.h"			//舵机库

#define MIN_ANGLE 10
#define MAX_ANGLE 170

const int REMOTE_RECV_PIN = 11;
const int SERVO_PIN = 3;
const int LED_PIN =8;
const int SERVO_STEP = 10;

int previousRecvValue = 0xFFFFFFFF;

//摇控的红外码
int REMOTE_CODE_KEYS[14] ={0xFFC23D,0xFFE01F,0xFFA857,0xFF9867,0xFF6897,0xFF30CF,0xFF18E7,0x7A85,0x10EF,0xFF38C7,0xFF5AA5,0xFF42BD,0xFF4AB5,0xFF52AD};


IRrecv irrece(REMOTE_RECV_PIN);
decode_results recv_result;

Servo servo;
int servoLastPosition = 1;

void setup() 
{
	pinMode(LED_PIN,OUTPUT);

	//初始化红外
	irrece.enableIRIn();


	Serial.begin(9600);
}


void dump(int recvValue)
{
	switch (recvValue) {
	    case 0xFFC23D:
	      toggleServoStatus();
	      break;
	    case 0xFFE01F:
	    {
	      int nextAngel = getNextAngle(-1);
	      servo.write(nextAngel);
	    }
	      break;
	    case 0xFFA857:
	    {
	      int nextAngle = getNextAngle(1);
	      servo.write(nextAngle);
	    }
	      break;
	    case 0xFF9867:
	      previousRecvValue = 0xFF9867;	//表示上个按键按的100+
	      break;
	    default:
	    {
	    	int angleValue = 0;

	    	int recvAngle = getAngleByCode(recvValue) * SERVO_STEP;

	    	if(previousRecvValue != 0xFFFFFFFF)
	    	{
	    		angleValue = 100 + recvAngle;
	    		if(angleValue > 180)
	    			angleValue = 1;

	    		if(angleValue < 0)
	    			angleValue = 179;

	    		previousRecvValue = 0xFFFFFFFF;
	    	}
	    	else
	    		angleValue = recvAngle;

	    	driveServo(angleValue);
	      
	    }
	    break;
	}
}

int getAngleByCode(int recvCode)
{
	int codeIndex = -1;
	for(int i = 4; i < 14;++i)
	{
		if(REMOTE_CODE_KEYS[i] == recvCode)
			return i - 4;
	}

	return codeIndex;
}

int getNextAngle(int direction)
{
	if(servo.attached())
	{
		int nextValue = 0;
		int currentValue = servo.read();

		nextValue = currentValue + SERVO_STEP * direction;


		if(nextValue < MIN_ANGLE)
			nextValue = MAX_ANGLE;
		else if(nextValue > MAX_ANGLE)
			nextValue = MIN_ANGLE;
		

		return nextValue;
	}

	return -1;
}

void toggleServoStatus()
{
	if(servo.attached())
		servo.detach();
	else
	{
		servo.attach(SERVO_PIN);
		servo.write(MIN_ANGLE);
	}
}

void driveServo(int angle)
{
	if(servo.attached())
	{
		servo.write(angle);
	}
}

void lightLed()
{
	digitalWrite(LED_PIN,HIGH);
	delay(100);	
	digitalWrite(LED_PIN,LOW);
}

void loop() 
{
	
	if(irrece.decode(&recv_result))
	{
		int recvValue = recv_result.value;
		if(recvValue != 0xFFFFFFFF)
		{

			//Serial.println(recv_result.value,HEX);		//print 格式化，HEX表示以16进制输出
			lightLed();

			dump(recvValue);

		}
		irrece.resume();		//接收下一个值 
	
	}
	

}