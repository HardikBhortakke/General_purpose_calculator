#ifndef __incometax_H
#define __incometax_H

#include "components.hpp"

void income_tax()
{
  double income = 0, tax = 0, income_temp = 0;
  int regime = 0;
  String namestr = "INCOME TAX";

  display2layermenu(namestr, "");

  income = GET_NUMBER_DECIMAL("Enter Income");

  display2layermenu("1: Old Tax Regime", "2: New Tax Regime");

  regime = GET_NUMBER_DECIMAL("Enter Regime");
  if (regime == 1)
  {
    if (income <= 250000)
    {
      income_temp = income;
    }
  }
  else if (regime == 2)
  {

  }
  else
  {
    display2layermenu("Invalid Entry", "");
    advanced_mode = 0;
    reset = 2;
  }



  
  //rate = GET_NUMBER_DECIMAL("Enter Rate");

//  result = (a * rate) / 100;
 // total = a + result;

//  displayresult(namestr, result);
 // displayresult("Total", total);
};

#endif