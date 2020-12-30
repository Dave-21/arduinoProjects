#include<Servo.h>

Servo serElbow;
Servo serBaseVer;
Servo serBaseHor;

String serialData;

void setup() {
  // put your setup code here, to run once:
  serBaseHor.attach(9);
  serBaseVer.attach(11);
  serElbow.attach(10);
  
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void serialEvent(){
  serialData = Serial.readString();
  
  //Serial.print(serialData);
  if (serialData.indexOf("X") > -1) {
    serialData.remove(0);
    serBaseHor.write(serialData.toInt());
  }
  else if (serialData.indexOf("Y") > -1) {
    serialData.remove(0);
    serBaseVer.write(serialData.toInt());
  }
  else if (serialData.indexOf("Z") > -1) {
    serialData.remove(0);
    serElbow.write(serialData.toInt());
  }
//  int serLength = serialData.length();
//  for (int i = 0; i <= serLength; i++) {
//    serialData.remove(i);
//  }
  Serial.print(serialData);
  //serElbow.write(parseDataX(serialData));
  //serBaseVer.write(parseDataY(serialData));
  //serBaseHor.write(parseDataZ(serialData));
}
/*
int parseDataX(String data) {
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("Z"));
  data.remove(data.indexOf("X"), 1);
  
  
  
  return data.toInt();
}

int parseDataY(String data) {
  data.remove(data.indexOf("Z"));
  data.remove(data.indexOf("X"), data.indexOf("Y") + 1);
  Serial.print(data);
  //data.remove(0, data.indexOf("Y") + 1);

  return data.toInt();
}
int parseDataZ(String data) {
  data.remove(data.indexOf("X"));
  data.remove(data.indexOf("Y"));
  data.remove(0, data.indexOf("Z") + 1);
    
  return data.toInt();
}
*/
//int parseDataA(String data) {
//  data.remove(0, data.indexOf("Y") + 1);
//
//  return data.toInt();
//}
