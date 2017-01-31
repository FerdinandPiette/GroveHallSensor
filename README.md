# GroveHallSensor
Hall Sensor Library for Arduino Uno + Grove shield.

[Link to the tested grove module](http://wiki.seeed.cc/Grove-Hall_Sensor/)

##Example
```c++
#include <GroveHallSensor.h>

GroveHallSensor hallSensor;

void setup() {
  hallSensor.initialize(GROVE_D2);
  hallSensor.activateOnChange(stateChange);
  Serial.begin(9200);
}

void loop() {
  delay(500);
}

void stateChange() {
  Serial.println(hallSensor.isMagnetNear() ? "Magnet!!" : "Nothing...");
}
```

##Documentation

###`void initialize(GrovePin pins)`
Initialize the sensor before using it.

Parameters:
- `pins`: Must be a digital socket (GROVE_D2 to GROVE_D8)

###`boolean isMagnetNear()`
Return `true` is a magnet is detected.

###`void activateOnChange(void (*callback)())`
Parameters:
- `callback`: a function pointer that will be automatically executed when a magnet appears or disappears.
This works only if the sensor is pluged on GROVE_D2 or GROVE_D3 (to have access to the interruptions).

###`void deactivateOnChange()`
Stop auto executing the callback when a magnet appears or disappears.