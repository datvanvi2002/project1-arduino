// Bai code duoc thuc hien boi sinh vien VI VAN DAT khoa dien -SEEE-HUST
#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 0, 5, 4, 3, 2);
int analogPin=0;
float Vin=5;
float V,R,imgV;
float R1=150;
float R2=1000;
float R3=10000;
float R4=100000;
float R5=1000000;
float q1=9;
float q2=10;
float q3=11;
float q4=12;
float q5=13;
float button1=8;
void setup () {
lcd.begin(16, 2);

pinMode(q1,OUTPUT);
pinMode(q2,OUTPUT);
pinMode(q3,OUTPUT);
pinMode(q4,OUTPUT);
pinMode(q5,OUTPUT);

pinMode(button1,INPUT);

}

void loop() {    
//Bat q1, t?t c?n l?i tat
	digitalWrite(q1,LOW);
    digitalWrite(q2,HIGH);
    digitalWrite(q3,HIGH);
    digitalWrite(q4,HIGH);
    digitalWrite(q5,HIGH);
	imgV= analogRead(analogPin);
//bat dau qua trinh 1 : neu analog thu duoc nho 240 in ra man hinh như duoi

if (imgV <240){
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("    1.Over Load   ");
	delay(1000);
// chuc nang
    if(digitalRead(button1)==HIGH){
     
         V = (imgV*Vin)/1023;										
        R=R1*imgV/(1023-imgV);
        //hien thi
		lcd.clear();													
        lcd.setCursor(0, 0);
        lcd.print("Gia tri dien tro");
        lcd.setCursor(0, 1);
        lcd.print("R= ");
        lcd.print(R);
		lcd.setCursor(13, 1);
        lcd.print("Ohm");
        delay(500);
    }

}else{
    //neu khong thuoc khoang do thi th?c hi?n
    if((imgV>=240) && (imgV<=780)){
        V = (imgV*Vin)/1023;										
        R=R1*imgV/(1023-imgV);
        //hien thi
		lcd.clear();													
        lcd.setCursor(0, 0);
        lcd.print("Gia tri dien tro");
        lcd.setCursor(0, 1);
        lcd.print("R= ");
        lcd.print(R);
		lcd.setCursor(13, 1);
        lcd.print("Ohm");
        delay(500);
    }else{
      //Bat Q2, tat Q1,Q3,Q4,Q5
        digitalWrite(q1,HIGH);
        digitalWrite(q2,LOW);
        digitalWrite(q3,HIGH);
        digitalWrite(q4,HIGH);
        digitalWrite(q5,HIGH);
      //do lai gia tri analog tuong ung voi R m?u m?i là R2
        imgV= analogRead(analogPin);
        //analog không th? đưa ra k?t qu? nh? hơn 240 v? khi analog nh? hơn 240 th? đ? đư?c đo ? quá tr?nh 1
        // khi analog trong kho?ng này th? ti?p t?c th?c hi?n
	    if((imgV>=240) && (imgV<=780)){
            V = (imgV*Vin)/1023;										
            R=R2*imgV/(1023-imgV);		

            lcd.clear();
            lcd.setCursor(0, 0);        
			lcd.print("Gia tri dien tro");
			lcd.setCursor(0, 1);
			lcd.print("R= ");
            lcd.print(R);
			lcd.setCursor(13, 1);
			lcd.print("Ohm");

            delay(500);   
        }else{
        // đây chính là kho?ng analog l?n hơn 780
        //B?t Q3, tat Q1,Q2,Q4,Q5
        digitalWrite(q1,HIGH);
        digitalWrite(q2,HIGH);
        digitalWrite(q3,LOW);
        digitalWrite(q4,HIGH);
        digitalWrite(q5,HIGH);

        //do lai gia tri analog tuong ung voi R m?u m?i là R3
        imgV= analogRead(analogPin);
        if((imgV>=240) && (imgV<=780)){
            V = (imgV*Vin)/1023;										
            R=R3*imgV/(1023-imgV);
			R=R/1000;
			lcd.clear();
            lcd.setCursor(0, 0);
			lcd.print("Gia tri dien tro");
			lcd.setCursor(0, 1);
			lcd.print("R= ");
            lcd.print(R);
			lcd.setCursor(12, 1);
			lcd.print("kOhm");
            delay(500);
        }else{
        //Bat Q4, tat Q1,Q2,Q3,Q5
        digitalWrite(q1,HIGH);
        digitalWrite(q2,HIGH);
        digitalWrite(q3,HIGH);
        digitalWrite(q4,LOW);
        digitalWrite(q5,HIGH);

        //do lai gia tri analog tuong ung voi R m?u m?i R4
        imgV= analogRead(analogPin);
        //tương t? như trên
        if((imgV>=240) && (imgV<=780)){
        V = (imgV*Vin)/1023;										
        R=R4*imgV/(1023-imgV);	
		R=R/1000;
        lcd.clear();
		lcd.setCursor(0, 0);
        lcd.print("Gia tri dien tro");
        lcd.setCursor(0, 1);
        lcd.print("R= ");
        lcd.print(R);
		lcd.setCursor(12, 1);
		lcd.print("kOhm");
        delay(500);
      }else{
        //Bat Q5, tat Q1,Q2,Q4,Q3
        digitalWrite(q1,HIGH);
        digitalWrite(q2,HIGH);
        digitalWrite(q3,HIGH);
        digitalWrite(q4,HIGH);
        digitalWrite(q5,LOW);

      //do lai gia tri analog tuong ung voi R mau moi R5
      imgV= analogRead(analogPin);
      if((imgV>=240) && (imgV<=780)){
        V = (imgV*Vin)/1023;										
        R=R5*imgV/(1023-imgV);
		R=R/1000;
		lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Gia tri dien tro");
        lcd.setCursor(0, 1);
        lcd.print("R= ");
        lcd.print(R);
		lcd.setCursor(12, 1);
		lcd.print("kOhm");
        delay(500);
      }else{
		lcd.clear();
        lcd.print("   Over Load   ");
        delay(100);
      }
        }
      }
    }
  }
  delay(100);
}
}
