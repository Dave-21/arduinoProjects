#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

String serialData;

void setup()
{  
    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);
}

void loop()
{
  // DO nothing
}

void serialEvent(){
// Serial events
  serialData = Serial.readString();  

  stepper.runToNewPosition(serialData.toInt());

  Serial.print(serialData);
}
