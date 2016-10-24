#include <LiquidCrystal.h>
#include <stdlib.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int led1 = 13;
int led2 = 6;
int led3 = 7;
int button1 = 8;
int button2 = 9;
int button3 = 10;
String txtone = "WSCalc 20160 Calculator";
String txttwo = "Made by Kelompok 1";
void setup()
{
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
}
void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  lcd.print(txtone);
  lcd.setCursor(0, 1); //cursor set baris 1 kolom 0
  lcd.print(txttwo);
  lcd.display();
  for (int positionCounter = 0; positionCounter < txtone.length(); positionCounter++)
  {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  lcd.clear();
  while (digitalRead(button1) == LOW) {}//wait input button1
  int A = 0;
  digitalWrite(led1, HIGH);
  delay(2000);

  while (digitalRead(button1) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Masukkan A");
    lcd.setCursor(0, 1);
    lcd.print(A);
    if (digitalRead(button2) == HIGH)
    {
      A += 1;
      while (digitalRead(button2) == HIGH) {}
    }
    if (digitalRead(button3) == HIGH)
    {
      if (digitalRead(button3) > 0)
      {
        A -= 1;
      }
      while (digitalRead(button3) == HIGH) {}
    }
  }
  int B = 0;
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  delay(2000);
  while (digitalRead(button1) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Masukkan B");
    lcd.setCursor(0, 1);
    lcd.print(B);
    if (digitalRead(button2) == HIGH)
    {
      B += 1;
      while (digitalRead(button2) == HIGH) {}
    }
    if (digitalRead(button3) == HIGH)
    {
      if (digitalRead(button3) > 0)
      {
        B -= 1;
      }
      while (digitalRead(button3) == HIGH) {}
    }
  }
  lcd.clear();
  int C = 0;
  char E = '/';
  digitalWrite(led3, HIGH);
  digitalWrite(led2, LOW);
  delay(2000);
  while (digitalRead(button1) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Masukkan C");
    lcd.setCursor(0, 1);
    lcd.print(E);

    if (digitalRead(button2) == HIGH)
    {
      C += 1;
      while (digitalRead(button2) == HIGH) {}
    }
    if (digitalRead(button3) == HIGH)
    {
      if (digitalRead(button3) > 0)
      {
        C -= 1;
      }
      while (digitalRead(button3) == HIGH) {}
    }
    if (C % 4 == 0)
    {
      E = '/' ;
    }
    else if (C % 4 == 1)
    {
      E = '+';
    }
    else if (C % 4 == 2)
    {
      E = '-';
    }
    else if (C % 4 == 3)
    {
      E = '*';
    }
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
  int x = C % 4;
  int result = 0;
  if (x == 0)
  {
    result = A / B ;
  }
  else if (x == 1)
  {
    result = A + B;
  }
  else if (x == 2)
  {
    result = A - B;
  }
  else if (x == 3)
  {
    result = A * B;
  }
  digitalWrite(led3, LOW);
  lcd.print(result);
  delay(5000);
}
