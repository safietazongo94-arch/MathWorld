#ifndef LIMITQUESTION_H
#define LIMITQUESTION_H
#include "Question.h"
#include <vector>
using namespace std;

/*
 * LimitQuestion:
 *  - A specific type of Question for limit problems.
 *  - It uses the same fields but the topic is "Limit".
 *  - Also provides a static function to load many limit questions from a file.
 */

class LimitQuestion : public Question {
public:
    using Question::Question;

    string getTopic() const override;

    static vector<LimitQuestion> loadFromFile(const string& filename);
};

#endif

