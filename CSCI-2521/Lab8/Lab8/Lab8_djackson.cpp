/**
 * @file Lab8_djackson.cpp
 * @author Darius
 * @date 2026-03-24
 * @brief Demonstrates stack vs heap memory and the use of pointers and references.
 */

#include <iostream>
using namespace std;

/**
 * @brief Entry point for the memory demonstration.
 * @return 0 to indicate success.
 */
int main()
{
    int stackInt = 10; 
    int* heapInt = new int(20); 
    int* ptrToStack = &stackInt;
    int& refToStack = stackInt;
   
    cout << "Stack Variable (stackInt):" << endl;
    cout << " Value: " << stackInt << endl;
    cout << " Address: " << &stackInt << endl;
    cout << "Heap Variable (heapInt):" << endl;
    cout << " Value: " << *heapInt << endl;
    cout << " Address: " << heapInt << endl;
    cout << "Pointer to Stack (ptrToStack):" << endl;
    cout << " Value Pointed To: " << *ptrToStack << endl;
    cout << " Address Stored: " << ptrToStack << endl;
    cout << "Reference to Stack (refToStack):" << endl;
    cout << " Value Referred To: " << refToStack << endl;
    cout << " Address: " << &refToStack << endl;

    delete heapInt;
    heapInt = nullptr;  

    return 0;
}
