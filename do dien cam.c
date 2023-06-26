// Bai code duoc thuc hien boi sinh vien VI VAN DAT khoa dien -SEEE-HUST
#include <LiquidCrystal.h> // Thu vien lcd
  LiquidCrystal lcd(7, 6,5,4,3, 2); //thu tu
  double pulse,pulse1, tanso, cap, diencam, diencam_mH,diencam_uH;
  int relayPin= 0;
void setup(){

	lcd.begin(16,2); //bat man hinh lcd 1602

	pinMode(relayPin, OUTPUT);
	pinMode(11, INPUT); //doc tin hieu cua bo so sanh
	pinMode(13, OUTPUT);//phat tin hieu cho machLC dao dong

}
void loop(){

	digitalWrite(relayPin, LOW);

	digitalWrite(13, HIGH);
	delay(10);                     
	digitalWrite(13, LOW);
	delayMicroseconds(100);        
	pulse = pulseIn(11, HIGH,180000000);  
	lcd.clear();
	

 if(pulse > 0.1){  
	if( pulse <141){	
		cap = 2.E-6; 
		tanso = 1.E6/(2*pulse); 
		diencam = 1/(cap*tanso*tanso*4.*3.14159*3.14159);//F
		diencam_uH=diencam*1.E6;
		
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Gia tri dien cam");

		lcd.setCursor(0, 1); 
		lcd.print(diencam_uH,1);
		lcd.setCursor(14, 1);
		lcd.print("uH");
		delay(500);
	}
	while(pulse>140){
		digitalWrite(relayPin, HIGH);
		digitalWrite(13, HIGH);
		delay(10);                       
		digitalWrite(13, LOW);
		delayMicroseconds(100);         
		pulse1 = pulseIn(11, HIGH,180000000);

		lcd.clear();
		lcd.print(pulse1);delay(1000);
		cap = 2.E-3; 
		tanso = 1.E6/(2*pulse1);
		diencam = 1/(cap*tanso*tanso*4.*3.14159*3.14159); 
		diencam_mH = diencam*1000; 

		lcd.setCursor(0, 0); 
		lcd.clear();
		lcd.print("Gia tri dien cam");

		if(diencam_mH <999){
			lcd.setCursor(0, 1); 
			lcd.print(diencam_mH,1);
			lcd.setCursor(14, 1);
			lcd.print("mH");
			delay(500);
		}else{
			lcd.setCursor(0, 1); 
			lcd.print(diencam,1);
			lcd.setCursor(14, 1);
			lcd.print("H");
			delay(500);
		}
		if(pulse1<4444){
			break;
		}
	}
 }else{
	lcd.print(pulse);
	delay(1000);
	lcd.print(" ERROR ");
 }
}
//update 18-06-2023
