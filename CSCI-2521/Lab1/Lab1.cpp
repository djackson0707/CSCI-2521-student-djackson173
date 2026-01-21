/**
 * @file Lab1.cpp
 * @author Darius 
 * @date 2026-01-20
 * @brief A simple program to greet the user by name.
 */

#include<iostream>

using namespace std;

int main()
{

	string firstName;
	cout << "Please enter first name: ";
	cin >> firstName;

	string lastName;
	cout << "Please enter last name: ";
	cin >> lastName;

	cout << "Welcome to c++ programming, " << firstName << " " << lastName << endl;


	return 0;


}
