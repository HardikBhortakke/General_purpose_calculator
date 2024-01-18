#ifndef __continuous_presentvalue_H
#define __continuous_presentvalue_H

#include "components.hpp"

void continuous_present_value()
{
  int no_of_period = 0;
  double future_value = 0, rate = 0, rate_period = 0;
  double interest = 0, present_value = 0, periodic_payment = 0;

  display2layermenu("Continuous Compounding", "Present Value");

  future_value = GET_NUMBER_DECIMAL("Future Value");
  
  rate = GET_NUMBER_DECIMAL("Rate")/100;

  rate_period = GET_NUMBER_DECIMAL("Rate Period");

  no_of_period = GET_NUMBER_DECIMAL("No of Periods");

  present_value = future_value / exp((rate / rate_period) * no_of_period);
  
  interest = future_value - present_value;
  periodic_payment = present_value / (12 * no_of_period) ;

  displayresult("Interest", interest);

  displayresult("Lumsum Present Value", present_value);

  displayresult("Monthly Payment", periodic_payment);
};

#endif