/**
 * @file Lab11_djackson.cpp
 * @author Darius Jackson
 * @date 2026-4-21
 * @brief Shows exception handling with STL vectors.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


 /**
  * @brief Entry point for the exception handling demonstration.
  * @return 0 to indicate successful execution.
  */
int main() {
    
    std::vector<std::string> cities{
        "Columbus",
        "Westerville",
        "Cincinnati",
        "Cleveland",
        "Hilliard",
        "Gahanna",
        "New Albany"
    };

    int index{};
    bool valid = false;
    
    while (!valid) {
        std::cout << "Enter an index to look up a city: ";
        std::cin >> index;

    try {
        const std::string& city = cities.at(index);
        std::cout << "City at index " << index << " is: " << city << "\n\n";
        valid = true;
    }
    catch (const std::out_of_range& e) {
     
        if (index < 0) {
            std::cout << "Invalid index. Here's the first city instead: " << cities.front() << "\n\n";
           
        }
        else if (static_cast<std::size_t>(index) >= cities.size()) {
            std::cout << "Invalid index. Here's the last city instead: " << cities.back() << "\n\n";
            }
        }
    }

    return 0;
}