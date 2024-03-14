#include <iostream>
struct Item
{
    std::string name;
    double value;
    void entry();
    void display();
};

class Expenses
{ // member variables
    static const int MAX_ITEMS = 1;
    Item items[Expenses::MAX_ITEMS];
    int num_items = 0;
    double total_income;
    double total_expenses;

public:
    // constructor
    Expenses() = default;

    // functions
    void input_income();
    void entry();
    double get_total_incomme()
    {
        return total_income;
    }
    void display();
};
