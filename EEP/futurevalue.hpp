#ifndef __futurevalue_H
#define __futurevalue_H

#include "components.hpp"

void future_value()
{
  int rate_format = 0, period_format = 0, no_of_period = 0;
  int r = 1, p = 1;
  double principal = 0, rate = 0, period = 0, rate_period = 0;
  double interest = 0, total = 0;

  display2layermenu("Future Value", "");

  display2layermenu("Compounding Period: ", "1: Years");

  display2layermenu("2: Months", "3: Days");

  period_format = round(GET_NUMBER_DECIMAL("Enter Period Format"));

  display2layermenu("Rate Period: ", "1: Years");

  display2layermenu("2: Months", "3: Days");

  rate_format = round(GET_NUMBER_DECIMAL("Enter Period Format"));

  principal = GET_NUMBER_DECIMAL("Present Value");

  rate = GET_NUMBER_DECIMAL("Rate");

  rate_period = GET_NUMBER_DECIMAL("Rate Period");

  no_of_period = round(GET_NUMBER_DECIMAL("No of Periods"));

  period = GET_NUMBER_DECIMAL("Compouding Period");

  if(period_format == 1)
  {
    p = 1;
  }
  else if(period_format == 2)
  {
    p = 12;
  }
  else if(period_format == 3)
  {
    p = 365;
  }

  if(rate_format == 1)
  {
    r = 1;
  }
  else if(rate_format == 2)
  {
    r = 12;
  }
  else if(rate_format == 3)
  {
    r = 365;
  }

  total = principal * pow((1 + (rate / (rate_period * r))), (no_of_period / (period * p)));
  
  interest = total - principal;

  displayresult("Interest", interest);

  displayresult("Future Value", total);
};

#endif