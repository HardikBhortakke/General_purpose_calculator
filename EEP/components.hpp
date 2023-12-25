#ifndef __components_H
#define __components_H

#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

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
int flag = 0;
int mode = 0;
int advanced_mode = 0;

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

void display2layermenu(String message1, String message2)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message1);
  lcd.setCursor(0, 1);
  lcd.print(message2);
  delay(1000);
};

void displayresult(String result1, double result2)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(result1);
  lcd.setCursor(0, 1);
  lcd.print(result2);
  while(true)
  { 
    char key = keypad1.getKey();  // Read the key
    if(key == 'A' || key == '+' || key == '*' || key == '-' || key == '=')
    {
      lcd.clear();
      break;
    }
  } 
};

int GET_NUMBER_DECIMAL(String message)
{
  String numstr = "";
  double number = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);

  while(true)
  {
    char key = keypad1.getKey();  // Read the key

    if (key)
    {
      if(key == 'A' || key == '+' || key == '*' || key == '-')
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(message);
        flag = 0;
        numstr = "";
        number = 0;
      }
      else if(key == '=')
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(message);

        number = numstr.toDouble();
        lcd.setCursor(0, 1);
        lcd.print(number);
        delay(1000);
        break;
      }
      else
      {
        lcd.setCursor(1, 0);
        numstr = numstr + key;
        lcd.print(numstr);
      } 
    }
  }

  return number; 
};

#endif