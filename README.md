# JVC-Stereo

An arduino library for controlling a JVC Stereo via the Steering Wheel Controls interface

Only tested on my stereo (JVC KW-X840BTS), so YMMV

Pull requests are welcome for other stereos

Example usage:

``` c++
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
```
