#ifndef __AdvanceMode_H
#define __AdvanceMode_H

#include "components.hpp"
#include "simpleinterest.hpp"
#include "futurevalue.hpp"
#include "presentvalue.hpp"


void adv_mode()
{
    display2layermenu("Advanced Mode", "");

    if (adv_mode == 0)
    {
        display2layermenu("1: Simple Interest", "2: Future Value");

        display2layermenu("3: Present Value", "");

        advanced_mode = round(GET_NUMBER_DECIMAL("Enter Mode: "));
    }

    if(advanced_mode == 1)
    {
        simple_interest();
    }
    else if(advanced_mode == 2) 
    {
        future_value();
    }
    else if(advanced_mode == 3) 
    {
        present_value();
    }
};

#endif