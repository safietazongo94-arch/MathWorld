#include "limitquestion.h"
#include <fstream>
#include <iostream>
using namespace std;

string LimitQuestion::getTopic() const {
    return "Limit";
}
/*
 * loadFromFile(filename)
 * Reads limit problems from a structured text file.
 */

vector<LimitQuestion> LimitQuestion::loadFromFile(const string& filename) {
    vector<LimitQuestion> bank;
    ifstream in(filename);
    // Could not open file
    if (!in) {
        cerr << "Cannot open limit problems file: " << filename << "\n";
        return bank;
    }

    string q, a, e, blank;

    while (getline(in, q)) {
        q = trim(q);
        if (q.empty()) continue;

        if (!getline(in, a)) break;
        if (!getline(in, e)) e = "";

        getline(in, blank);

        if (e == "-") e = "";

        bank.emplace_back(q, a, e);
    }

    return bank;
}
