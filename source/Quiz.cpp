#include "Quiz.hpp"

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::chrono::high_resolution_clock;

void Quiz::addQuestion(Question question) {
    mQuestions.push_back(question);
}

int Quiz::numQuestions() {
    return mQuestions.size();
}

void Quiz::shuffle() {
    default_random_engine engine = default_random_engine();

    typedef high_resolution_clock myClock;
    myClock::time_point beginning = myClock::now();
    myClock::duration d = myClock::now() - beginning;
    unsigned seed = d.count();
    engine.seed(seed);
    std::shuffle(mQuestions.begin(), mQuestions.end(), engine);
}

void Quiz::removeLast() {
    mQuestions.pop_back();
}

string Quiz::getQuestion() {
    return mQuestions.back().getQuestion();
}

string Quiz::getAnswer() {
    return mQuestions.back().getAnswer();
}
