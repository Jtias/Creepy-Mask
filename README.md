# Creepy Mask
CS 207

The project we have decided to do is an Arduino Based Simple mask. We have this project with a view to make a mask that will stare at someone when they come near to it. 
 
Making a mask may look like something silly but when it’s Halloween who doesn’t want a good Halloween decoration? When little children come to our doors we like to amuse them with a good decoration. They will knock on our door and they will notice a mask is following them with creepy eyes.
Again not only on Halloweens, we can keep it in our living room. When our friends will come to our house it will also amuse them. It’s easy to build and fun to see.

1)Here, we're going to use 2 lcd displays to represent the eyes of the machine. The 2 lcds are connected using the common pins except for for pin E. The VSS and VDD pins are connected to GND and 5V on the arduino. D5-D7 are connected to 5,4,3,2 pins on the arduino. Pin 15 and 16 are for the backlight on the lcd display
2) We're going to use 2 ultrasonic sensors to detect objects withing 50 cm radius on either side of the mask. Since we are using just 1 arduino, we did not have many pins left after connecting 2 displays. So, I put the left sensor on digital pin and the right sensor in analog pin. The trigger pin and echo pin on the left sensor is connected to pin 9 and 7 respectively. The trigger pin and echo pin on the right sensor is on A0 and A1.
A reference to the website from where the project is inspired is given below-
[1]Admin. “UltrasonicEyes”. wwww.hackster.io. Apr 10, 2020. https://www.hackster.io/unexpectedmaker/ultrasoniceyes-b9fd38?fbclid=IwAR01xVrsyunEqNDNEEIsTtuwRy_Ue-joNGOw3aGWu-xrGviBm3FIr1kOIdk
