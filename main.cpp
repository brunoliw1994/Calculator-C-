// Calculator (C++)
// Created by Bruno Valente
// References:
// - https://www.w3schools.com/cpp/cpp_user_input.asp
// - https://cplusplus.com/doc/tutorial/operators/
// - https://www.youtube.com/watch?v=Rub-JsjMhWY
// - https://learn.microsoft.com/en-us/cpp/cpp/new-and-delete-operators-cpp
// - https://www.geeksforgeeks.org/basic-calculator-cpp/

#include <iostream>
using namespace std;

// This Calculator class will handle the arithmetic logic
class SimpleCalculator {
public:
    double value1, value2;
    char operation;

    // Constructor
    SimpleCalculator(double v1, double v2, char opSymbol) {
        value1 = v1;
        value2 = v2;
        operation = opSymbol;
    }

    // Function to perform the selected operation
    double compute() {
        if (operation == '+') return value1 + value2;
        else if (operation == '-') return value1 - value2;
        else if (operation == '*') return value1 * value2;
        else if (operation == '/') {
            // Error handling: check for divide by zero
            if (value2 == 0) {
                cout << "Error: Cannot divide by zero!" << endl;
                return 0;
            }
            return value1 / value2;
        } else {
            // Invalid operator
            cout << "Error: Invalid operator!" << endl;
            return 0;
        }
    }
};

int main() {
    double numA, numB;
    char mathOp;
    char repeat;

    do {
        // Getting user input
        cout << "Enter first number: ";
        cin >> numA;

        cout << "Enter operator (+, -, *, /): ";
        cin >> mathOp;

        cout << "Enter second number: ";
        cin >> numB;

        // Here we use 'new' to dynamically allocate a Calculator object
        SimpleCalculator* myCalc = new SimpleCalculator(numA, numB, mathOp);

        // Perform calculation and display result
        double output = myCalc->compute();
        cout << "Result: " << output << endl;

        // Here we use 'delete' to free the memory of the dynamically allocated object
        delete myCalc;

        // Ask the user if they want to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    // Program ends with a message to the user
    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
