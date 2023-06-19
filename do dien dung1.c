#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

#define analogPinC 1   //analogPin1
#define sac 0   //digitalPin 0
#define xa 1    //digitalPin 1

float RC = 10000;
unsigned long t1, t2, dt;
float microF;

void setup() { 
	lcd.begin(16,2);
    pinMode(sac, OUTPUT); 
    delay(500);
 }
 void loop(){

    digitalWrite(sac,LOW);
    pinMode(xa,OUTPUT); digitalWrite(xa,LOW);
    while (analogRead(analogPinC) >0){
    }
    pinMode(xa,INPUT);

    digitalWrite(sac,HIGH);
    t1=micros();
    while(analogRead(analogPinC) < 512){
    }
    t2=micros();
    dt=t2-t1;
    microF=1000*dt/(693.1471*RC);
	lcd.clear();													
    lcd.setCursor(0, 0);
    lcd.print("   DIEN DUNG ");
    lcd.setCursor(0, 1);
    lcd.print("C= ");
    lcd.print(microF);
	lcd.setCursor(13, 1);
    lcd.print("uF");
    delay(50);


 }