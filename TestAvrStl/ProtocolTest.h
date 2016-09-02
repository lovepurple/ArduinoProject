// ProtocolTest.h

#ifndef _PROTOCOLTEST_h
#define _PROTOCOLTEST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ProtocolTest :public ProtocolBase
{
public:
	ProtocolTest();
	~ProtocolTest();

	void HandleMessage();

private:

};



#endif

