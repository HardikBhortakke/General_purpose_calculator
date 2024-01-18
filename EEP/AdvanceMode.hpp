#ifndef __AdvanceMode_H
#define __AdvanceMode_H

#include "components.hpp"
#include "functions.hpp"

void adv_mode()
{
    reset = 0;
    display2layermenu("Advanced Mode", "");

    if (advanced_mode == 0)
    {
        if (adv_sel == 0)
        {
            display2layermenu("1: Simple Interest", "2: Future Value");
            display2layermenu("3: Present Value", "4: Continuous Future Value");
            display2layermenu("5: Continuous Present Value", "6: Amortized Loan");
            display2layermenu("7: SIP & Mutual Fund", "8: Factorial");
            display2layermenu("9: Permutation", "10: Combination");
            display2layermenu("11: Tax", "12: Discount");
            display2layermenu("13: Income Tax", "");

            adv_sel = 1;
        }


        advanced_mode = GET_NUMBER_DECIMAL("Enter Mode: ");
        reset = 0;
    }

    typedef void (*FunctionPointer)();

    FunctionPointer advanced_functions[] = 
    {
        simple_interest,
        future_value,
        present_value,
        continuous_future_value,
        continuous_present_value,
        amortized_loan,
        mutual_fund,
        factorial_func,
        permutation_func,
        combination_func,
        tax,
        discount,
        income_tax
        //log_user,
        //natural_log,
        //exponentiation,
        //exponential,
        //degreetoradian,
        //radiantodegree,
        //sine_degrees,
        //cosine_degrees,
        //tangent_degrees
    };

    const int num_advanced_functions = sizeof(advanced_functions) / sizeof(advanced_functions[0]);

    if (advanced_mode >= 1 && advanced_mode <= num_advanced_functions) 
    {
        advanced_functions[advanced_mode - 1]();
    } 
    else 
    {
        display2layermenu("Invalid Entry", "");
        advanced_mode = 0;
    }

    advanced_mode = 0;
};

#endif