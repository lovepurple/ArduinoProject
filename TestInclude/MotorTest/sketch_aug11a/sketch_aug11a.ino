#define motor1pin 4
#define motor1pwm 5
#define  motor2pin 7
#define motor2pwm 6
 
void setup()
{}
void loop()
{
   motor(motor1pin,motor1pwm,1,180);      //电机1以180的速度正转,45口控制电机1
   motor(motor2pin,motor2pwm,1,180);      //电机2以180的速度正转，67口控制电机2
   delay(1000);
   motor(motor1pin,motor1pwm,2,180);      //电机1以180的速度反转
   motor(motor2pin,motor2pwm,2,180);      //电机2以180的速度反转
   delay(1000);
}
void motor(char pin,char pwmpin,char state,int val)//参数pin是输入的高低电平的IO口，pwmpin表示输入的PWM波形的IO口，state指电机状态(正转或反转)，val是调速值大小0-255
{
    pinMode(pin, OUTPUT);    
  if(state==1)                             //当state为1时正转
  {  
    analogWrite(pwmpin,val);
    digitalWrite(pin,1);
   }
  else if(state==2)                     //当state为2时反转
{  
   analogWrite(pwmpin,val);
   digitalWrite(pin,0);
}
else if(state==0)                     //当state为0时停止
{
    analogWrite(pwmpin,0);
    digitalWrite(pin,0);
}
}