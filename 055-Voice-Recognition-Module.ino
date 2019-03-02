#include <Servo.h>
byte speech = 0;
Servo myServo;
int rLed = 13;
int gLed = 12;
int yLed = 11;

void setup() {
  
Serial.begin(9600);
myServo.attach(10); //motor pin
myServo.write(0);
pinMode(rLed,OUTPUT);
pinMode(gLed,OUTPUT);
pinMode(yLed,OUTPUT);

delay(1000);
Serial.write(0xAA);
Serial.write(0x37); // start recognization

delay(1000);

Serial.write(0xAA); 
Serial.write(0x21);// get speech code
}

void loop() {

  while(Serial.available()) {

  speech = Serial.read();

  switch(speech) {

      case 0x11:   //command 1 is for Red LED 
      digitalWrite(rLed, HIGH);
      break;

      case 0x12:  //command 2 is for Green LED
      digitalWrite(gLed, HIGH);
      break;

      case 0x13:  //command 3 is for Yellow LED
      digitalWrite(yLed, HIGH);
      break;

      case 0x14:  //command 4 is for Servo motor
      myServo.write(180);
      break;

      case 0x15:  //command 5 is for Servo Motor
      myServo.write(0);
      break;

            }
      }
}
