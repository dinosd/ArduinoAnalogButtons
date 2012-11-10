ArduinoAnalogButtons
====================

Library for arduino analog buttons

Installation
1. Create a folder under <arduino home>\libraries named CDButton
2. Copy the contents of the zip file into the above folder

If you are missing digital inputs for buttons then you may need another approach.

USE ANALOG Input with some resistors

Schema for connections

//    5V -----[Button]-------- [Resistor] ----------------- ANALOG PIN   --------- [Pulldown Resistor] ------- GROUND

//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 
//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 
//                                                        | 
//    5V -----[Button]-------- [Resistor] ----------------- 

each button connects 5V to an analog pin thru a resistor.
the analog pin has a pulldown

The library is free for any purpose except criminal actions.

Constantinos Dafalias
cdafalias@gmail.com