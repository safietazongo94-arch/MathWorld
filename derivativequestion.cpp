#include "derivativequestion.h"
#include <fstream>
#include <iostream>
using namespace std;
/*
* Allows the system to label these questions as “Derivative”
 * when shown in Feedback or other menus.
 */

string DerivativeQuestion::getTopic() const {
    return "Derivative";
}
/*
 * loadFromFile(filename)
 * ----------------------
 * Reads derivative questions from a structured text file.
 * Format expected:
 *   line 1: question text
 *   line 2: correct answer
 *   line 3: explanation (or '-' for no explanation)
 *   blank line
 */

vector<DerivativeQuestion> DerivativeQuestion::loadFromFile(const string& filename) {
    vector<DerivativeQuestion> bank;
    ifstream in(filename);

    // If file fails to open, return an empty bank.
    if (!in) {
        cerr << "Cannot open derivative problems file: " << filename << "\n";
        return bank;
    }

    string q, a, e, blank;

    // Read until no more questions remain
    while (getline(in, q)) {
        q = trim(q); // Remove whitespace
        if (q.empty()) continue; // Skip accidental blank lines

        // Read the answer and explanation lines
        if (!getline(in, a)) break;
        if (!getline(in, e)) e = "";

        std::getline(in, blank);// Consume the empty separator line

        if (e == "-") e = ""; // "-" means no explanation

        bank.emplace_back(q, a, e);// Construct to store the question, answer, explanation
    }

    return bank;
}

