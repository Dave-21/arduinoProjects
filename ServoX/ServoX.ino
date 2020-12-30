#include <Servo.h>

Servo serX;

String inByte;
int pos;

void setup() {
  // put your setup code here, to run once:
  serX.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    inByte = Serial.readString();
    pos = inByte.toInt();
    
    serX.write(pos);   
  }
}
