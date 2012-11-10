ArduinoAnalogButtons
====================

Library for arduino analog buttons

Purpose<br>
I made a few things with arduino and in some cases I was missing pins just for buttons. 
I googled and I found some solutions with very similar implementation.
I decided to make my own because ....

My first approach is to be object oriented.
The second approach is to turn arduino to event driven programming. I really want the void loop() clear with no logic
inside.

Theory<br>
This schematic is simply a voltage divider. The library calculates the value should the analog pin have, based on the 
input voltage and the resistor values. When you call the addButton the calculation is done and stored in the appropriate
object.

The loop function reads the analog port and finds which voltage divider is closer to that value.
That means that you can not detect (at the moment) multiple buttons.

Future<br>
My purpose is to add some extra features. But I will add them as soon as I have the need.
1. Duration of the press, detectable at onButtonRelease event. This event will be backword compatible.
2. Timeout value and event. In case of LCDs you may need to do something but after a specified amount of seconds your
sketch must go back to the default LCD layout.
So
1. A new property timeout_seconds will be added to main object.
2. A new event onTimeout(int seconds) will be fired at your sketch when your last keypress happened more than 
timeout_seconds ago.

Installation<br>
1. Create a folder under <arduino home>\libraries named CDButton
2. Copy the contents of the zip file into the above folder


Schema for connections<br>

//    5V -----[Button]-------- [Resistor] ----------------- ANALOG PIN   --------- [Pulldown Resistor] ------- GROUND<br>
//                                                        | <br>
//    5V -----[Button]-------- [Resistor] ----------------- <br>
//                                                        | <br>
//    5V -----[Button]-------- [Resistor] ----------------- <br>
//                                                        | <br>
//    5V -----[Button]-------- [Resistor] ----------------- <br>

each button connects 5V to an analog pin thru a resistor.
the analog pin has a pulldown

The library is free for any purpose except criminal actions.<br>

Constantinos Dafalias
cdafalias@gmail.com