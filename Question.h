#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

/*
 * The Question class is an ABSTRACT BASE CLASS.
 * It represents a generic calculus question (integral, derivative, limit).
 *
 * Each question has:
 *  - a prompt:      the text shown to the student
 *  - a correctAnswer: what we consider the correct response
 *  - an explanation:   optional text explaining the solution
 *
 * Derived classes (IntegralQuestion, DerivativeQuestion, LimitQuestion) provide:
 *  - a topic name (via getTopic())
 *  - loading from files
 */
class Question {
protected:
    string prompt;
    string correctAnswer;
    string explanation;

public:
    // Default constructor (empty question).
    Question() = default;

    // Convenience constructor to set all the content at once.
    Question(const string& p, const string& ans, const string& expl);

    // Virtual destructor because we will delete derived objects through base pointers.
    virtual ~Question() = default;

    // Each specific question type (integral, derivative, limit) returns its topic name.
    virtual string getTopic() const = 0;

    // Accessors (read-only).
    const string& getPrompt() const;
    const string& getCorrectAnswer() const;
    const string& getExplanation() const;

    /*
     * checkAnswer:
     * Compares the student's answer with the stored correct answer.
     * We normalize both strings (trim spaces, make lowercase) to be less strict
     * about capitalization and extra spaces.
     */
    virtual bool checkAnswer(const string& userAns) const;

    /*
     * normalize:
     * Helper: trims whitespace and converts all characters to lowercase.
     * Used so that " x^2 + c " and "X^2 + C" are treated as the same.
     */
    static string normalize(const string& s);
};

/*
 * trim:
 * Removes leading and trailing whitespace characters (space, tab, newline).
 * This is used when reading lines from files and when checking answers.
 */
string trim(const string& s);

/*
 * toLower:
 * Returns a copy of the string where every character is converted to lowercase.
 */
string toLower(const string& s);
#endif // QUESTION_H
