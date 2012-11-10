#include <CDButton.h>

#define VOLTAGE 5.0
#define ANALOGPIN A0
#define PULLDOWNRES 10000

AnalogButtons buttons(VOLTAGE,PULLDOWNRES,A0);
// default value for voltage is 5V
// default value for Pulldown resistor is 10K
//
//    5V -----[Button]-------- [Resistor] ----------------- ANALOG PIN   --------- [Pulldown Resistor] ------- GROUND
//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 
//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 
//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 

void setup()
{
  Serial.begin(57600);
  
  buttons.onButtonPush=button_onButtonPush;
  buttons.onButtonRelease = button_onButtonRelease;
  buttons.addButton(1,1000);
  buttons.addButton(2,2200);
  buttons.addButton(3,4700);
  buttons.addButton(4,10000);
  buttons.addButton(5,220);
  
}


void loop()
{
  buttons.loop();
}

void button_onButtonPush(byte id)
{
  Serial.print("ON:");
  Serial.println(id,DEC);
  delay(300);
}

void button_onButtonRelease(byte id)
{
  Serial.print("OFF:");
  Serial.println(id,DEC);
}
