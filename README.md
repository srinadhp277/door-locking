# door-locking
A password-based door lock simulated in Proteus 8 using Arduino Uno,  a 4x3 matrix keypad, 16x2 LCD, and a servo motor.

Built and simulated entirely in Proteus 8 Professional without any physical hardware. The schematic uses an Arduino Uno as the controller, a 4x3 matrix keypad for password input, a 16x2 LCD in 4-bit mode for display, and a servo motor to simulate the lock mechanism.The keypad runs on D0–D3 for rows and D4–D6 for columns. The LCD is wired in 4-bit mode across A0–A5 to keep the digital pins free. Servo signal goes to D9. A potentiometer on the LCD contrast pin keeps the display readable during simulation.
The code uses the Keypad.h library for matrix scanning, LiquidCrystal.h for display, and Servo.h for lock actuation. Password logic is handled through a simple FSM — digits build up a string, # submits it, * clears it. Three wrong attempts locks the system for 30 seconds before resetting.
Compiled in Arduino IDE using Sketch → Export Compiled Binary, then loaded the .hex directly into the Arduino component in Proteus to run the simulation.
