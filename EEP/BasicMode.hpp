#ifndef __BasicMode_H
#define __BasicMode_H
#include "components.hpp"

String str1 = "";
String str2 = ""; 
double result= 0,a = 0,b = 0;
int scroll = 0;
char op = '.';

void basic_mode(){
  char key = keypad1.getKey();// Read the key
  
  if((str1.length()+str2.length())>=15){
    //lcd.scrollDisplayRight();
    lcd.autoscroll();
    scroll++;
  }

  // Print if key pressed
  if (key){
    //clear screen
    if(key == '*'){
      key = extra_key(key);
      flag = 1;
    }

    if(key == 'A'){
      lcd.clear();
      lcd.setCursor(0,0);
      while(scroll){
        lcd.scrollDisplayRight();
        scroll--;
      }
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
      //lcd.clear();
      while(scroll){
        lcd.scrollDisplayRight();
        scroll--;
      }
      lcd.setCursor(0,1);
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

#endif