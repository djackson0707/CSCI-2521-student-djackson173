/**
 * @file Lab5_djackson.cpp
 * @author Darius Jackson
 * @date 2026-02-19
 * @brief A modular program to generate a multiplication table using functions.
 */

#include <iostream>
using namespace std;

/**
 * @brief: Outputs an error message for invalid input.
 * @param: None.
 * @return: None.
 */
void printInputValidationError();

/**
 * @brief: Checks if the input is within the valid range.
 * @param: input The integer value to be validated.
 * @return: True if the input is valid (4 < input < 10), false otherwise.
 */

bool isMaxDigitInputValid(int input);

/**
 * @brief: Prompts the user for input and ensures it is valid.
 * @param: None.
 * @return: A validated integer representing the maximum digit.
 */
int getMaxDigitInput();

/**
 * @brief: Prints the formatted multiplication table.
 * @param: maxDigit - The highest digit to include in the table.
 * @return: None.
 */
void printMultiplicationTable(int maxDigit);

/**
 * @brief: Entry point of the program.
 * @param: None.
 * @return: 0 to indicate success.
 */
int main() {
    int maxDigit = getMaxDigitInput();
    printMultiplicationTable(maxDigit);
    return 0;
}

void printInputValidationError() {
    cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
}

bool isMaxDigitInputValid(int input) {
    return (input > 4 && input < 10);
}

int getMaxDigitInput() {
    int max = 0;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10." << endl;

    cout << "Max Digit: ";
    cin >> max;

    while (!isMaxDigitInputValid(max)) {
        printInputValidationError();
        cout << "Max Digit: ";
        cin >> max;
    }

    return max;
}

void printMultiplicationTable(int maxDigit) {
    for (int row = 1; row <= maxDigit; row++) {
        for (int col = 1; col <= maxDigit; col++) {
            cout << row * col << "\t";
        }
        cout << endl;
    }
}
