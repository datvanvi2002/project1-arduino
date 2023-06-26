//Duoc thuc hien boi VI VAN DAT - SEE - HUST _2023
//hien thi i2c+lcd
//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>

//LiquidCrystal_I2C lcd(0x27,16,2); 

// hien thi lcd khong co i2c
#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 0, 5, 4, 3, 2);
//RS-1 E-0 D7-2 D6-3 D5-4 D4-5

//khai bao chan
int analogPinC = 1;
int sac1 = 7;
int sac2 = 8;
int sac3 = 9;
int xa=6;
double RC1= 1000; //1kohm
double RC2 = 100000;//100k
double RC3=1000000;;//1M
unsigned long t,dt;
double uF, nF, mF,pF;

void setup(){
    //hien thi i2c + lcd
    //lcd.begin();
    //lcd.backlight();
    //hien thi lcd
    lcd.begin(16,2);
    pinMode(sac2,INPUT);
    pinMode(sac3,INPUT);
    delay(1000);
}
void loop(){
    pinMode(sac1, OUTPUT);
    digitalWrite(sac1, HIGH);
    t = micros(); // bat dau ghi l?i thoi diem sac 
    while (analogRead(analogPinC)<648){
        //cho den khi duoc sac 63,2%
    }
    dt=micros() - t;
    
    digitalWrite(sac1,LOW);
    pinMode(sac1, INPUT);

    //bat dau xa tu
    pinMode(xa, OUTPUT);
    digitalWrite(xa, LOW);
    while (analogRead(analogPinC) >0 ){
        // cho toi khi duoc xa tu hoan toan
    }
    pinMode(xa, INPUT); // dung xa tu

    if( dt > 99990){
        mF=((float)dt/RC1)/1000;
        if(mF > 0.99){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  DIEN DUNG  ");
            lcd.setCursor(0, 1);
            lcd.print("C = ");
            lcd.print(mF);
            lcd.print(" mF");
            delay(500);
        } else{
            uF=mF*1000;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  DIEN DUNG  ");
            lcd.setCursor(0, 1);
            lcd.print("C = ");
            lcd.print(uF);
            lcd.print(" uF");
            delay(500);
        }
        //do tu lon hon 100uF
    }else{
        //neu nho hon 9990, thi khong the do tiep
        //bat dau qua trinh 2 như qua trinh 1 nhung voi dien tro khac
        pinMode(sac2, OUTPUT);
        digitalWrite(sac2, HIGH);
        t = micros();
        while(analogRead(analogPinC)<648){
            // cho duoc sac toi 63,2%
        }
        dt=micros() - t;
        
        digitalWrite(sac2,LOW);
        pinMode(sac2, INPUT);

        //bat dau xa tu
        pinMode(xa, OUTPUT);
        digitalWrite(xa, LOW);
        while (analogRead(analogPinC) >0 ){
        // cho toi khi duoc xa tu hoan toan
        }
        pinMode(xa, INPUT); // dung xa tu

        if( dt > 9990){
            uF=((float)dt/RC2);
            if(uF > 0.9){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("  DIEN DUNG  ");
                lcd.setCursor(0, 1);
                lcd.print("C = ");
                lcd.print(uF,2);
                lcd.print(" uF"); 
                delay(1500);
            }else{
                nF=uF*1000;
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("  DIEN DUNG  ");
                lcd.setCursor(0, 1);
                lcd.print("C = ");
                lcd.print(nF,2);
                lcd.print(" nF"); 
                delay(1500);
            }
            //do tu lơn hon 100nF
        }else{
            pinMode(sac3,OUTPUT);
            digitalWrite(sac3,HIGH);

            t=micros();
            while (analogRead(analogPinC)<648){
            }
            dt=micros()-t;
            
            nF=(((float)dt)/RC3)*1000;
            digitalWrite(sac3,LOW);
            pinMode(sac3,INPUT);
            pinMode(xa,OUTPUT);
            digitalWrite(xa,LOW);

			
				lcd.clear();
				lcd.setCursor(0,0);
				lcd.print("  DIEN DUNG  ");
				lcd.setCursor(0, 1);
				lcd.print("C = ");
				lcd.print(nF,2);
				lcd.print(" nF"); 
				delay(1500);
            while(analogRead(analogPinC)>0){}
            pinMode(xa,INPUT);
        }
        
    }//else 2
}
//update 20-06-2023
