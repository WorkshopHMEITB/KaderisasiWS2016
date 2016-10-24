#include <LiquidCrystal.h>

int led1 = 6;
int led2 = 9;
int led3 = 10;
int pushbutton1 = 2;
int pushbutton2 = 3;
int brightness1 = 0;
int brightness2 = -10;
int brightness3 = -20;
int fadeamount1 = 5;
int fadeamount2 = 5;
int fadeamount3 = 5;
int buttonstate1 = 0;
int buttonstate2 = 0;
int buttonstate3 = 0;
int buttonstate4 = 0;
int A = 0;
int B = 0;
int Opr = 0;
int Hasil = 0;
int ulang = 1;
int awal = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (pushbutton1, INPUT);
  pinMode (pushbutton2, INPUT);

  if (awal==1) {
  //menggeser kata ke kiri
  lcd.begin(0, 2);
  lcd.print("WSCalc20160Calculator");
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
  }
  //membaca mulai komputasi
  buttonstate1 = digitalRead (pushbutton1);
  if (buttonstate1 == 1) {
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
  }
  buttonstate1 = 0;

  //membaca nilai a
  buttonstate2 = digitalRead (pushbutton2);
  buttonstate1 = digitalRead (pushbutton1);
  while ((buttonstate2 == 1)&&(buttonstate1 == 0)) {
    A = A+1;
     buttonstate2 = digitalRead (pushbutton2);
     buttonstate1 = digitalRead (pushbutton1);
  }
    digitalWrite (led1, LOW);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, LOW);
  buttonstate1 = 0;

  //membaca nilai b
  buttonstate3 = digitalRead (pushbutton2);
  buttonstate1 = digitalRead (pushbutton1);
  while ((buttonstate3 == 1)&&(buttonstate1 == 0)) {
    B = B+1;
     buttonstate3 = digitalRead (pushbutton2);
     buttonstate1 = digitalRead (pushbutton1);
  }
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, HIGH);
  buttonstate1 = 0;

  //membaca operator
  buttonstate4 = digitalRead (pushbutton2);
  buttonstate1 = digitalRead (pushbutton1);
  while ((buttonstate4 == 1)&&(buttonstate1 == 0)) {
    Opr = Opr+1;
     buttonstate4 = digitalRead (pushbutton2);
     buttonstate1 = digitalRead (pushbutton1);
  } 
  for (ulang; (ulang==3); ulang++) {
    while ((brightness1 >=0)&&(brightness1 <=255)) {
      analogWrite (led1, brightness1);
      brightness1 = brightness1 + fadeamount1;
    }
    while ((brightness2 >=0)&&(brightness2 <=255)) {
      analogWrite (led2, brightness2);
      brightness2 = brightness2 + fadeamount2;
    }
    while ((brightness3 >=0)&&(brightness3 <=255)) {
      analogWrite (led3, brightness3);
      brightness3 = brightness3 + fadeamount3;
    }
    if (brightness1 > 255){
      fadeamount1 = -fadeamount1;
    }
    if (brightness2 > 255){
      fadeamount2 = -fadeamount2;
    }
    if (brightness3 > 255){
      fadeamount3 = -fadeamount3;
    }
    while ((brightness1 >=0)&&(brightness1 <=255)) {
      analogWrite (led1, brightness1);
      brightness1 = brightness1 + fadeamount1;
    }
    while ((brightness2 >=0)&&(brightness2 <=255)) {
      analogWrite (led2, brightness2);
      brightness2 = brightness2 + fadeamount2;
    }
    while ((brightness3 >=0)&&(brightness3 <=255)) {
      analogWrite (led3, brightness3);
      brightness3 = brightness3 + fadeamount3;
    }
  }
  
  //masukan dianggap benar
  if (Opr==1) {
    Hasil = A+B;
  } else if (Opr==2) {
    Hasil = A-B;
  } else if (Opr==3) {
    Hasil = A*B;
  } else {
    Hasil = A/B;
  }

  //menampilkan hasil ke layar
  lcd.begin(16, 2);
  lcd.print(Hasil);

  //mengulang kalkulator
  awal = digitalRead (pushbutton1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  }

  

  

  


