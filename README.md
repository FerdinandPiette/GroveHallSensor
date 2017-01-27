# GroveHallSensor
Hall Sensor Library for Arduino Uno + Grove shield.

[Link to the tested grove module](http://wiki.seeed.cc/Grove-Hall_Sensor/)

##Example
```c++
#include <Grove.h>
#include <GroveHallSensor.h>

GroveHallSensor hallSensor(GROVE_D2);

void setup() {
  hallSensor.initialize();
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

###**`GroveHallSensor(GrovePin pins)`**
Parameters :
- pins : Must be a digital socket (GROVE_D2 to GROVE_D8)

###**`void initialize()`**
Initialize the sensor before using it.

###**`boolean isMagnetNear()`**
Return `true` is a magnet is detected.

###**`void activateOnChange(void (*callback)())`**
Parameters :
- callback : a function pointer that will be automatically executed when a magnet appears or disappears.

###**`void deactivateOnChange()`**
Stop auto executing the callback when a magnet appears or disappears.