#include <iostream>
#include "exp.h"

int main()
{
    Expenses exp;
    exp.input_income();
    exp.entry();
    exp.display();
    return 0;
}