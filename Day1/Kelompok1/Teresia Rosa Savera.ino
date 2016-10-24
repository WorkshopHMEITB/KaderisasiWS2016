#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int A;
int B;
int C;
int counter;
int led1 = 13;
int led2 = 10;
int led3 = 9;
int but1 = 7;
int but2 = 6;
int but3 = 5;
String text1= "WSCalc 2016 Calculator";
String text2= "Made by Kelompok 1";
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
pinMode (but1, INPUT);
pinMode (but2, INPUT);
pinMode (but3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1, LOW);
digitalWrite (led2, LOW);
digitalWrite(led3,LOW);
lcd.print(text1);
lcd.setCursor(0,1);
lcd.print(text2);
for (int positionCounter = 0; positionCounter < text1.length(); positionCounter++)
  {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
lcd.clear();

while (digitalRead(but1) == LOW)
  {} //gak ngapa2in sampe ditekan
    digitalWrite(led1, HIGH);
    A = 0;
    lcd.setCursor(0,0);
    lcd.print("Masukkan A");
  

while (digitalRead(but1)== LOW)
{
  if (digitalRead(but2)== HIGH)
  {
    A=A+1;
    lcd.setCursor(0,1);
    lcd.print(A);
  }
}
int B=0;
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
//kondisi ini terjadi ketika but1 ditekan

while (digitalRead(but1) == LOW)
{
  lcd.setCursor(0,0);
  lcd.print("Masukkan B");
  lcd.setCursor(0,1);
  lcd.print(B);
  if (digitalRead (but2)==HIGH)
  {
   B=B+1;
  }
}
//terjadi ketika but1 di tekan
lcd.clear();
digitalWrite(led1,LOW);
digitalWrite(led2, LOW);
digitalWrite(led3,HIGH);

counter=0;
while (digitalRead(but1)==LOW)
{
  if (digitalRead(but2)==HIGH)
  {
    counter = counter +1;
   }
}

switch (counter) {
    case 1:
      C =A+B;
      break;
    case 2:
      C=A-B;
      break;
    case 3:
      C=A*B;
      break;
    case 4:
      C=A/B;
    break;
  }
  
 for (int i = 1; i <= 3; i++)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led3, LOW);
    delay(1000);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    delay(1000);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    delay(1000);
  }

digitalWrite(led3, LOW);
lcd.print(C);
delay(5000);

}
