#pragma once

#include <vector>

#include "Question.hpp"

using std::vector;

class Quiz {
    public:
        void addQuestion(Question question);
        
        int numQuestions();
        void removeLast();
        void shuffle();
        
        string getQuestion();
        string getAnswer();
    
    private:
        vector<Question> mQuestions;
};

