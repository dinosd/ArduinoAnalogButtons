#include "Arduino.h"
#ifndef CDButton_h
#define CDButton_h

#define MAXBUTTONS 8
#define ANALOGMAX 1023

typedef void (*delegate_onButtonPress)(byte);


struct Button
{
	byte id;
	unsigned long resistor;
	double voltage;
};


class AnalogButtons
{
public:
	delegate_onButtonPress onButtonPush;
	delegate_onButtonPress onButtonRelease;
	Button buttons[MAXBUTTONS+1];
	double voltage;
	double pulldown;
	byte pin;
	byte prev_button;
	AnalogButtons(double p_voltage, unsigned long p_pulldown,byte p_pin);
	AnalogButtons(byte p_pin);
	void addButton(byte id, unsigned long resistor);
	void loop();
private:
	void init();
};

#endif