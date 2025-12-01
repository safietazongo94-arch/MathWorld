#include "formulasheet.h"
#include "Question.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * loadFromFile(filename)
 * ----------------------
 * Reads each non-empty line from a text file
 * and stores it as a formula.
 */

bool FormulaSheet::loadFromFile(const string& filename) {
    formulas.clear();
    ifstream in(filename);

    if (!in) {
        cerr << "Could not open formula sheet file: " << filename << "\n";
        return false;
    }

    string line;
    while (getline(in, line)) {
        line = trim(line);
        if (!line.empty()) {
            formulas.push_back(line);
        }
    }

    return true;
}

/*
 * display()
 * Prints all formulas under a topic heading.
 */

void FormulaSheet::display() const {
    cout << "\n===== " << getTopic() << " Formula Sheet =====\n";

    if (formulas.empty()) {
        cout << "(No formulas loaded.)\n";
    }
    else {
        for (const auto& f : formulas) {
            cout << " - " << f << "\n";
        }
    }

    cout << "=========================================\n\n";
}
