#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
 
 lcd.begin(16,2);
 //lcd.print("helo");
}

void loop() {
lcd.setCursor(3,0);
lcd.print("i am tiem");  
delay(1000);
lcd.setCursor(0,1);
lcd.print("Bach khoa Ha Noi");
delay(1000);
}
