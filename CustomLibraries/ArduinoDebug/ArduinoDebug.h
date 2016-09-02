/**
	关于Arduino 串口调试类
*/

#ifndef __ArduinoDebug_H__
#define __ArduinoDebug_H__

class ArduinoDebug
{
public:
	ArduinoDebug();
	~ArduinoDebug();
	
	logDebug(String arg);

};

#endif