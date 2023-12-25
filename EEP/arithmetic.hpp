#ifndef __arithmetic_H
#define __arithmetic_H

#include "components.hpp"

void addition()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Addition";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Augend");

  b = GET_NUMBER_DECIMAL("Enter Addend");

  result = a + b;

  displayresult(namestr, result);
};

void subtraction()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Subtraction";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Minuend");

  b = GET_NUMBER_DECIMAL("Enter Subtrahend");

  result = a - b;

  displayresult(namestr, result);
};

void multiplication()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Multiplication";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Multiplicand");

  b = GET_NUMBER_DECIMAL("Enter Multiplier");

  result = a * b;

  displayresult(namestr, result);
};

void division()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Division";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Dividend");

  b = GET_NUMBER_DECIMAL("Enter Divisor");

  if (b == 0)
  {
    b = 1;
  }
  result = a / b;

  displayresult(namestr, result);
};

void rounding()
{
  double a = 0; 
  int result = 0;
  String namestr = "Rounding";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Number");

  result = round(a);

  displayresult(namestr, result);
};

void flooring()
{
  double a = 0;
  int result = 0;
  String namestr = "Floor";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Number");

  result = floor(a);

  displayresult(namestr, result);
};

void ceiling()
{
  double a = 0;
  int result = 0;
  String namestr = "Ceiling";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Number");

  result = ceil(a);

  displayresult(namestr, result);
};

void ratio()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Ratio";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Dividend");

  b = GET_NUMBER_DECIMAL("Enter Divisor");

  if (b == 0)
  {
    b = 1;
  }
  result = a / b;

  displayresult(namestr, result);
};

void percentage()
{
  double a = 0, b = 0, result = 0;
  String namestr = "Percentage";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Dividend");

  b = GET_NUMBER_DECIMAL("Enter Divisor");

  if (b == 0)
  {
    b = 1;
  }
  result = a / b;

  displayresult("Percentage Ratio", result);
  displayresult(namestr, result*100);
};

void tax()
{
  double a = 0, rate = 0, result = 0, total = 0;
  String namestr = "TAX";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Value");

  rate = GET_NUMBER_DECIMAL("Enter Rate");

  result = (a * rate) / 100;
  total = a + result;

  displayresult(namestr, result);
  displayresult("Total", total);
};

void discount()
{
  double a = 0, rate = 0, result = 0, total = 0;
  String namestr = "Discount";

  display2layermenu(namestr, "");

  a = GET_NUMBER_DECIMAL("Enter Value");

  rate = GET_NUMBER_DECIMAL("Enter Rate");

  result = (a * rate) / 100;
  total = a - result;

  displayresult(namestr, result);
  displayresult("Total", total);
};

#endif