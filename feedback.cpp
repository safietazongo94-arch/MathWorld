#include "feedback.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Constructor
 * -----------
 * Copies the original question (prompt, correctAnswer, explanation)
 * and stores extra feedback fields.
 */

Feedback::Feedback(const Question& q, const string& userAns, bool correct)
    // We call the base class constructor to copy prompt/correctAnswer/explanation.
    : Question(q.getPrompt(), q.getCorrectAnswer(), q.getExplanation()),
    userAnswer(userAns),
    isCorrect(correct),
    originalTopic(q.getTopic()) {
}

/*
* Feedback items are not selectable topics.
 */
string Feedback::getTopic() const {
    return "Feedback";
}

/*
 * display()
 * ---------
 * Prints:
 *   - Topic
 *   - Question
 *   - User's answer
 *   - Correct answer
 *   - Explanation (if any)
 *   - A correctness message
 */

void Feedback::display() const {
    cout << "\n===== Feedback =====\n";
    cout << "Topic: " << originalTopic << "\n\n";

    cout << "Question:\n" << prompt << "\n\n";

    cout << "Your answer:    " << userAnswer << "\n";
    cout << "Correct answer: " << correctAnswer << "\n";

    if (!explanation.empty()) {
        cout << "Explanation:   " << explanation << "\n";
    }

    if (isCorrect) {
        cout << "Result: Correct! Great job.\n";
    }
    else {
        cout << "Result: Incorrect. Review the explanation above.\n";
    }

    cout << "====================\n\n";
}
