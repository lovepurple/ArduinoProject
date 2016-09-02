// MessageHandler.h

#ifndef _MESSAGEHANDLER_h
#define _MESSAGEHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class MessageHandler
{
public:
	MessageHandler();
	~MessageHandler();

	void OnReceiveMessage(uint8_t* messageBuffer, uint32_t bufferSize);

	void HandleMessage(uint8_t* messageBuffer, uint32_t bufferSize);

	void RegisterProtocol(uint8_t protocolId,)

private:

};

#endif

