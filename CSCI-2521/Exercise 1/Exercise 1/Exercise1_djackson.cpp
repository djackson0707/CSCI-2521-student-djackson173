/**
 * @file Exercise1_djackson.cpp
 * @author Darius Jackson
 * @date 2026-03-05
 * @brief This program validates UPC-A barcodes performing the UPC-A check digit algorithm.
 */

#include <iostream>
#include <string>
using namespace std;


/**
 * @brief Computes the sum of digits in even positions 
 * @param A string containing the 12 digit UPC code
 * @return The sum of even position digits 
 */
int EvenSum(const string& upc) {
    int sum = 0;
    for (int i = 1; i < 11; i += 2) {  
        sum += (upc[i] - '0');
    }
    return sum;
}

/**
 * @brief Computes the sum of digits in odd position
 * @param A string containing the 12 digit UPC code
 * @return The sum of odd position digits multiplied by 3
 */
int OddSum(const string& upc) {
    int sum = 0;
    for (int i = 0; i < 11; i += 2) {
        sum += (upc[i] - '0');
    }
    return sum * 3;
}


/**
 * @brief Calculates the correct UPC check digit 
 * @param A string containing the 12 digit UPC code
 * @return The calculated check digit which is from 0 to 9
 */
int CheckDigit(const string& upc) {
    int odd = OddSum(upc);
    int even = EvenSum(upc);
    int total = odd + even;

    int mod = total % 10;
    if (mod == 0) return 0;
    return 10 - mod;
}

int main() {
    string upc;
    char again = 'y';

    cout << "UPC-A Check Digit Validator\n";

    while (again == 'y') {
        cout << "\nEnter a 12 digit UPC code: ";
        cin >> upc;

        
        if (upc.length() != 12) {
            cout << "Invalid input. UPC must be 12 digits.\n";
        }
        else {
            int userCheckDigit = upc[11] - '0';
            int calculatedDigit = CheckDigit(upc);

            if (userCheckDigit == calculatedDigit) {
                cout << "Valid UPC. Check digit matches (" << calculatedDigit << ")" << endl;
            }
            else {
                cout << " Invalid UPC. Expected check digit: " << calculatedDigit << ", but found: " << userCheckDigit << ".\n";
            }
        }

        cout << "Test another UPC? (y/n): ";
        cin >> again;
    }

    cout << "Bye!\n";
    return 0;
}
