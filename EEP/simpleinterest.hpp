#ifndef __simpleinterest_H
#define __simpleinterest_H

#include "components.hpp"

void simple_interest()
{
  int period_format = 0, period = 0;
  double principal = 0, rate = 0;
  double interest = 0, total = 0;

  display2layermenu("Simple Interest", "");

  period_format = GET_FORMAT("Period Format");

  principal = GET_NUMBER_DECIMAL("Principal");

  rate = GET_NUMBER_DECIMAL("Interest Rate");

  period = GET_NUMBER_DECIMAL("Period");

  if(period_format == 1)
  {
    interest = (principal*rate*period)/(100);
  }
  else if(period_format == 2)
  {
    interest = (principal*rate*period)/(12*100);
  }
  else if(period_format == 3)
  {
    interest = (principal*rate*period)/(365*100);
  }

  total = principal + interest;

  displayresult("Interest", interest);

  displayresult("Total", total);
};

#endif