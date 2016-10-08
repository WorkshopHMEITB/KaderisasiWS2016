// Tugas WS 2 - Membuat Kalkultor Sederhana

#include <LiquidCrystal.h>

int power = 0;
float A = 0;
float B = 0;
int operasi = 0;
float hasil = 0;
int M = 0;
int M1 = 10;
int K = 160;
int K1 = 10;
int H = 80;
int H1 = 10;
int waktu = 0;

LiquidCrystal lcd(12,11,4,5,6,7);

void setup() {

  lcd.begin(16,2);
 
  pinMode(2, INPUT);
  pinMode(13, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  // untuk satu display 1 berikut perintahnya
  if (digitalRead(2) ==  1) { 
    power = power + 1;
    while (digitalRead(2) == 1);
  }
  
  if (power == 0){
      lcd.clear();
      
      char kata[16] = "WS Calculator";
      String perintah = "";
 
      for (int pos=0; pos<(strlen(kata)); pos++){ 
          perintah = perintah + kata[pos];
          lcd.clear();
          lcd.print(perintah);
      
          if (digitalRead(2) ==  1) { 
          power = power + 1;
          while (digitalRead(2) == 1);
           }
      delay(100);
      }

      lcd.clear();
      char kata1[17] = "Kelompok 1 ^_^";
      String perintah1 = "";
 
      for (int pos=0; pos<(strlen(kata1)); pos++){ 
          perintah1 = perintah1 + kata1[pos];
          
          lcd.clear();
          lcd.print(perintah);
          lcd.setCursor(0,1);
          lcd.print(perintah1);
          
          if (digitalRead(2) ==  1) { 
          power = power + 1;
          while (digitalRead(2) == 1);
           }
          
          delay(100);
      }
      
      if (digitalRead(2) ==  1) { 
      power = power + 1;
      while (digitalRead(2) == 1);
       }
      delay(1000);
  }
  else if (power == 1) {
      if (digitalRead(13) ==  1) { 
          A = A + 1;
          while (digitalRead(13) == 1);
      }
      
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10,LOW);
      
      lcd.clear();
      lcd.print(A);
      delay(10);
      }
    
      if (power == 2) {
      if (digitalRead(13) ==  1) { 
          B = B + 1;
          while (digitalRead(13) == 1);
      }
      
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(10,LOW);
      lcd.clear();
      lcd.print(B);   
      delay(10);
      }

      if (power == 3) {
      if (digitalRead(13) ==  1) {
          operasi = operasi + 1;
          while (digitalRead(13) == 1);
      }
      
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9,LOW);
    
    if (operasi == 0){
      lcd.clear();
      lcd.print("Masukan Operasi");
      delay(10);
    } 
    else if (operasi == 1) {
      lcd.clear();
      lcd.print("Tambah");
      delay(10);
    } 
    else if (operasi == 2) {
      lcd.clear();
      lcd.print("Kurang");
      delay(10);
    } 
    else if (operasi == 3) {
      lcd.clear();
      lcd.print("Kali");
      delay(10);
    } 
    else if (operasi == 4) {
      lcd.clear();
      lcd.print("Bagi");
      delay(10);
    } 
    else if (operasi > 4) {
      operasi = 1;    
    }
  }
  if (power == 4) {
    if (operasi == 1) {
      hasil = A + B;
    } 
    else if (operasi == 2) {
      hasil = A - B;
    } 
    else if (operasi == 3) {
      hasil = A * B;
    } 
    else if (operasi == 4) {
      hasil = A / B;
    }
    while (waktu < 800){
    M = M + M1;
   
    H = H + H1;
    
    K = K + K1;
    if (M > 230 || M < 0) {
      M1 = -M1;
    }
     if (H > 230 || H < 0) {
      H1 = -H1;
    }
    if (K > 230 || K < 0) {
      K1 = -K1;
    }
    analogWrite(8,M);
    analogWrite(9,H);
    analogWrite(10,K);
    lcd.clear();
    lcd.print("loading");
    delay(5);
    waktu = waktu + 1;
    }

    lcd.clear();
    lcd.print(hasil);
    
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10,LOW);
    delay(20);
  }
  if (power > 4) {
    power = 0;
    A = 0;
    operasi = 0;
    B = 0;
    waktu = 0;
  }
  }
