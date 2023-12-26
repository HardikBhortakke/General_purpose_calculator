#ifndef __continuous_futurevalue_H
#define __continuous_futurevalue_H

#include "components.hpp"

void continuous_future_value()
{
  int no_of_period = 0;
  double principal = 0, rate = 0, rate_period = 0;
  double interest = 0, total = 0;

  display2layermenu("Continuous Compounding", "Future Value");

  principal = GET_NUMBER_DECIMAL("Present Value");

  rate = GET_NUMBER_DECIMAL("Rate")/100;

  rate_period = GET_NUMBER_DECIMAL("Rate Period");

  no_of_period = GET_NUMBER_DECIMAL("No of Periods");

  total = principal * exp((rate / rate_period ) * no_of_period);
  
  interest = total - principal;

  displayresult("Interest", interest);

  displayresult("Future Value", total);
};

#endif