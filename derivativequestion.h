#ifndef DERIVATIVEQUESTION_H
#define DERIVATIVEQUESTION_H
#include "Question.h"
#include <vector>
using namespace std;

/*
 * DerivativeQuestion:
 *  - Represents a derivative problem.
 *  - Inherits from Question (which stores prompt, answer, explanation).
 * - Adds a static loader to read derivative questions from a file.
 */
class DerivativeQuestion : public Question {
public:
    using Question::Question;// Reuse Question’s constructor (prompt, answer, explanation).

    string getTopic() const override;
    // Loads a vector of DerivativeQuestion objects from a .txt file.
    static vector<DerivativeQuestion> loadFromFile(const string& filename);
};

#endif

