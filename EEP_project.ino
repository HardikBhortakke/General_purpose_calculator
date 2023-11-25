#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
String str1 = "";
String str2 = ""; 
int result= 0,a = 0,b = 0;
int flag = 0;

void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    //clear screen
    if(key == 'A'){
      lcd.clear();
    }
    //addition
    else if(key == 'B'){
      lcd.print("+");
      flag = 1;
    }
    else if(key == 'D'){
      lcd.clear();
      a = str1.toInt();
      Serial.println("a:");
      Serial.println(a);
      b = str2.toInt();
      Serial.println("b:");
      Serial.println(b);
      result = a+b;
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