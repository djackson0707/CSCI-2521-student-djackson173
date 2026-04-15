/**
 * @file Exercise2_djackson.cpp
 * @author Darius Jackson
 * @date 2026-4-15
 * @brief Translates English sentences into Morse Code.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;


string toUpperCase(string str)
{
    string output = "";
    for (int i = 0; i < str.length(); i++)
        output += toupper(str[i]);
    return output;
}



class MorseTable {
private:
    map<char, string> table;

public:
    MorseTable() {
        table['A'] = ".-";   table['B'] = "-..."; table['C'] = "-.-.";
        table['D'] = "-..";  table['E'] = ".";    table['F'] = "..-.";
        table['G'] = "--.";  table['H'] = "...."; table['I'] = "..";
        table['J'] = ".---"; table['K'] = "-.-";  table['L'] = ".-..";
        table['M'] = "--";   table['N'] = "-.";   table['O'] = "---";
        table['P'] = ".--."; table['Q'] = "--.-"; table['R'] = ".-.";
        table['S'] = "...";  table['T'] = "-";    table['U'] = "..-";
        table['V'] = "...-"; table['W'] = ".--";  table['X'] = "-..-";
        table['Y'] = "-.--"; table['Z'] = "--..";
    }

    string getMorse(char c) {
        if (table.count(c))
            return table[c];
        return "";
    }
};



class Translator {
private:
    MorseTable morse;

public:
    void translateSentence(string sentence) {
        sentence = toUpperCase(sentence);

        cout << "\nMorse Code Output:\n";

        for (int i = 0; i < sentence.length(); i++) {
            char c = sentence[i];

            if (isalpha(c)) {
                cout << morse.getMorse(c) << " ";
            }
            
        }

        cout << "\n\n";
    }
};


int main() {
    Translator translator;
    string input;
    char again = 'Y';

    cout << "\nMorse Code Translator\n";

    while (toupper(again) == 'Y') {
        cout << "Enter a sentence (max 50 characters):";
        getline(cin, input);

        if (input.length() > 50) {
            cout << "Error: Sentence is too long.";
            continue;
        }

        translator.translateSentence(input);

        cout << "Would you like to translate another? (Y/N): ";
        cin >> again;
      
    }

    cout << "Bye.";
    return 0;
}