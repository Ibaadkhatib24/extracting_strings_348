/*
 * Name: Ibaad Khatib
 * KUID: 3080818
 * LAB Session: Thursdays 4pm
 * LAB Assignment: Extra Credit
 * Description: extracting double precision numbers from strings
 * Collaborators: n/a
 */

#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

// check if a string is valid and get the value
double extractNumeric(const string &input) {
    bool hasDecimalPoint = false; // checks if a decimal point exists
    int start = (input[0] == '+' || input[0] == '-') ? 1 : 0; 

    if (input.empty() || start == input.size()) return -999999.99; 

    // user input 
    for (size_t i = start; i < input.size(); ++i) {
        if (input[i] == '.') {
            if (hasDecimalPoint) return -999999.99; 
            hasDecimalPoint = true;
        } else if (!isdigit(input[i])) {
            return -999999.99; 
        }
    }
    // convert the strings
    double result = 0.0;
    size_t decimalPos = input.find('.');
    size_t i = start;
    // integer functon
    while (i < input.size() && input[i] != '.') {
        result = result * 10 + (input[i] - '0');
        ++i;
    }
    // fraction function
    if (decimalPos != string::npos) {
        double fraction = 0.0, divisor = 10.0;
        for (size_t j = decimalPos + 1; j < input.size(); ++j) {
            fraction += (input[j] - '0') / divisor;
            divisor *= 10.0;
        }
        result += fraction;
    }
    //  negative connotation
    if (input[0] == '-') result = -result;

    return result;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") break;

        double value = extractNumeric(input);

        if (value != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << value << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
