/*******************************************************************************
* Project: JVC-Stereo                                                          *
* Filename: /src/JVC-Stereo.cpp                                                *
*                                                                              *
* Created: 2023-09-08                                                          *
* Author: thirstyice                                                           *
*                                                                              *
* Copyright (c) 2023-2024 Tauran - https://github.com/thirstyice               *
* For details see JVC-Stereo/LICENSE                                           *
*                                                                              *
*******************************************************************************/

#include "JVC-Stereo.h"

void JVCStereo::sendOne() {
	digitalWrite(ctrlPin, HIGH);
	delayMicroseconds(delayLength);
	digitalWrite(ctrlPin, LOW);
	delayMicroseconds(delayLength * 3);
}

void JVCStereo::sendZero() {
	digitalWrite(ctrlPin, HIGH);
	delayMicroseconds(delayLength);
	digitalWrite(ctrlPin, LOW);
	delayMicroseconds(delayLength);
}
void JVCStereo::sendByte(byte byte) {
	for (size_t i = 0; i < 7; i++)
	{
		if ((byte & 1) == 1) {
			sendOne();
		} else {
			sendZero();
		}
		byte = byte >> 1;
	}
}
void JVCStereo::sendPreamble() {
	digitalWrite(ctrlPin, LOW);
	delayMicroseconds(delayLength);
	digitalWrite(ctrlPin, HIGH);
	delayMicroseconds(delayLength * 16);
	digitalWrite(ctrlPin, LOW);
	delayMicroseconds(delayLength * 8);

	sendOne();
	sendByte(0x47); // device code
}

void JVCStereo::sendPostamble() {
	sendOne();
	sendOne();
}

void JVCStereo::send(byte command) {
	for (size_t i = repeat; i>0; i--) {
		sendPreamble();
		sendByte(command);
		sendPostamble();
	}
}
void JVCStereo::setup() {
	pinMode(ctrlPin, OUTPUT);
	digitalWrite(ctrlPin, LOW);
}

JVCStereo::JVCStereo(int pin)
{
	ctrlPin = pin;
}