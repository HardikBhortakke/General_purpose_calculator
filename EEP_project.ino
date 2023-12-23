#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>
//#include<cmath.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys1[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','+'},
  {'7','8','9','-'},
  {'*','0','.','='}
};
char keys2[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','%'},
  {'7','8','9','/'},
  {'*','0','^','D'}
};
byte rowPins[ROWS] = {9, 10, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad1 = Keypad( makeKeymap(keys1), rowPins, colPins, ROWS, COLS );
Keypad keypad2 = Keypad( makeKeymap(keys2), rowPins, colPins, ROWS, COLS );
void setup(){
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
String str1 = "";
String str2 = ""; 
double result= 0,a = 0,b = 0;
int flag = 0;
char op = '.';

char extra_key(char in)
{
  unsigned long currentMillis = millis();
  flag = 0;
  previousMillis = currentMillis;
  char key = keypad2.getKey();// Read the key
  Serial.println(currentMillis);
  while(currentMillis - previousMillis < interval){
    currentMillis = millis();
    //Serial.println(interval);
    key = keypad2.getKey();// Read the key
    if(key){
      flag = 1;
      break;
    }
  }
  if(flag){
    return key;
  }
  else return in;
};
void loop(){
  char key = keypad1.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    //clear screen
    if(key == '*'){
      key = extra_key(key);
      flag = 1;
    }

    if(key == 'A'){
      lcd.clear();
      flag = 0;
      a = 0;
      b = 0;
      str1 = "";
      str2 = "";
    }
    //addition
    else if(key == '+'){
      lcd.print(key);
      op = '+';
      flag = 1;
    }
    //subtraction
    else if(key == '-'){
      lcd.print(key);
      op = '-';
      flag = 1;
    }
    //Multiplication
    else if(key == '*'){
      lcd.print(key);
      op = '*';
      flag = 1;
    }
    //division
    else if(key == '/'){
      lcd.print(key);
      op = '/';
      flag = 1;
    }
    //modulo
    else if(key == '%'){
      lcd.print(key);
      op = '%';
      flag = 1;
    }
    //exponential
    else if(key == '^'){
      lcd.print(key);
      op = '^';
      flag = 1;
    }
    else if(key == '='){
      lcd.clear();
      a = str1.toDouble();
      Serial.println("a:");
      Serial.println(a);
      b = str2.toDouble();
      Serial.println("b:");
      Serial.println(b);
      Serial.println(op);
      if(op=='+'){
        result = a+b;
      }
      else if (op=='-'){
        result = a-b;
      }else if(op=='/'){
        result = a/b;
      }else if(op=='*'){
        result = a*b;
      }else if (op=='%'){
        result = a - (int)(a/b)*b;
      }else if(op=='^'){
        result = pow(a,b);
      }
      lcd.print(result);
      flag = 0;
      a = 0;
      b = 0;
      str1 = "";
      str2 = "";
    }
    else{
      lcd.print(key);
      if(!flag){
        str1 = str1 + key;
        Serial.println(str1);
      }
      else{
        str2 = str2 + key;
        Serial.println(str2);
      }
    } 
  }
}
