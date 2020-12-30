#include <Servo.h>

Servo serX;
Servo serY;

String inByte;
int pos;

int num;
int num1;
int num2;

void setup() {
  // put your setup code here, to run once:
  serX.attach(10);
  serY.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    //inByte = Serial.readString();
    //pos = inByte.toInt();

    num = Serial.parseInt();
    num1 = num / 1000;
    num2 = num % 1000;
    serX.write(num1);     // move servo
    serY.write(num2);     // move servo
    
  }
}
/*
int parseDataX(String data) {
  //data = data.substring(data.indexOf("X") + 1, data.indexOf("Y"));
  data = data[0];

  return data.toInt();
}

int parseDataY(String data) {
  //data = data.substring(data.indexOf("Y") + 1);
  data = data[1];

  return data.toInt();
}*/
