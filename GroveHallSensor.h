#ifndef GroveHallSensor_H
#define GroveHallSensor_H

#include <Arduino.h>
#include <Grove.h>

class GroveHallSensor {
	private:
		unsigned int _pin;
		boolean _state;
		void (*_callback)();
		
	public:
		GroveHallSensor();
		virtual ~GroveHallSensor() {};
		void initialize(GrovePin pins);
		boolean isMagnetNear();
		void activateOnChange(void (*callback)());
		void deactivateOnChange();
};

#endif