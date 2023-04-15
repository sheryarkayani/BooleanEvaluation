#include <iostream>
#include <string>
using namespace std;

bool evaluateBoolean(string str, int& index, bool& result);

bool evaluateSubExpression(string str, int& index, bool& result) {
    if (str[index] == '~') {
        index++;
        // Evaluate the negation of the next expression
        bool negationResult;
        evaluateBoolean(str, index, negationResult);
        result = !negationResult;
        return true;
    } else if ((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z')) {
        // Evaluate the literal
        result = str[index] >= 'A' && str[index] <= 'Z';
        index++;
        return true;
    } else {
        // Return false to indicate that an error occurred
        return false;
    }
}

bool evaluateBoolean(string str, int& index, bool& result) {
    if (!evaluateSubExpression(str, index, result)) {
        return false;
    }

    while (index < str.length()) {
        if (str[index] == '^') {
            index++;
            bool rightResult;
            if (!evaluateSubExpression(str, index, rightResult)) {
                return false;
            }
            result = result || rightResult;
        } else if (str[index] == 'v') {
            index++;
            bool rightResult;
            if (!evaluateSubExpression(str, index, rightResult)) {
                return false;
            }
            result = result && rightResult;
        } else if (str[index] == ')') {
            index++;
            return true;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string propositionalFormula;
    cout << "Enter a propositional Formula" << endl;
    getline(cin, propositionalFormula);

    int index = 0;
    bool result;
    bool success = evaluateBoolean(propositionalFormula, index, result);

    if (success) {
        // Print the final result of the expression
        cout << "Result: " << (result ? "true" : "false") << endl;
    } else {
        // Indicate that an error occurred
        cout << "Error: Invalid propositional formula" << endl;
    }

    return 0;
}
