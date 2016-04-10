# CNC-Shield-Expansion-Board-V3

Stepper motor control program

#define EN 8 // stepper motor enable, active low 
#define X_DIR 5 // X-axis stepper motor direction control 
#define Y_DIR 6 // y-axis stepper motor direction control 
#define Z_DIR 7 // z-axis stepper motor direction control 
#define X_STP 2 // x-axis stepper control 
#define Y_STP 3 // y-axis stepper control 
#define Z_STP 4 // z-axis stepper control 
/ * 
// Function: step function: stepper motor control direction, the number of steps. 
// Parameters: dir direction control, dirPin corresponding stepper motor DIR pin, stepperPin stepper motor step corresponding pin stepping a few steps steps 
// No return value 
* / 
void step (boolean dir, byte dirPin, byte stepperPin, int steps) 
{
   digitalWrite (dirPin, dir); 
   delay (50); 
   for (int i = 0; i <steps; i ++) {
     digitalWrite (stepperPin, HIGH); 
     delayMicroseconds (800); 
     digitalWrite (stepperPin, LOW); 
     delayMicroseconds (800); 
   } 
} 
void setup () {// The stepper motor used IO pin is set to output 
   pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT); 
   pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT); 
   pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT); 
   pinMode (EN, OUTPUT); 
   digitalWrite (EN, LOW); 
} 
void loop () {
   step (false, X_DIR, X_STP, 200); // X-axis motor reversing a circle, 200 steps for a lap 
   step (false, Y_DIR, Y_STP, 200); // y-axis motor reversal a circle, 200 steps for a lap 
   step (false, Z_DIR, Z_STP, 200); // z-axis motor reversal a circle, 200 steps for a lap 
   delay (1000); 
   step (true, X_DIR, X_STP, 200); // X-axis motor is transferred a circle, 200 steps for a lap 
   step (true, Y_DIR, Y_STP, 200); // y-axis motor is transferred a circle, 200 steps for a lap
   step (true, Z_DIR, Z_STP, 200); // z-axis motor is transferred a circle, 200 steps for a lap
   delay (1000); 

