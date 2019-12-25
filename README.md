# Kaleidoscope-LED-ChristmasLights

Turns your keyboard into blinking Christmas lights.

## Using the plugin

* `git clone https://github.com/avonderluft/Kaleidoscope-LED-ChristmasLights` in the Arduino libaries directory
* include the header and select the effect in your sketch
* compile your sketch

```c++
#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LED-ChristmasLights.h>

KALEIDOSCOPE_INIT_PLUGINS(
  LEDControl,
  LEDOff,
  LEDChristmasLights,
  ...
);

void setup() {
  // Optional setting for blink delay in ms.  Default 1000
  LEDChristmasLights.blink_delay = 700;
  
```

## Dependencies

* [Kaleidoscope-LEDControl](https://github.com/keyboardio/Kaleidoscope-LEDControl)

## Acknowledgements

Parts of this code gratefully borrowed from https://github.com/ToyKeeper/Kaleidoscope-LED-Wavepool/

