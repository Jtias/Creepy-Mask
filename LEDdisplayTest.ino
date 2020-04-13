#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
}

void eye()
{
  byte ON[8] = {
    0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  byte A[8] = {
    0b00001,0b00011,0b00110,0b01100,0b11000,0b10000,0b10000,0b10000};
  byte B[8] = {
    0b10000,0b10000,0b10000,0b11000,0b01100,0b00110,0b00011,0b00001};
  byte C[8] = {
    0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte D[8] = {
    0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
  byte E[8] = {
    0b10000,0b11000,0b01100,0b00110,0b00011,0b00001,0b00001,0b00001};
  byte F[8] = {
    0b00001,0b00001,0b00001,0b00011,0b00110,0b01100,0b11000,0b10000};

  lcd.createChar(6,ON);
  lcd.createChar(0,A);
  lcd.createChar(1,B);
  lcd.createChar(2,C);
  lcd.createChar(3,D);
  lcd.createChar(4,E);
  lcd.createChar(5,F);
  
  lcd.setCursor(4,0);
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.write(byte(2));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(7,0);
  lcd.write(byte(6));
  lcd.setCursor(8,0);
  lcd.write(byte(6));
  lcd.setCursor(9,0);
  lcd.write(byte(6));    
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(11,0);
  lcd.write(byte(4));
  
  lcd.setCursor(4,1);
  lcd.write(byte(1));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(3));
  lcd.setCursor(7,1);
  lcd.write(byte(6));
  lcd.setCursor(8,1);
  lcd.write(byte(6));
  lcd.setCursor(9,1);
  lcd.write(byte(6));    
  lcd.setCursor(10,1);
  lcd.write(byte(3));
  lcd.setCursor(11,1);
  lcd.write(byte(5));

}

void loop() {
  // put your main code here, to run repeatedly:
  eye();
}
