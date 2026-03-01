/**
 * @file Lab6_djackson.cpp
 * @author Darius
 * @date 2026-02-24
 * @brief Compare static arrays and vectors for processing student scores
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Calculates statistics using a fixed-size static array
 * @param None
 * @return None (void)
 */
void arraySolution() {
    const int size = 10;
    int scores[size];

    cout << "Static Array Solution" << endl;

    
    for (int i = 0; i < size; i++) {
        int value = 0;
        cout << "Enter score " << (i + 1) << " (0 to 100): ";
        cin >> value;

        
        while (value < 0 || value > 100) {
            cout << "Invalid score. Enter a value between 0 and 100: ";
            cin >> value;
        }

        scores[i] = value;
    }

    
    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (int i = 0; i < size; i++) {
        sum += scores[i];
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
    }

    float average = static_cast<float>(sum) / size;

    cout << "Static Array Results:" << endl;
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;
    cout << endl;
}

/**
 * @brief Calculates statistics using a dynamic vector
 * @param None
 * @return None (void)
 */
void vectorSolution() {
    vector<int> scores;
    int value = 0;

    cout << "Vector Solution" << endl;

    
    cout << "Enter scores (0 to 100). Enter -1 to finish." << endl;

    while (true) {
        cout << "Enter score: ";
        cin >> value;

        if (value == -1) break;

        while (value < 0 || value > 100) {
            cout << "Invalid score. Enter a value between 0 and 100, or -1 to stop: ";
            cin >> value;
            if (value == -1) break;
        }

        if (value != -1) {
            scores.push_back(value);
        }
    }

   

    
    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (int s : scores) {
        sum += s;
        if (s > highest) highest = s;
        if (s < lowest) lowest = s;
    }

    float average = static_cast<float>(sum) / scores.size();

   
    sort(scores.begin(), scores.end());

    cout << "Vector Results:" << endl;
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    cout << "Sorted scores: ";
    for (int s : scores) {
        cout << s << " ";
    }
    cout << endl << endl;
}

/**
 * @brief Entry point of the program
 * @param None
 * @return 0 to indicate success
 */
int main() {
    arraySolution();
    vectorSolution();
    return 0;
}








