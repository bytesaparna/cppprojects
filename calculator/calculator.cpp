#include <iostream>
#include "calculator.h"
using namespace CALCULATOR;

double Calculator::input_num(std::string output, double *num_ptr)
{
    std::cout << "Enter " << output << " number : ";
    std::cin >> *num_ptr;
    this->history[this->num_history % MAX_HISTORY] = *num_ptr;
    this->num_history++;
    return *num_ptr;
}

void Calculator::input_first_num()
{
    this->input_num("First", &first_num);
}
void Calculator::input_second_num()
{
    this->input_num("Second", &second_num);
}

double Calculator::get_first_num()
{
    return first_num;
}

double Calculator::get_second_num()
{
    return second_num;
}
void Calculator::input_operation()
{
    std::cout << "Press required Operation : ";
    std::cin >> operation;
}
char Calculator::get_operation()
{
    return operation;
}

double Calculator::add()
{
    return first_num + second_num;
}
double Calculator::subtract()
{
    return first_num - second_num;
}
double Calculator::multiply()
{
    return first_num * second_num;
}
double Calculator::modulo()
{
    return (int)first_num % (int)second_num;
}
double Calculator::divide()
{
    if (second_num == 0)
    {
        throw ERROR_CODES::DIVIDE_BY_ZERO::CODE;
    }
    return first_num / second_num;
}
// void Calculator::other_operator()
// {
//     if (!(operation == '+' || operation == '-' || operation == '*' || operation == '%' || operation == '/'))
//     {
//         throw ERROR_CODES ::OPERATOR_NOT_FOUND::CODE;
//     }
// }

double Calculator::working()
{
    double result;
    switch (operation)
    {
    case '+':
        result = add();
        break;
    case '-':
        result = subtract();
        break;
    case '*':
        result = multiply();
        break;
    case '%':
        result = modulo();
        break;
    case '/':
        result = divide();
        break;
    default:
        throw ERROR_CODES ::OPERATOR_NOT_FOUND::CODE;
    }
    std::cout << "Result is: " << result << std::endl;
    return result;
}
void Calculator::ask()
{
    char answer{'Y'};
    while (answer == 'Y')
    {
        input_first_num();
        input_operation();
        input_second_num();
        working();
        std::cout << "Do you want to continue? (press Y to continue) :";
        std::cin >> answer;
    }
}

void Calculator::try_catch()
{
    try
    {
        ask();
    }
    catch (int err)
    {
        switch (err)
        {
        case ERROR_CODES::DIVIDE_BY_ZERO::CODE:
            std::cout << ERROR_CODES::DIVIDE_BY_ZERO::TEXT << std::endl;
            break;
        default:
            std::cout << "Error not registered. Closing program with code error " << err << " ..." << std::endl;
            break;
        }
    }
    catch (...)
    {
        std::cout << "Error not registered. Closing program..." << std::endl;
        throw 1;
    }
}

void Calculator::print_history()
{
    int answer2;
    std::cout << "Thanyou for your time... Do you want to print history ? (press 1 for yes): ";
    std::cin >> answer2;
    if (answer2 == 1)
    {
        std::cout << "\n-------------------------------------------------\n\n";
        for (int i = num_history, j = 1; i > 0 && j <= CALCULATOR::MAX_HISTORY; i--, j++)
        {
            std::cout << "History " << i << " is: " << history[(i - 1) % CALCULATOR::MAX_HISTORY] << std::endl;
        }
    }
    std::cout << "\n-------------------------------------------------\nSee you soon!!!" << std::endl;
}
