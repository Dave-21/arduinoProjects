#include <Stepper.h>

int ENA = 6; 
int ENB = 7;

//int joystick_power = 5; // connect the vcc pin of the joysick
// with pin number 5 of the arduino.  
int vrx = A0; 
int vry = A1; 
int vrx_data = 0; 
int vry_data = 0; 
//int joystick_switch = 4; 
boolean state = false;
int switch_flag = 0; 
int stepper_motor_led = 13; 


 int steps = 4; // you can set to different values, 4, 8, 12,16,20,24,28 and 32
Stepper myStepper(steps, 8, 9, 10, 11);
 
void setup() {
   
  myStepper.setSpeed(100);
  Serial.begin(9600);
  digitalWrite(ENA , LOW); 
  digitalWrite(ENB , LOW); 

  //pinMode(joystick_power , OUTPUT); 
  //digitalWrite(joystick_power, HIGH); 
  pinMode(vrx , INPUT); 
  pinMode(vry, INPUT); 
 // pinMode(joystick_switch , INPUT_PULLUP); 
  pinMode(stepper_motor_led, OUTPUT); 
  digitalWrite(stepper_motor_led, LOW); 
}
 
void loop() {
  
  digitalWrite(ENA , HIGH); 
  digitalWrite(ENB , HIGH); 
  Serial.println("Stepper motor is ActivE"); 
  digitalWrite(stepper_motor_led, HIGH);
  switch_flag = 0; 
  }

void joystick()
{
vrx_data = analogRead(vrx);
Serial.print("Vrx:"); 
Serial.println(vrx_data); 


if ( (vrx_data > 510)  &&   (vrx_data < 1000)   )
{
    digitalWrite(ENA , HIGH); 
  digitalWrite(ENB , HIGH);

  myStepper.setSpeed(20);
  myStepper.step(+1);  
}



if ( vrx_data > 1000   )
{
    digitalWrite(ENA , HIGH); 
  digitalWrite(ENB , HIGH);
  myStepper.setSpeed(700);
  myStepper.step(+1);  
}



// for reverse movement

if ( (vrx_data >= 0)  &&   (vrx_data < 20)   )
{
      digitalWrite(ENA , HIGH); 
  digitalWrite(ENB , HIGH);
  myStepper.setSpeed(700);
  myStepper.step(-1);  
}

if ( (vrx_data > 20)  &&   (vrx_data < 490)   )
{
    digitalWrite(ENA , HIGH); 
  digitalWrite(ENB , HIGH);
  myStepper.setSpeed(50);
  myStepper.step(-1);  
}

}
