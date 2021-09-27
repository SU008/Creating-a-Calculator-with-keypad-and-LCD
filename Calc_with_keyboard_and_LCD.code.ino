#include <stdio.h>
// include the library code:
#include <Keypad.h>
#include <LiquidCrystal.h>

//int Addition(int num1);
int Subtraction(int num1);
int muliplication(int num1);
int Division(int num1);
int num1;
int Ans;
char  key;      


 // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(13, 1, 5, 4, 3, 2);
  



                                                             // Keypad Setup
  const byte ROWS = 4;                                          //four rows
  const byte COLS = 3;                                         //three columns
  char keys[ROWS][COLS] = {
                         {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'},
                         {'#','0','*'}
                          };
  //byte rowPins[ROWS] = {1, 14, 15, 16}; //connect to the row pinouts of the keypad
  //byte colPins[COLS] = {17, 18, 19}; //connect to the column pinouts of the keypad
  byte rowPins[ROWS] = { 12, 10 ,11,9 };
  byte colPins[COLS] = { 8, 7, 6 }; 

  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //keypad setup end


//////////////////setupENDS///////////////////////////////////////////////
void setup()
{
// Serial.begin(9600);
 lcd.begin(16, 2);   
 lcd.setCursor(0,0);    // set up the LCD's number of columns and rows:
 lcd.print("Hello");   // Print a message to the LCD only once.
 delay(2000);
 lcd.clear();
 

}



void loop()
{

  lcd.setCursor(0, 0); // set the cursor to column 0, line 1
  lcd.print("Enter first num:"); //get first number
  lcd.noAutoscroll();
  delay(2000);
  lcd.clear();
  do{
    key = keypad.getKey();                 // scanf("%f",&num1);                       
  }while( key == NO_KEY );
  num1 = key - 48;    // ***convert ASCII value to number 
  lcd.setCursor(0, 1); // set the cursor to column 0, line 
  lcd.print(num1);
  delay(2000);
  lcd.clear();


//lcd.setCursor(0, 1);// lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print("press sign where"); //get symbol
  lcd.setCursor(0, 1);
  lcd.print("(1= +)(2= -)");
  delay(2000);
  lcd.autoscroll();
  //lcd.setCursor(0, 1);
  lcd.print("(3= *)(4= /)");
  lcd.noAutoscroll();
  delay(2000);
  lcd.clear();
  
  do{
   key = keypad.getKey();  
  }while( key == NO_KEY );
  
   if (key == '1')
   {
      Addition(num1);     //go to + function, pass down num1, save to ans
   }

   else if (key == '2')
   {
      Subtraction(num1);    //go to - function, pass down num1, save to ans
    
   }

   else if (key == '3')
   {
      muliplication(num1); //go to function, pass down num1, save ans
      
   }

   else if  (key == '4')
   {
      Division(num1);        //go to function, pass down num1, save ans
     
   }

   else
   {
    lcd.setCursor(0, 1);    // set the cursor to column 0, line 1
    lcd.print("Error");
    delay(2000);
    lcd.clear();
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("1,2,3,4"); // ask user to press a sign, not number
    delay(1000);
    
   }



}


//----------------------------------functions start---------
int Addition(int num1)              //addition function
{
 // float num2;
  //float result;
  lcd.setCursor(0, 0);
  lcd.print("Enter second num:");
  delay(2000);
  lcd.clear();
  int num2;
  int result;
  //-----------------------------
  do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );
  num2 = key - 48;
  //------------------------------
  lcd.setCursor(0, 1);
  lcd.print(num2);
  delay(2000);
  lcd.clear();
  result = num1 + num2;
  delay(2000);
  lcd.print(num1);
  lcd.print(" + ");
  lcd.print(num2);
  lcd.print(" = "); 
  lcd.print(result); //display answer
  delay(2000);
  lcd.clear();
  delay(2000);
  //lcd.setCursor(0, 1);
  //lcd.setCursor(0, 0);
  //lcd.print(num2);
  //lcd.setCursor(0, 1);
  //lcd.print(" = "); 
  //lcd.setCursor(0, 1);
  //lcd.print(result);  //display answer
  //lcd.setCursor(0, 1);
   
 
  
  
  //return result;
}
int Subtraction(int num1)        //subtraction function
{
 //int num2;
 //int result;
 lcd.setCursor(0, 0);
 lcd.print("Enter second num:");
 delay(2000);
 lcd.clear();
  int num2;
 int result;
do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );             //scanf("%f",&num2);
  num2 = key -48;

  lcd.setCursor(0, 1);
  lcd.print(num2);
  delay(2000);
  lcd.clear();
  result = num1 - num2;
  delay(2000);
  lcd.print(num1);
  lcd.print(" - ");
  lcd.print(num2);
  lcd.print(" = ");
 // lcd.print(num2);
 // lcd.print(" = ");
 lcd.print(result); 
 delay(3000);
 lcd.clear();
 delay(2000);

  //return result;
}
int muliplication(int num1)            //multiplication function
{
// int num2;
// int result;
 lcd.setCursor(0, 0);
 lcd.print("Enter second num:");
 delay(2000);
 lcd.clear();
 int num2;
 int result;
  do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );  //scanf("%f",&num2);keypad.getkey();
  num2 = key -48;

  lcd.setCursor(0, 1);
  lcd.print(num2);
  delay(2000);
  lcd.clear();
  result = num1 * num2;
  delay(2000);
  lcd.print(num1);
  lcd.print(" * ");
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(result);
  delay(2000);
  lcd.clear();
  delay(2000);
 
 
}
int Division(int num1)              //division function
{
  // int num2;
  //int result;
  lcd.setCursor(0, 0);
  lcd.print("Enter second num:");
  delay(2000);
  lcd.clear();
  int num2;
  int result;
  do{
    key = keypad.getKey();              //scanf("%f",&num2);
    }while( key == NO_KEY );        
  num2 = key -48;   //keypad.getkey();  scanf("%f",&num2);

  lcd.setCursor(0, 1);
  lcd.print(num2);
  delay(2000);
  lcd.clear();
  result = num1 / num2;;
  delay(2000);
  lcd.print(num1);
  lcd.print(" / ");
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(result);
  delay(2000);
  lcd.clear();
  delay(2000);
    
}




