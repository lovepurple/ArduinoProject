//Servo.ino
/*
	舵机实验
	1. 舵机是靠PWM脉冲控制旋转的角度
	2. 数字引脚带有~ 表示可输出PWM信号
	3. 舵机一般三个引脚 GND、5V、数字信号
	4. 舵机一个脉冲周期是20ms
		(1) 高电平时间,控制角度
		(2) 低电平时间
	5. 舵机转换角度是0~180
	6. Arduino 里有封闭舵机的库 Servo.h 最多控制8个舵机
	7. 一般舵机不能连续旋转，一般用于机器人的关节
	8. 查看servo.h 可以看到
		#define Min_PULSE_WIDTH 544
		#define MAX_PULSE_WIDTH = 2400 
	*/


int servPin = 9;

void setup()
{
  // put your setup code here, to run once:
  pinMode(servPin, OUTPUT);
  Serial.begin(9600);			//使用串口输入0~9 用于控制舵机旋转的角度
  delay(500);
}

///舵机转换函数
// 一个脉冲周期2ms
void servopulse(int servo,int angle)
{
	int angelMapTopulseWidth = map(angle,0,180,544,2400);		//把角度映射到脉宽时间
	digitalWrite(servo, HIGH);
	delayMicroseconds(angelMapTopulseWidth);
	digitalWrite(servo, LOW);
	delayMicroseconds(20000 - angelMapTopulseWidth);
}


void loop() 
{
	if(Serial.available() > 0)
	{
		int serialInput = Serial.read() - '0';
		if(serialInput > 0 && serialInput <= 9)
		{
			int rotateAngle = map(serialInput,0,9,0,180);

			Serial.print("rotate to angle:");
			Serial.println(rotateAngle);

			//给足够时间转到角度
			for(int i = 0 ; i < 50 ; ++i)
				servopulse(servPin,rotateAngle);
		}
	}
	
}
