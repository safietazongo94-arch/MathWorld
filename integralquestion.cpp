#include "integralquestion.h"
#include <fstream>
#include <iostream>
using namespace std;
/*
 * getTopic()
 * Allows feedback and menu systems to label these questions
 * as belonging to the Integral category.
 */

string IntegralQuestion::getTopic() const {
    return "Integral";
}
/*
 * loadFromFile(filename)
 * Reads integration problems from a text file with the specified structure.
 */

vector<IntegralQuestion> IntegralQuestion::loadFromFile(const string& filename) {
    vector<IntegralQuestion> bank;
    ifstream in(filename);

    // If the file cannot be opened, return an empty set.
    if (!in) {
        cerr << "Cannot open integral problems file: " << filename << "\n";
        return bank;
    }

    string q, a, e, blank;

    // Loop reads one complete question block at a time.
    while (std::getline(in, q)) {
        q = trim(q); // Clean whitespace
        if (q.empty()) continue;// Skip empty lines

        if (!getline(in, a)) break; // Answer line
        if (!getline(in, e)) e = "";// Explanation line

        getline(in, blank); // Consume blank line separator

        if (e == "-") e = "";// "-" means no explanation included

        // Store a constructed IntegralQuestion
        bank.emplace_back(q, a, e);
    }

    return bank;
}

