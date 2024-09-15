# JVC-Stereo

An arduino library for controlling a JVC Stereo via the Steering Wheel Controls interface

Only tested on my stereo (JVC KW-X840BTS), so YMMV

Pull requests are welcome for other stereos

## Example usage:

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

## Supported commands:
```
JVC_VOLUP
JVC_VOLDN
JVC_SOURCE
JVC_SOUND
JVC_MUTE
JVC_SKIPFWD
JVC_SKIPBACK
JVC_SCANFWD
JVC_SCANBACK
JVC_ANSWER
JVC_DECLINE
JVC_VOICE
```
#### NOTE:

Skip + scan will also answer calls, + will put active calls on hold

Voice will also decline / hang up calls