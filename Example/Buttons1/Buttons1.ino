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



#include <CDButton.h>

#define VOLTAGE 5.0
#define ANALOGPIN A0
#define PULLDOWNRES 10000    // R10K

AnalogButtons buttons(VOLTAGE,PULLDOWNRES,A0);


void setup()
{
  Serial.begin(57600);
  
  buttons.onButtonPush=button_onButtonPush;          // call back when a button pressed passing button id as parameter
  buttons.onButtonRelease = button_onButtonRelease;  // call back when a button released passing button id as parameter
  buttons.addButton(1,1000);   // button id=1 resistor=R1K
  buttons.addButton(2,2200);   // button id=2 resistor=2R2K
  buttons.addButton(3,4700);   // button id=3 resistor=4R7K
  buttons.addButton(4,10000);  // button id=4 resistor=R10K
  buttons.addButton(5,220);    // button id=5 resistor=R100
  
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
