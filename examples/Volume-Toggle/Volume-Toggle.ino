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