#include "GroveHallSensor.h"

GroveHallSensor::GroveHallSensor() {
	this->_state = false;
}

void GroveHallSensor::initialize(GrovePin pins) {	
	this->_pin = pins.pin1;
	pinMode(this->_pin, INPUT_PULLUP);
}

boolean GroveHallSensor::isMagnetNear() {
	this->_state = digitalRead(this->_pin);
	return this->_state;
}

void GroveHallSensor::activateOnChange(void(*callback)()) {
	this->_callback = callback;
	attachInterrupt(digitalPinToInterrupt(this->_pin), this->_callback, CHANGE);
}

void GroveHallSensor::deactivateOnChange() {
	detachInterrupt(digitalPinToInterrupt(this->_pin));
}