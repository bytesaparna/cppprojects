namespace CALCULATOR
{
#include <iostream>

    const uint64_t MAX_HISTORY = 5;

    class Calculator
    {
        // member variable
    private:
        double first_num;
        double second_num;
        char operation;

        uint64_t num_history = 0;
        double history[MAX_HISTORY];

        double input_num(std::string output, double *num_ptr);

        // constructor
    public:
        Calculator() = default;

        // functions
        void input_first_num();
        double get_first_num();
        void input_operation();
        char get_operation();
        void input_second_num();
        double get_second_num();

        double add();
        double subtract();
        double multiply();
        double modulo();
        double divide();
        double working();
        void ask();
        void try_catch();
        void print_history();
    };
}
namespace ERROR_CODES
{
    namespace DIVIDE_BY_ZERO
    {
        const int CODE = 501;
        const char TEXT[] = "Divide by zero error";
    }

    namespace OPERATOR_NOT_FOUND
    {
        const int CODE = 502;
        const char TEXT[] = "Unsupported operation";
    }
}