#include<LiquidCrystal.h>

const int trigPin = 9;         //Declare trigger pin for left sensor
const int echoPin = 7;         //Declare echo pin for left sensor

const int trigPin2 = A0;       //Declare trigger pin for right sensor
const int echoPin2 = A1;       //Declare echo pin for right sensor

const int d1 = 11;
const int d2 = 10;

LiquidCrystal lcd(12, d1, 5, 4, 3, 2);        //Initialize LCD 1
LiquidCrystal lcd2(12, d2, 5, 4, 3, 2);       //Initialize LCD 2


long duration, Leftcm;                        //Variables for measuring distance                      
long duration2, Rightcm;

void setup() {
  lcd.begin(16,2);                            //Begin communication with LCDs
  lcd.clear();
  lcd2.begin(16,2);
  lcd2.clear();
  
  pinMode(trigPin, OUTPUT);                   //Set up sensor pinmodes
  digitalWrite(trigPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trigPin2, OUTPUT);                  //Set up sensor pinmodes
  digitalWrite(trigPin2, HIGH);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.begin(9600); 
}

//Default Eye for left LCD

void eyeL()
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

//Default Eye for right LCD

void eyeR()
{
   byte ON[8] = {
    0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
   byte A[8] = {
    0b00001, 0b00011, 0b00110, 0b01100, 0b11000, 0b10000, 0b10000, 0b10000};
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

  lcd2.createChar(6,ON);                //Create custom characters
  lcd2.createChar(0,A);
  lcd2.createChar(1,B);
  lcd2.createChar(2,C);
  lcd2.createChar(3,D);
  lcd2.createChar(4,E);
  lcd2.createChar(5,F);
  
  lcd2.setCursor(4,0);                  //Print first row
  lcd2.write(byte(0));
  lcd2.setCursor(5,0);
  lcd2.write(byte(2));
  lcd2.setCursor(6,0);
  lcd2.write(byte(2));
  lcd2.setCursor(7,0);
  lcd2.write(byte(6));
  lcd2.setCursor(8,0);
  lcd2.write(byte(6));
  lcd2.setCursor(9,0);
  lcd2.write(byte(6));    
  lcd2.setCursor(10,0);
  lcd2.write(byte(2));
  lcd2.setCursor(11,0);
  lcd2.write(byte(4));
  
  lcd2.setCursor(4,1);                  //Print second row
  lcd2.write(byte(1));
  lcd2.setCursor(5,1);
  lcd2.write(byte(3));
  lcd2.setCursor(6,1);
  lcd2.write(byte(3));
  lcd2.setCursor(7,1);
  lcd2.write(byte(6));
  lcd2.setCursor(8,1);
  lcd2.write(byte(6));
  lcd2.setCursor(9,1);
  lcd2.write(byte(6));    
  lcd2.setCursor(10,1);
  lcd2.write(byte(3));
  lcd2.setCursor(11,1);
  lcd2.write(byte(5));

}

//EyeBall-left for left LCD

void lefteyeL()
{
  byte ON[8] = {
  0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  byte A[8] = {
    0b00001, 0b00011, 0b00111, 0b01111, 0b11111, 0b11111, 0b11111, 0b11111};
  byte B[8] = {
    0b11111,0b11111,0b11111,0b11111,0b01111,0b00111,0b00011,0b00001};
  byte C[8] = {
    0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte D[8] = {
    0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
  byte E[8] = {
    0b10000,0b11000,0b01100,0b00110,0b00011,0b00001,0b00001,0b00001};
  byte F[8] = {
    0b00001,0b00001,0b00001,0b00011,0b00110,0b01100,0b11000,0b10000};

  lcd.createChar(6,ON);              //Create custom characters
  lcd.createChar(0,A);
  lcd.createChar(1,B);
  lcd.createChar(2,C);
  lcd.createChar(3,D);
  lcd.createChar(4,E);
  lcd.createChar(5,F);

  lcd.setCursor(4,0);                //Print first row
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.write(byte(6));
  lcd.setCursor(6,0);
  lcd.write(byte(6));
  lcd.setCursor(7,0);
  lcd.write(byte(2));
  lcd.setCursor(8,0);
  lcd.write(byte(2));
  lcd.setCursor(9,0);
  lcd.write(byte(2));    
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(11,0);
  lcd.write(byte(4));
  
  lcd.setCursor(4,1);                       //Print second row
  lcd.write(byte(1));
  lcd.setCursor(5,1);
  lcd.write(byte(6));
  lcd.setCursor(6,1);
  lcd.write(byte(6));
  lcd.setCursor(7,1);
  lcd.write(byte(3));
  lcd.setCursor(8,1);
  lcd.write(byte(3));
  lcd.setCursor(9,1);
  lcd.write(byte(3));    
  lcd.setCursor(10,1);
  lcd.write(byte(3));
  lcd.setCursor(11,1);
  lcd.write(byte(5));
}

//EyeBall-left for right LCD

void lefteyeR()
{
  byte ON[8] = {
  0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  byte A[8] = {
    0b00001, 0b00011, 0b00111, 0b01111, 0b11111, 0b11111, 0b11111, 0b11111};
  byte B[8] = {
    0b11111,0b11111,0b11111,0b11111,0b01111,0b00111,0b00011,0b00001};
  byte C[8] = {
    0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte D[8] = {
    0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
  byte E[8] = {
    0b10000,0b11000,0b01100,0b00110,0b00011,0b00001,0b00001,0b00001};
  byte F[8] = {
    0b00001,0b00001,0b00001,0b00011,0b00110,0b01100,0b11000,0b10000};

  lcd2.createChar(6,ON);                  //Create custom characters
  lcd2.createChar(0,A);
  lcd2.createChar(1,B);
  lcd2.createChar(2,C);
  lcd2.createChar(3,D);
  lcd2.createChar(4,E);
  lcd2.createChar(5,F);

  lcd2.setCursor(4,0);                    //Print first row
  lcd2.write(byte(0));
  lcd2.setCursor(5,0);
  lcd2.write(byte(6));
  lcd2.setCursor(6,0);
  lcd2.write(byte(6));
  lcd2.setCursor(7,0);
  lcd2.write(byte(2));
  lcd2.setCursor(8,0);
  lcd2.write(byte(2));
  lcd2.setCursor(9,0);
  lcd2.write(byte(2));    
  lcd2.setCursor(10,0);
  lcd2.write(byte(2));
  lcd2.setCursor(11,0);
  lcd2.write(byte(4));
  
  lcd2.setCursor(4,1);                   //Print second row
  lcd2.write(byte(1));
  lcd2.setCursor(5,1);
  lcd2.write(byte(6));
  lcd2.setCursor(6,1);
  lcd2.write(byte(6));
  lcd2.setCursor(7,1);
  lcd2.write(byte(3));
  lcd2.setCursor(8,1);
  lcd2.write(byte(3));
  lcd2.setCursor(9,1);
  lcd2.write(byte(3));    
  lcd2.setCursor(10,1);
  lcd2.write(byte(3));
  lcd2.setCursor(11,1);
  lcd2.write(byte(5));
}

//EyeBall-right for left LCD

void righteyeL()
{
  byte ON[8] = {
  0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  byte A[8] = {
   0b00001, 0b00011,0b00110,0b01100,0b11000,0b10000,0b10000,0b10000};
  byte B[8] = {
    0b10000,0b10000,0b10000,0b11000,0b01100,0b00110,0b00011,0b00001};
  byte C[8] = {
    0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte D[8] = {
    0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
  byte E[8] = {
    0b10000,0b11000,0b11100,0b11110,0b11111,0b11111,0b11111,0b11111};
  byte F[8] = {
    0b11111,0b11111,0b11111,0b11111,0b11110,0b11100,0b11000,0b10000};

  lcd.createChar(6,ON);                   //Create custom characters
  lcd.createChar(0,A);
  lcd.createChar(1,B);
  lcd.createChar(2,C);
  lcd.createChar(3,D);
  lcd.createChar(4,E);
  lcd.createChar(5,F);
  
  lcd.setCursor(4,0);                     //Print first row
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.write(byte(2));
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(7,0);
  lcd.write(byte(2));
  lcd.setCursor(8,0);
  lcd.write(byte(2));
  lcd.setCursor(9,0);
  lcd.write(byte(6));    
  lcd.setCursor(10,0);
  lcd.write(byte(6));
  lcd.setCursor(11,0);
  lcd.write(byte(4));  
  
  lcd.setCursor(4,1);                     //Print second row
  lcd.write(byte(1));
  lcd.setCursor(5,1);
  lcd.write(byte(3));
  lcd.setCursor(6,1);
  lcd.write(byte(3));
  lcd.setCursor(7,1);
  lcd.write(byte(3));
  lcd.setCursor(8,1);
  lcd.write(byte(3));
  lcd.setCursor(9,1);
  lcd.write(byte(6));    
  lcd.setCursor(10,1);
  lcd.write(byte(6));
  lcd.setCursor(11,1);
  lcd.write(byte(5));
  
}

//EyeBall-right for right LCD

void righteyeR()
{
  byte ON[8] = {
  0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
  byte A[8] = {
   0b00001, 0b00011,0b00110,0b01100,0b11000,0b10000,0b10000,0b10000};
  byte B[8] = {
    0b10000,0b10000,0b10000,0b11000,0b01100,0b00110,0b00011,0b00001};
  byte C[8] = {
    0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte D[8] = {
    0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
  byte E[8] = {
    0b10000,0b11000,0b11100,0b11110,0b11111,0b11111,0b11111,0b11111};
  byte F[8] = {
    0b11111,0b11111,0b11111,0b11111,0b11110,0b11100,0b11000,0b10000};

  lcd2.createChar(6,ON);                  //Create custom characters
  lcd2.createChar(0,A);
  lcd2.createChar(1,B);
  lcd2.createChar(2,C);
  lcd2.createChar(3,D);
  lcd2.createChar(4,E);
  lcd2.createChar(5,F);
  
  lcd2.setCursor(4,0);                    //Print first row
  lcd2.write(byte(0));
  lcd2.setCursor(5,0);
  lcd2.write(byte(2));
  lcd2.setCursor(6,0);
  lcd2.write(byte(2));
  lcd2.setCursor(7,0);
  lcd2.write(byte(2));
  lcd2.setCursor(8,0);
  lcd2.write(byte(2));
  lcd2.setCursor(9,0);
  lcd2.write(byte(6));    
  lcd2.setCursor(10,0);
  lcd2.write(byte(6));
  lcd2.setCursor(11,0);
  lcd2.write(byte(4));  
  
  lcd2.setCursor(4,1);                    //Print second row
  lcd2.write(byte(1));
  lcd2.setCursor(5,1);
  lcd2.write(byte(3));
  lcd2.setCursor(6,1);
  lcd2.write(byte(3));
  lcd2.setCursor(7,1);
  lcd2.write(byte(3));
  lcd2.setCursor(8,1);
  lcd2.write(byte(3));
  lcd2.setCursor(9,1);
  lcd2.write(byte(6));    
  lcd2.setCursor(10,1);
  lcd2.write(byte(6));
  lcd2.setCursor(11,1);
  lcd2.write(byte(5)); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  Leftcm = (duration/2) / 29.1;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  // Convert the time into a distance
  Rightcm = (duration2/2) / 29.1;
  
  delay(250);

  if( Leftcm < 100)            //Condition to cheack if anything appears on the left side
  {
    lefteyeL();       //Update left LCD
    lefteyeR();       //Update right LCD
  }  
  else if( Rightcm < 100)      //Condition to cheack if anything appears on the right side
  {
    righteyeL();      //Update left LCD
    righteyeR();      //Update right LCD
  }
  else
  {
    eyeL();           //Update left LCD
    eyeR();           //Update right LCD
  }
  
}
