// ProtocolBase.h

#ifndef _PROTOCOLBASE_h
#define _PROTOCOLBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class ProtocolBase
{
public:
	ProtocolBase();
	~ProtocolBase();

	uint8_t GetMessageId() { return messageId; }

	void SetMessageId(const uint8_t msgId) { messageId = msgId; }

	uint32_t GetMessageLength() { return messageLength; }

	void SetMessageLength(const uint32_t msgLength) { messageLength = msgLength; }

	virtual void HandleMessage() = 0;

	virtual void Serialize() = 0;

	virtual void Deserialize(uint8_t* msgBuffer, uint32_t msgLength) = 0;

private:
	uint8_t messageId = 0;
	uint32_t messageLength = 0;
	uint8_t* messageBuffer;

};


#endif

