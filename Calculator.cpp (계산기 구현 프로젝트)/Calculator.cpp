/*
 * Calculator.cpp
 *
 *  Date: 2025-05-18
 *  Author: Seunghwan Lee
 */

#include <iostream>

using namespace std;

int main() // Changed to int main(), which is the correct return type
{
    double op1, op2; // Changed to double for supporting both integers and decimals
    char operation;
    char answer = 'Y'; // Changed from double quotes -> single quotes for a character literal

    while (answer == 'Y' || answer == 'y') // Added comparison for both 'Y' and 'y'
    {
        cout << "Enter expression (e.g., 2 + 2): " << endl;
        cin >> op1 >> operation >> op2; // Switched to correct order of operands

        // Removed extra semicolons , also corrected the logic
        if (operation == '+') {
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }
        else if (operation == '-') {
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }
        else if (operation == '*') {
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }
        else if (operation == '/') {
            if (op2 != 0) {
                cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
            }
            else {
                cout << "Error: Division by zero is undefined." << endl;
            }
        }
        else {
            cout << "Error: Invalid operator." << endl;
        }

        cout << "Do you wish to evaluate another expression? (Y/N): ";
        cin >> answer;
    }

    cout << "Program Finished." << endl;
    return 0; 
}
