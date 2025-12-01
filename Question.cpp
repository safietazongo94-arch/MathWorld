#include "Question.h"
#include <algorithm>
#include <cctype>
using namespace std;

Question::Question(const string& p, const string& ans, const string& expl)
    : prompt(p), correctAnswer(ans), explanation(expl) {
}

// Simple getters.
const string& Question::getPrompt() const {
    return prompt;
}

const string& Question::getCorrectAnswer() const {
    return correctAnswer;
}

const string& Question::getExplanation() const {
    return explanation;
}

string trim(const string& s) {
    // Find first non-whitespace character.
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return ""; // string is all whitespace

    // Find last non-whitespace character.
    size_t end = s.find_last_not_of(" \t\n\r");

    // Return substring without leading/trailing spaces.
    return s.substr(start, end - start + 1);
}

string toLower(const string& s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(),
              [](unsigned char c) { return tolower(c); });
    return out;
}

string Question::normalize(const string& s) {
    // First trim spaces, then convert to lowercase for comparison.
    return toLower(trim(s));
}

bool Question::checkAnswer(const string& userAns) const {
    // By default we just compare the normalized versions.
    return normalize(userAns) == normalize(correctAnswer);
}
