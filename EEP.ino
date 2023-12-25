#include "components.hpp"
#include "AdvanceMode.hpp"
#include "BasicMode.hpp"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
int mode = 1;
void loop() {
  // put your main code here, to run repeatedly:
  if(mode == 1){
    basic_mode();
  }else adv_mode();
}
