#ifndef FORMULASHEET_H
#define FORMULASHEET_H
#include <string>
#include <vector>
using namespace std;

/*
 * FormulaSheet:
 *  - Abstract base class that stores a list of formulas (strings) for a topic.
 *  - Used for Integral, Derivative, and Limit formula sheets.
 *
 *  Each formula is just a line of text from a .txt file.
 */
class FormulaSheet {
protected:
    vector<string> formulas; // Each formula is just one line of text.

public:
    virtual ~FormulaSheet() = default;

    // Returns the topic name (Integral / Derivative / Limit).
    virtual string getTopic() const = 0;

    /*
     * Loads formulas from a text file, one formula per non-empty line.
     */
    bool loadFromFile(const string& filename);

    /*
     * display:
     * Prints the formula sheet to the console in a nice format.
     */
    void display() const;
};

#endif

