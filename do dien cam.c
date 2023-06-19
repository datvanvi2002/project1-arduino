
#include <Wire.h>
#include <LiquidCrystal.h> // Thu vien lcd
  LiquidCrystal lcd(7, 6,5,4,3, 2); //thu tu
  double pulse, tanso, cap, diencam, diencam_mH;

void setup(){
	lcd.begin(16,2); //bat man hinh lcd 1602
	
	pinMode(11, INPUT); //doc tin hieu cua bo so sanh
	pinMode(13, OUTPUT);//phat tin hieu cho mach LC dao dong

}
void loop(){
	digitalWrite(13, HIGH);
	delay(5);                       //phat tin hieu nap dien cho mach LC trong 5ms sau do dung
	digitalWrite(13, LOW);
	delayMicroseconds(100);         //dung chương trinh trong thoi gian 100 micro giây, de mach LC dao dong on dinh
	pulse = pulseIn(11, HIGH, 5000);  //tra ve thoi gian micro giay de thay doi trang thai L-H 1s=10^6, tra ve 0 neu het thoi gian cho phep
    if(pulse > 0.1){ //neu thoi gian > 0.1
		cap = 2.E-6; // Gia tri dien dung, F 
		tanso = 1.E6/(2*pulse); // tinh tan so 
		diencam = 1/(cap*tanso*tanso*4.*3.14159*3.14159); // tinh dien cam dua tren cong thuc
		diencam=diencam*1.E6;
        diencam_mH = diencam/1000; // đoi sang đơn vi mH
        //LCD hien thi
        lcd.setCursor(0, 0); // Hàng 0, cot 0
        lcd.print("Gia tri dien cam");
        lcd.setCursor(0, 1); //Hàng 1, cot 0
        lcd.print(diencam_mH);
        lcd.setCursor(14, 1);//Hàng 1 cot 14
        lcd.print("mH");
        delay(10);
    }
}
