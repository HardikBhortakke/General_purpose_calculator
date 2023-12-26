#ifndef __incometax_H
#define __incometax_H

#include "components.hpp"

void income_tax()
{
  double income = 0, tax = 0;
  int regime = 0;
  String namestr = "INCOME TAX";

  display2layermenu(namestr, "");

  income = GET_NUMBER_DECIMAL("Enter Income");

  display2layermenu("1: Old Tax Regime", "2: New Tax Regime");

  regime = GET_NUMBER_DECIMAL("Enter Regime");

  if (regime == 1)
  {
    double deduction = GET_NUMBER_DECIMAL("Enter Total Deductions");
    income = income - deduction;

    double slab1 = 250000.0;
    double slab2 = 500000.0;
    double slab3 = 1000000.0;

    if (income <= slab1) 
    {
      tax = 0.0;  // No tax for the first slab
    } 
    else if (income <= slab2) 
    {
      tax = 0.05 * (income - slab1);  // 5% tax for the second slab
    } 
    else if (income <= slab3) 
    {
      tax = 0.2 * (income - slab2) + 0.05 * (slab2 - slab1);  // 10% tax for the third slab
    }
    else
    {
      tax = 0.3 * (income - slab3) + 0.2 * (slab3 - slab2) + 0.05 * (slab2 - slab1);  // 10% tax for the third slab
    }
  }
  else if (regime == 2)
  {
    double slab1 = 300000.0;
    double slab2 = 600000.0;
    double slab3 = 900000.0;
    double slab4 = 1200000.0;
    double slab5 = 1500000.0;

    if (income <= slab1) 
    {
      tax = 0.0;  // No tax for the first slab
    } 
    else if (income <= slab2) 
    {
      tax = 0.05 * (income - slab1);  // 5% tax for the second slab
    } 
    else if (income <= slab3) 
    {
      tax = 0.1 * (income - slab2) + 0.05 * (slab2 - slab1);  // 10% tax for the third slab
    } 
    else if (income <= slab4) 
    {
      tax = 0.15 * (income - slab3) + 0.1 * (slab3 - slab2) + 0.05 * (slab2 - slab1);  // 15% tax for the fourth slab
    } 
    else if (income <= slab5) 
    {
      tax = 0.2 * (income - slab4) + 0.15 * (slab4 - slab3) + 0.1 * (slab3 - slab2) + 0.05 * (slab2 - slab1);  // 20% tax for the fifth slab
    } 
    else 
    {
      // Handle cases where income is beyond the highest slab (30% tax)
      tax = 0.3 * (income - slab5) + 0.2 * (slab5 - slab4) + 0.15 * (slab4 - slab3) + 0.1 * (slab3 - slab2) + 0.05 * (slab2 - slab1);
    }
  }
  else
  {
    display2layermenu("Invalid Entry", "");
    advanced_mode = 0;
    reset = 2;
  }

  displayresult(namestr, tax);
};

#endif