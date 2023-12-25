#include "components.hpp"
#include "AdvanceMode.hpp"
#include "BasicMode.hpp"

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

int mode = 1;

void loop() 
{
  // put your main code here, to run repeatedly:
  if (mode == 0)
  {
    display2layermenu("GPC INITIALIZED", "     HI :)     ");

    display2layermenu("MODES:", "");

    display2layermenu("1: Basic", "2: Advanced");

    mode = round(GET_NUMBER_DECIMAL("Enter Mode: "));

  }

  if(mode == 1)
  {
    basic_mode();
  }
  else if(mode == 2 ) 
  {
    adv_mode();
  }
}
