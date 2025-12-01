#ifndef INTEGRALQUESTION_H
#define INTEGRALQUESTION_H
#include "Question.h"
#include <vector>
using namespace std;

/*
 * IntegralQuestion:
 *  - A specific type of Question for integration problems.
 *  - It uses the same fields but the topic is "Integral".
 *  - Also provides a static function to load many integral questions from a file.
 */
class IntegralQuestion : public Question {
public:
    // Inherit the base constructors (so we can construct with (prompt, answer, explanation)).
    using Question::Question;

    string getTopic() const override;

    /*
     * loadFromFile:
     * Reads integral questions from a text file with the following structure:
     *   Line 1: question
     *   Line 2: answer
     *   Line 3: explanation (or "-" if no explanation)
     *   Line 4: blank line (separator)
     */
    static vector<IntegralQuestion> loadFromFile(const string& filename);
};

#endif
