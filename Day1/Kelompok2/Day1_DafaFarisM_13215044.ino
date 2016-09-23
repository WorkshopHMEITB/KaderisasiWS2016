
//Readme
/*   <Needs checking> = Might be wrong, requires actual circuit.
 *   <Addition>       = Added feature is not a part of the task.
 *   Will be updated after testing.
 */

//Lib
#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Hardware specs
const int butpin[]={6,7};
const int butcount=sizeof(butpin)/sizeof(int);
const int ledpin[]={8,9,10};
const int ledcount=sizeof(ledpin)/sizeof(int);

//Configs
const int operand=2;        //Count of numbers to be operated
int num[operand]={0};       //Zeroing all numbers
const char operators[]={'+','-','x','/'};

//Var
int glbstate=0;   //Designating global state
int calc=0;       //Designating math operation to do
double ans=0;

struct state {
  bool now;
  bool prev;
} butstate[butcount];

void setup() {
  for (int i=0;i<ledcount;i++) pinMode(ledpin[i],OUTPUT);
  lcd.begin(16, 2);                     //Set up the LCD's number of columns and rows:
  
  // Print a message to the LCD.
  lcd.print("WSCalc 20160 Calculator");
  lcd.setCursor(0, 1);                  //Realign cursor to the 1st col and 2nd row
  lcd.print("Made by Kelompok 2");
}

void loop() {
  //Read current button condition
  for (int i=0;i<butcount;i++) butstate[i].now=analogRead(butpin[i]);

  //Button 1
  if ((butstate[0].now == HIGH) != butstate[0].prev) {
    ledoff();
    //Start calculation, Submit 1st number, & Submit 2nd number respectively
    if (glbstate<=2) digitalWrite(ledpin[glbstate],HIGH);

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

  //Button 2
  if ((butstate[1].now == HIGH) != butstate[1].prev) {
    if (glbstate>=1 && glbstate<=2) num[glbstate-1]++;    //Iterate i-th number for every push
    if (glbstate==3) {
      if (calc>=sizeof(operators)/sizeof(int)-1) calc=0;  //Choose math operation. <Addition> Loop if out of boundary
      else calc++;
    }
  }

  if (glbstate>0) displaynum(); //Start displaying numbers and operation after first push of button 1
  
  //Store current button condition for future check
  for (int i=0;i<butcount;i++) butstate[i].prev=butstate[i].now;
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