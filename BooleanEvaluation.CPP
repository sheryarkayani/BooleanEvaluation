#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Functions
string applyDeMorgan(string str, int start, int end) {
    string result;
    for (int i = start; i <= end; i++) {
        if (str[i] == '^') {
            // result.push_back('v');
            result = result + 'v';
        } else if (str[i] == 'v') {
            // result.push_back('^');
            result = result + '^';
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            // result.push_back('~');
            // result.push_back(str[i]);
            result = result + '~' + str[i];
        } else {
            // result.push_back(str[i]);
            result = result + str[i];
        }
    }
    return result;
}

string SimplifyBoolean(string str) {
    int arrLength = str.length();
    string updatedStr;

    for (int i = 0; i < arrLength; i++) {
        if (str[i] == '~' && str[i + 1] == '(') {
            int openParentheses = 1;
            int closeParentheses = 0;

            for (int j = i + 2; j < arrLength; j++) {
                if (str[j] == '(') {
                    openParentheses++;
                } else if (str[j] == ')') {
                    closeParentheses++;
                }

                if (openParentheses == closeParentheses) {
                    string simplified = applyDeMorgan(str, i + 2, j - 1);
                    // updatedStr += simplified;
                    updatedStr = updatedStr + simplified;
                    i = j;
                    break;
                }
            }
        } else {
            // updatedStr.push_back(str[i]);
            updatedStr = updatedStr + str[i];
        }
    }
    return updatedStr;
}

int main() {
    string propositionalFormula;
    cout << "Enter a propositional Formula" << endl;
    getline(cin, propositionalFormula);

    cout << "Simplified formula: " << SimplifyBoolean(propositionalFormula) << endl;

    return 0;
}
