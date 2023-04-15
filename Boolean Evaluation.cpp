#include <iostream>
#include <string>

using namespace std;

string conjunction(string p, string q) {
    if (p == "T" && q == "T") {
        return "T";
    } else {
        return "F";
    }
}

string disjunction(string p, string q) {
    if (p == "T" || q == "T") {
        return "T";
    } else {
        return "F";
    }
}

string implication(string p, string q) {
    if (p == "T" && q == "F") {
        return "F";
    } else {
        return "T";
    }
}

string biconditional(string p, string q) {
    if (p == q) {
        return "T";
    } else {
        return "F";
    }
}

string exclusive_or(string p, string q) {
    if ((p == "T" && q == "F") || (p == "F" && q == "T")) {
        return "T";
    } else {
        return "F";
    }
}

int main() {
    string p, q;
    char option;
    cout << "Enter the truth value of p (F for False, T for True): ";
    cin >> p;
    cout << "Enter the truth value of q (F for False, T for True): ";
    cin >> q;
    cout << "Enter the corresponding number for the logical operator:\n";
    cout << "1. Conjunction (^)\n2. Disjunction (v)\n3. Implication (->)\n4. Biconditional (<->)\n5. Exclusive or (+)\n";
    cout << "Option: ";
    cin >> option;

    string propositionalFormula;
    switch (option) {
        case '1':
            propositionalFormula = conjunction(p, q);
            break;
        case '2':
            propositionalFormula = disjunction(p, q);
            break;
        case '3':
            propositionalFormula = implication(p, q);
            break;
        case '4':
            propositionalFormula = biconditional(p, q);
            break;
        case '5':
            propositionalFormula = exclusive_or(p, q);
            break;
        default:
            cout << "Invalid option. Please enter a number between 1 and 5.\n";
            return 0;
    }

    cout << "P: " << p << endl;
    cout << "Q: " << q << endl;
    cout << "Expression: " << propositionalFormula << endl;

    return 0;
}
