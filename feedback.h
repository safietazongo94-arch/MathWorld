#ifndef FEEDBACK_H
#define FEEDBACK_H
#include "Question.h"
using namespace std;

/*
 * Feedback class:
 *  - Created AFTER the student answers a question.
 *  - It stores:
 *      * the original question text and correct answer (from Question)
 *      * the user's answer
 *      * whether their answer was correct or not
 *      * the topic (Integral / Derivative / Limit)
 *
 *  Inherits from Question so we can reuse stored data.
 *  but with extra info useful to show results.
 */
class Feedback : public Question {
private:
    string userAnswer;   // What the student typed
    bool isCorrect;           // True if their answer was correct
    string originalTopic;//  "Integral", "Derivative", or "Limit"

public:
    // Construct feedback from an the original Question, the user answer, and correctness.
    Feedback(const Question& q, const string& userAns, bool correct);

    // Topic for feedback is simply "Feedback" (not used for selection).
    string getTopic() const override;

    // Print a formatted feedback block to the console
    void display() const;
};

#endif

