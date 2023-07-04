// Bai code duoc thuc hien boi sinh vien VI VAN DAT khoa dien -SEEE-HUST
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  //hoac 0x3F
int analogPin = 0;
float Vin = 5;
float V, R, imgV;
float R1 = 200;
float R2 = 1000;
float R3 = 10000;
float R4 = 100000;

float q1 = 10;
float q2 = 11;
float q3 = 12;
float q4 = 13;

float button1 = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(q1, OUTPUT);
  pinMode(q2, OUTPUT);
  pinMode(q3, OUTPUT);
  pinMode(q4, OUTPUT);
}

void loop() {
  //Bat Q1, con lai tat
  digitalWrite(q1, LOW);
  digitalWrite(q2, HIGH);
  digitalWrite(q3, HIGH);
  digitalWrite(q4, HIGH);

  imgV = analogRead(analogPin);
  //bat dau qua trinh 1 : neu analog thu duoc nho 240 in ra man hinh như duoi

  if (imgV < 240) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Over Load 1   ");
    delay(1000);
    // chuc nang
    if (digitalRead(button1) == HIGH) {
      V = (imgV * Vin) / 1023;
      R = R1 * imgV / (1023 - imgV);
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

  } else {
    //neu khong thuoc khoang do thi thuc hien
    if ((imgV >= 240) && (imgV <= 670)) {
      V = (imgV * Vin) / 1023;
      R = R1 * imgV / (1023 - imgV);
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
    } else {
      //Bat Q2, tat Q1,Q3,Q4,Q5
      digitalWrite(q1, HIGH);
      digitalWrite(q2, LOW);
      digitalWrite(q3, HIGH);
      digitalWrite(q4, HIGH);

      //do lai gia tri analog tuong ung voi R m?u m?i là R2
      imgV = analogRead(analogPin);
      //analog khong the dua ra ket qua nho hon 240 vi imgV=<240 da duoc do o qua trinh 1
      // khi analog trong khoang  240-780 thi next
      if ((imgV >= 240) && (imgV <= 780)) {
        V = (imgV * Vin) / 1023;
        R = R2 * imgV / (1023 - imgV);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Gia tri dien tro");
        lcd.setCursor(0, 1);
        lcd.print("R= ");
        lcd.print(R);
        lcd.setCursor(13, 1);
        lcd.print("Ohm");

        delay(500);
      } else {
        // đây chính là khoang analog lon hơn 780
        //Bat Q3, tat Q1,Q2,Q4,Q5
        digitalWrite(q1, HIGH);
        digitalWrite(q2, HIGH);
        digitalWrite(q3, LOW);
        digitalWrite(q4, HIGH);


        //do lai gia tri analog tuong ung voi R ref moi là R3
        imgV = analogRead(analogPin);
        if ((imgV >= 240) && (imgV <= 780)) {
          V = (imgV * Vin) / 1023;
          R = R3 * imgV / (1023 - imgV);
          R = R / 1000;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Gia tri dien tro");
          lcd.setCursor(0, 1);
          lcd.print("R= ");
          lcd.print(R);
          lcd.setCursor(12, 1);
          lcd.print("kOhm");
          delay(500);
        } else {
          //Bat Q4, tat Q1,Q2,Q3,Q5
          digitalWrite(q1, HIGH);
          digitalWrite(q2, HIGH);
          digitalWrite(q3, HIGH);
          digitalWrite(q4, LOW);


          //do lai gia tri analog tuong ung voi R ref moi  la  R4
          imgV = analogRead(analogPin);
          //tương tu như trên
          if ((imgV >= 240) && (imgV <= 990)) {  //8.2%
            V = (imgV * Vin) / 1023;
            R = R4 * imgV / (1023 - imgV);
            R = R / 1000;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Gia tri dien tro");
            lcd.setCursor(0, 1);
            lcd.print("R= ");
            lcd.print(R);
            lcd.setCursor(12, 1);
            lcd.print("kOhm");
            delay(500);
          } else {
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
