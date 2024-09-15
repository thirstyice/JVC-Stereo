/*******************************************************************************
* Project: JVC-Stereo                                                          *
* Filename: /examples/Volume-Toggle/Volume-Toggle.ino                          *
*                                                                              *
* Created: 2023-09-08                                                          *
* Author: thirstyice                                                           *
*                                                                              *
* Copyright (c) 2023-2024 Tauran - https://github.com/thirstyice               *
* For details see JVC-Stereo/LICENSE (if applicable)                           *
*                                                                              *
*******************************************************************************/

#include <JVC-Stereo.h>

#define JVC_PIN 3
JVCStereo JVC(JVC_PIN);

void setup() {
	JVC.setup();
}

void loop() {
	JVC.send(JVC_VOLUP);
	delay(1000);
	JVC.send(JVC_VOLDN);
	delay(1000);
}