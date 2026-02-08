/**
 * @file Lab3_djackson.cpp
 * @author Darius Jackson
 * @date 2026-02-27
 * @brief A menu-driven program to calculate areas of rectangles and circles.
 */

#include <iostream>
using namespace std;

int main() {
    
    const double PI = 3.14159;

    
    int option;
    double length, width, radius, area;

    
    cout << "Menu" << endl;
    cout << "1. Calculate the Area of a Rectangle" << endl;
    cout << "2. Calculate the Area of a Circle" << endl;
    cout << "3. Quit" << endl;
    cout << "Please make a menu selection: ";
    cin >> option;

    
    if (option == 1) {
        
        cout << "Please enter the length of the rectangle: ";
        cin >> length;

        cout << "Please enter the width of the rectangle: ";
        cin >> width;

        area = length * width;

        cout << "The area of the rectangle is: " << area << endl;
    }
    else if (option == 2) {
        
        cout << "Please enter the radius of the circle: ";
        cin >> radius;

        area = PI * radius * radius;

        cout << "The area of the circle is: " << area << endl;
    }
    else if (option == 3) {
        
        return 0;
    }
    else {
       
        cout << "The menu option you entered is not valid. Please try again." << endl;
    }

    return 0;
}
