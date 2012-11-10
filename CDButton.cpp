#include "CDButton.h"
#include "Arduino.h"

AnalogButtons::AnalogButtons(byte p_pin)
{
	voltage = 5.0;
	pulldown = 10000;
	pin = p_pin;
	init();
}

AnalogButtons::AnalogButtons(double p_voltage, unsigned long p_pulldown,byte p_pin)
{
	voltage = p_voltage;
	pulldown = p_pulldown;
	pin = p_pin;
	init();
}
void AnalogButtons::addButton(byte id, unsigned long resistor)
{
	buttons[id].id=id;
	buttons[id].resistor = resistor;
	buttons[id].voltage = voltage * pulldown / (pulldown + resistor);
	buttons[id].voltage = ANALOGMAX * buttons[id].voltage / voltage;
}

void AnalogButtons::loop()
{
   int v = analogRead(pin);
   if (v==0)
   {
	   int p=prev_button;
	   prev_button = 0;
	   if (p)
	   {
		   if (!onButtonRelease==NULL) (onButtonRelease)(p);
	   }
	   return;
   }

   int smallest = 0;
   int comp=ANALOGMAX;
   for (int i=1;i<=MAXBUTTONS;i++)
   {
	   if (buttons[i])
	   {
		   int diff = abs(v-buttons[i].voltage);
		   if (diff<comp)
		   {
			  comp = diff;
			  smallest = buttons[i].id;
		   }
	   }
   }
   if (smallest)
   {
	   if (prev_button != smallest)
	   {
		   prev_button = smallest;
		   if (!onButtonPush==NULL) (onButtonPush)(smallest);
	   }
   }
}
void AnalogButtons::init()
{
	prev_button = 0;
	for (int i=1;i<=MAXBUTTONS;i++)
	{
		buttons[i].id = 0;
		buttons[i].resistor = 0;
		buttons[i].voltage = 0;
	}
}