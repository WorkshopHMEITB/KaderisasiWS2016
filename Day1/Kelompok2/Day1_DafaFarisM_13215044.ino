
//Readme
/*   <Needs checking> = Might be wrong, requires actual circuit.
 *   <Addition>       = Added feature is not a part of the task.
 *   Will be updated after testing.
 */

//Libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //Connect I2C [UNO A4(SDA), A5(SCL)]

//Set I2C Adress
LiquidCrystal_I2C lcd(0x38);

//Hardware specs
const int backlightpin=13;
const int butpin[]={4,5,6,7,8}; //Button enter, increase, decrease, pointer left, pointer right
const int butcount=sizeof(butpin)/sizeof(int);
const int ledpin[]={9,10,11};
const int ledcount=sizeof(ledpin)/sizeof(int);

//Configs
const int operand=2;        //Count of numbers to be operated
int num[operand]={0};       //Zeroing all numbers
const char operators[]={'+','-','x','/'};
int operatorcnt=sizeof(operators)/sizeof(int);

//Var
int glbstate=0;   //Designating global state
int calc=0;       //Designating math operation to do
int pointer=0;    //Designating number pointer
double ans=0;

struct state {
  bool now;
  bool prev;
} butstate[butcount];

void setup() {
  for (int i=0;i<ledcount;i++) pinMode(ledpin[i],OUTPUT);
  pinMode(backlightpin,OUTPUT);
  for (int i=0;i<butcount;i++) {
    pinMode(butpin[i], INPUT);
    digitalWrite(butpin[i], HIGH);       //Turn on pullup resistors, no additional resistor needed. Remember that 0 means pressed.
  }
  
  lcd.begin(16, 2);                     //Set up the LCD's number of columns and rows
  digitalWrite(backlightpin,HIGH);
  
  // Print a message to the LCD.
  lcd.print("WSCalc 20160 Calculator");
  lcd.setCursor(0, 1);                  //Realign cursor to the 1st col and 2nd row
  lcd.print("Made by Kelompok 2");
}

void loop() {
  //Read current button condition
  for (int i=0;i<butcount;i++) butstate[i].now=!digitalRead(butpin[i]); //Inverse condition since using pullup resistor

  //Button 1 - Enter
  if ((butstate[0].now == HIGH) != butstate[0].prev) {
    ledoff();
    //Start calculation, Submit 1st number, & Submit 2nd number respectively
    if (glbstate<=2) {
      digitalWrite(ledpin[glbstate],HIGH);
      pointer=0;
    }

    //Submit math operation and calculate
    if (glbstate==3) {                        
      loading();
      ans = (double)(                         //Result based on the selection of operation
        (calc==0)*(num[0]+num[1]) + (calc==1)*(num[0]-num[1])+
        (calc==2)*(num[0]*num[1]) + (calc==3)*(num[0]/num[1]));
    }

    //Reset sketch only, not peripherals. But it doesn't matter in this case.
    if (glbstate>3) asm volatile ("  jmp 0");

    //Next global state
    glbstate++;
  }

  int iterate = powf(10,pointer);
  
  //Button 2 - Increase
  if ((butstate[1].now == HIGH) != butstate[1].prev) {
    if (glbstate>=1 && glbstate<=2){
      if (num[glbstate-1] / iterate !=9) num[glbstate-1]+=iterate;    //Iterate the pointer-th digit of i-th number for every push
      else num[glbstate-1]-=9*iterate;                                //Revert the pointer-th digit to zero if it's 9
    }
    if (glbstate==3) {
      if (calc>=operatorcnt-1) calc=0;  //Choose math operation. <Addition> Loop if out of boundary
      else calc++;
    }
  }

  //Button 3 - Decrease
  if ((butstate[1].now == HIGH) != butstate[1].prev) {
    if (glbstate>=1 && glbstate<=2){
      if (num[glbstate-1] / iterate !=0) num[glbstate-1]-=iterate;    //Revert the pointer-th digit of i-th number for every push
      else num[glbstate-1]+=9*iterate;                                //Revert the pointer-th digit to 9 if it's 0
    }
    if (glbstate==3) {
      if (calc<=operatorcnt-1) calc=operatorcnt-1;  //Choose math operation. <Addition> Loop if out of boundary
      else calc--;
    }
  }

  //Button 4 - Pointer left
  if ((butstate[3].now == HIGH) != butstate[3].prev) {
    if (glbstate>=1 && glbstate<=2) pointer++;    //Move the pointer left
  }

  //Button 5 - Pointer right
  if ((butstate[4].now == HIGH) != butstate[3].prev) {
    if (glbstate>=1 && glbstate<=2) pointer--;    //Move the pointer right
  }

  if (pointer<0) pointer=0;


  if (glbstate>0) displaynum(); //Start displaying numbers and operation after first push of button 1
  
  //Store current button condition for future check
  for (int i=0;i<butcount;i++) butstate[i].prev=butstate[i].now;
}

int powf(int num, int power){
  if (power==0) return 1;
  else return num*powf(num,power-1);
}

void displaynum() { //<Addition> Display current numbers and operation symbol in realtime
  /*  Layout:
   *    111111 + 222
   *          111333
   */
  lcd.clear();
  lcd.rightToLeft();
  lcd.print(num[0]);
  lcd.print(' ');
  lcd.print(operators[calc]);
  lcd.print(' ');
  lcd.print(num[1]);
  lcd.setCursor(0,1);           //Second row <Needs checking>
  if (glbstate>=4) lcd.print(ans);;
}

void ledoff() { //Turning off all LEDs
  for (int i=0;i<ledcount;i++) digitalWrite(ledpin[i],LOW);
}

void loading() {  //~1s of fading LEDs
  for (int i=0;i<1000;i++){
    analogWrite( ledpin[0],(int)(255*abs(sin(i))) );    //<Needs checking>
    analogWrite( ledpin[1],(int)(255*abs(sin(i+20))) );
    analogWrite( ledpin[1],(int)(255*abs(sin(i+40))) );
    delay(1);
  }
}
