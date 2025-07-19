//include the servo library

#include <Servo.h>

Servo servo1;
int position = 90;
int tolerance = 50;
int lightValue1 = A0;
int lightValue2 = A1;
void setup() { // put your setup code here, to run once:
Serial.begin(9600);
 servo1.attach(9); 
 pinMode(lightValue1, INPUT);
 pinMode(lightValue2, INPUT);
 delay(2000);
 
 }

void loop() { // put your main code here, to run repeatedly:

int Value1 = analogRead(A0);
int Value2 = analogRead(A1);
float solarReading = (analogRead(A2) * 5) /1023;
float volt1 = (Value1 * 5)/ 1023;
float volt2 = (Value2 * 5)/ 1023;
Serial.print("Value1: ");
Serial.println(Value1);
Serial.print("Value2: ");
Serial.println(Value2);

 int lightValue = Value1 - Value2;
 int lightValue1 = Value2 - Value1;
  Serial.println(lightValue);
  if((abs(lightValue) <= tolerance) || (abs(lightValue1) <= tolerance)){
    Serial.println("Within Tolerance.");
  }
  else{
    if(Value1 < Value2){
    position = position + 3;
    }
    if(Value1 > Value2){
    position = position - 3;
  }
  }
  if(position > 150){position = 150;}
  if(position < 30){ position = 30;}
  Serial.println(position);
   servo1.write(position);
   
 }