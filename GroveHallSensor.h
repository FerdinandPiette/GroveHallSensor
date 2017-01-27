#ifndef GroveHallSensor_H
#define GroveHallSensor_H

#include <Arduino.h>
#include "../Grove/Grove.h"

class GroveHallSensor {
	private:
		unsigned int _pin;
		boolean _state;
		void (*_callback)();
		
	public:
		GroveHallSensor(GrovePin pins);
		virtual ~GroveHallSensor() {};
		void initialize();
		boolean isMagnetNear();
		void activateOnChange(void (*callback)());
		void deactivateOnChange();
};

#endif