#ifndef __log_exponent_H
#define __log_exponent_H

#include "components.hpp"

void log_user()
{
  double argument = 0, base = 0, result = 0;

  display2layermenu("Log", "");

  argument = GET_NUMBER_DECIMAL("Enter Argument");

  base = GET_NUMBER_DECIMAL("Enter Base");

  result = log(argument) / log(base);

  displayresult("Log", result);
};

void natural_log()
{
  double argument = 0, result = 0;

  display2layermenu("Natural Log", "");

  argument = GET_NUMBER_DECIMAL("Enter Argument");

  result = log(argument);

  displayresult("Natural Log", result);
};

void decadic_log()
{
  double argument = 0, base = 10, result = 0;

  display2layermenu("Decadic Log", "");

  argument = GET_NUMBER_DECIMAL("Enter Argument");

  result = log(argument) / log(base);

  displayresult("Decadic Log", result);
};

void exponentiation()
{
  double exponent = 0, base = 0, result = 0;

  display2layermenu("Exponentiation", "");

  base = GET_NUMBER_DECIMAL("Enter Base");
  exponent = GET_NUMBER_DECIMAL("Enter Exponent");

  result = pow(base, exponent);

  displayresult("Exponentiation", result);
};

void antilog()
{
  double exponent = 0, base = 0, result = 0;

  display2layermenu("Antilog", "");

  base = GET_NUMBER_DECIMAL("Enter Base");
  exponent = GET_NUMBER_DECIMAL("Enter Exponent");

  result = pow(base, exponent);

  displayresult("Antilog", result);
};

void exponential()
{
  double exponent = 0, result = 0;

  display2layermenu("Exponential", "");

  exponent = GET_NUMBER_DECIMAL("Enter Exponent");

  result = exp(exponent);

  displayresult("Exponential", result);
};

void square()
{
  double exponent = 2, base = 0, result = 0;

  display2layermenu("Square", "");

  base = GET_NUMBER_DECIMAL("Enter Base");

  result = pow(base, exponent);

  displayresult("Square", result);
};

void cube()
{
  double exponent = 3, base = 0, result = 0;

  display2layermenu("Cube", "");

  base = GET_NUMBER_DECIMAL("Enter Base");

  result = pow(base, exponent);

  displayresult("Cube", result);
};

void squareroot()
{
  double number = 0, result = 0;

  display2layermenu("Square-Root", "");

  number = GET_NUMBER_DECIMAL("Enter Number");

  result = sqrt(number);

  displayresult("Square-Root", result);
};

void cuberoot()
{
  double number = 0, result = 0;

  display2layermenu("Cube-Root", "");

  number = GET_NUMBER_DECIMAL("Enter Number");

  result = cbrt(number);

  displayresult("Cube-Root", result);
};

#endif