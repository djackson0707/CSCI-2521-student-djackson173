/**
 * @file Lab4_djackson.cpp
 * @author Darius Jackson
 * @date 2026-02-10
 * @brief A program to generate a multiplication table with input validation.
 */

#include <iostream>
using namespace std;

int main() {
    int max = 0;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10" << endl;

    cout << "Max Digit: ";
    cin >> max;

    
    while (max <= 4 || max >= 10) { 
          cout << "Error: The max digit must be greater than 4 and less than 10. Please try again.\n"; 
          cout << "Max Digit: "; 
          cin >> max; 
         
         }

    
    for (int row = 1; row <= max; row++) {
        for (int col = 1; col <= max; col++) {
            cout << row * col << "\t";
        }
        cout << endl;
    }

    return 0;
}
