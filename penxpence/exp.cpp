#include <iostream>
#include "exp.h"

using namespace std;
void Item::entry()
{
    cout << "Enter name of item: ";
    cin >> this->name;
    cout << "Enter value of item: ";
    cin >> this->value;
}

void Item::display()
{
    cout << "\nItem Name: " << name << ", Item value: " << value;
}
void Expenses::input_income()
{
    cout << "\nEnter total income: ";
    cin >> this->total_income;
}

void Expenses::entry()
{
    char answer = 'Y';
    while (answer == 'Y')
    {
        Item new_item;
        new_item.entry();

        items[num_items] = new_item;
        num_items++;
        total_expenses += new_item.value;

        if (num_items == Expenses::MAX_ITEMS)
        {
            cout << "Max limit reached. Thanks!";
            break;
        }
        cout << "Press Y to continue: ";
        cin >> answer;
    }
}

void Expenses::display()
{
    cout << "\nTotal Income: " << total_income;
    cout << "\nTotal Expenses: " << total_expenses;
    cout << "\nEntries: ";
    for (int i = 0; i < num_items; i++)
    {
        items[i].display();
    }
    cout << "\n\nEnd of the list ----------\n\n";
}
