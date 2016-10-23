
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    const int buttonPin1 = 8;
    const int buttonPin2 = 7;
    int buttonState1 = 0; 
    int buttonState2 = 0;  
    const int ledm = 6;
    const int ledh = 9;
    const int ledb = 10;
   
   int fadeValue = 0;
   int fadeValue2 = 45;
   int fadeValue3 = 105;
   int penambah1 = 15;
   int penambah2 = 15;
   int penambah3 = 15;
   float cacah;
   bool kelar;
     
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledm, OUTPUT);
  pinMode(ledh, OUTPUT);
  pinMode(ledb, OUTPUT);
}

void loop() {
    
    float A = 0;
    float B = 0;
    int C = 0;
    float hasil=0;
  
  buttonState1 = digitalRead(buttonPin1);
  
  
  lcd.setCursor(0, 0);
  lcd.print("WS Calculator016");
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Made by Gabut");

  int positionCounter = 0; 
  while (buttonState1 == LOW) { 
    
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
    buttonState1 = digitalRead(buttonPin1);

//Debugging Button 1
/*    if (buttonState1== HIGH) {
     Serial.println("Ada");
    }
*/  
    positionCounter++;
   if ( positionCounter >= 32) 
    positionCounter = 0;
  }
  
  
  // if it is, the buttonState is HIGH:
 // buttonState1 = digitalRead(buttonPin1);
   digitalWrite(ledm,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Nilai A:");
   delay(500);
   
   do{
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2== HIGH){
    while (buttonState2== HIGH){
    buttonState2 = digitalRead(buttonPin2);}
    A=A+1;
    }
    lcd.setCursor(0,15);
    lcd.print (A);
    } while (buttonState1 == LOW);
      
   digitalWrite(ledh,HIGH);
   digitalWrite(ledm,LOW);
   delay (1500);
//B

   buttonState1 = digitalRead(buttonPin1);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Nilai B:");
   do{
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2== HIGH){
    while (buttonState2== HIGH){
    buttonState2 = digitalRead(buttonPin2);}
    B=B+1;
    }
    lcd.setCursor(0,15);
    lcd.print (B);
    } while (buttonState1 == LOW);
   
   
    
   digitalWrite(ledb,HIGH);
   digitalWrite(ledh,LOW);
   digitalWrite(ledm,LOW);
   delay (1500);

   buttonState1 = digitalRead(buttonPin1);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Tentukan Operator:");
   do{
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2== HIGH){
    while (buttonState2== HIGH){
    buttonState2 = digitalRead(buttonPin2);}
    C=C+1;
    }
    lcd.setCursor(0,15);
    lcd.print (C);
    } while (buttonState1 == LOW);
    delay (1500);

   switch (C) {
    case 1:
     {lcd.clear();
      lcd.print("Penjumlahan:");
      waving();
            lcd.print(A+B);
     break;}
     case 2:
     {lcd.clear();
      lcd.print("Pengurangan:");
      waving();
          
          lcd.print(A-B);
     break;}
     case 3:
     {lcd.clear();
      lcd.print("Perkalian:");
      waving();
          hasil=A*B;
          lcd.println((int)hasil);
     break;}
     case 4:
     {lcd.clear();
      lcd.print("Pembagian:");
      waving();
          hasil=  A/B;
          lcd.println((int)hasil);
     break;}
     default:
     {lcd.clear();
     lcd.print("input salah");
     }
   }
  buttonState1 = digitalRead(buttonPin1);
  do {
    buttonState1 = digitalRead(buttonPin1);
    } while (buttonState1 == LOW);
   
  }
  
void waving(){
   // fade in from min to max in increments of 5 points:

  cacah = millis();
   do {
    analogWrite(ledm, fadeValue);
    analogWrite(ledh, fadeValue2);
    analogWrite(ledb, fadeValue3);
    // wait for 30 milliseconds to see the dimming effect
    fadeValue = fadeValue + penambah1;
    fadeValue2 = fadeValue2 + penambah2;
    fadeValue3 = fadeValue3 + penambah3;
    if ( fadeValue >=254 || fadeValue <1) penambah1 = -penambah1;
    if ( fadeValue2 >254 || fadeValue2 <1) penambah2 = -penambah2;
    if ( fadeValue3 >=254 || fadeValue3 <1) penambah3 = -penambah3;
    delay (50);
    // wait for 30 milliseconds to see the dimming effect
   }while ((cacah+4000)>millis());
    delay(30);
    digitalWrite(ledm, LOW);
    digitalWrite(ledh, LOW);
    digitalWrite(ledb, LOW);
    
}

