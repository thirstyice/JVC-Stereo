#include <Arduino.h>

#pragma once

#define JVC_VOLUP 0x04
#define JVC_VOLDN 0x05
#define JVC_SOURCE 0x08
#define JVC_SOUND 0x0D
#define JVC_MUTE 0x0E
#define JVC_SKIPFWD 0x12
#define JVC_SKIPBACK 0x13
#define JVC_SCANFWD 0x14
#define JVC_SCANBACK 0x15
#define JVC_ANSWER 0x18
#define JVC_DECLINE 0x19
#define JVC_VOICE 0x1A
// NOTE: Skip + scan will also answer calls, + will put calls on hold
//       Voice will also decline / hang up calls
//       At least on my stereo. YMMV

class JVCStereo
{
	private:
		uint8_t ctrlPin;

		void sendOne();
		void sendZero();
		void sendByte(byte);
		void sendPreamble();
		void sendPostamble();
public:
	const unsigned int delayLength = 527;
	const int repeat = 3;

	void send(byte command);
	void setup();
	JVCStereo(int pin);
};

