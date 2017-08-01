#pragma once

#include <memory>

#include "Quiz.hpp"
#include "QuizProgram.hpp"

using std::unique_ptr;

class QuizProgram {
    public:
        QuizProgram(unique_ptr<Quiz> quiz);
        void start(int numQs, bool shuffle);

    private:
        unique_ptr<Quiz> mQuiz;

        void shuffle();
        void clearScreen();
};
