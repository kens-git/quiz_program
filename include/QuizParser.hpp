#pragma once

#include <vector>

#include "Question.hpp"

using std::vector;

class Quiz;

class QuizParser {
    public:
        Quiz fetchQuestions(vector<string> filepaths);
};

