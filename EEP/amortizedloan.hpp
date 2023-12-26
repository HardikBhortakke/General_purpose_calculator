#ifndef __amortizedloan_H
#define __amortizedloan_H

#include "components.hpp"

void amortized_loan()
{
  int period_format = 0, period = 0, compounding_period = 0;
  double principal = 0, rate = 0;
  double interest = 0, total = 0, periodicpayment = 0;

  display2layermenu("Amortized Loan", "");

  display2layermenu("1: Years", "2: Months");

  period_format = GET_NUMBER_DECIMAL("Enter Period Format");
  if (period_format == 1 || period_format == 2)
  {
  }
  else
  {
    display2layermenu("Invalid Entry", "");
    advanced_mode = 0;
    reset = 2;
  }

  principal = GET_NUMBER_DECIMAL("Principal");

  rate = GET_NUMBER_DECIMAL("Interest Rate per annum")/100;

  period = GET_NUMBER_DECIMAL("Period");

  compounding_period = GET_NUMBER_DECIMAL("Compounding Period");

  if(period_format == 1)
  {
    period = period * compounding_period;
  }
  else if(period_format == 2)
  {
    rate = rate / 12;
  }

  rate = rate / compounding_period;

  periodicpayment = principal * (rate / (1 - pow((1 + rate), -period)));

  total = periodicpayment * period;

  interest = total - principal;

  displayresult("Periodic Payment", periodicpayment);

  displayresult("Interest", interest);

  displayresult("Total", total);
};

#endif