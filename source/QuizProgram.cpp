#include "QuizProgram.hpp"

#include <iostream>
#include <climits>

using std::cout;
using std::cin;
using std::endl;
using std::move;

QuizProgram::QuizProgram(unique_ptr<Quiz> quiz) : mQuiz(move(quiz)) { }

void QuizProgram::start(int numQs, bool shuffle) {
    if (shuffle) {
        mQuiz->shuffle();
    }

    int numAnsweredQs = 0;
    int rightAnswers = 0;
    int wrongAnswers = 0;

    int input = 0;

    clearScreen();


    while (numAnsweredQs < numQs && mQuiz->numQuestions() > 0) {
        cout << mQuiz->getQuestion() << endl << endl;

        do {
            //cout << "Press enter..." << endl;
        } while (cin.get() != '\n');

        cout << mQuiz->getAnswer() << endl;

        input = 0;

        cout << endl << endl;
        do {
            cout << "Correct? (y/n) 1/2: ";
            cin >> input;
            if (input != 1 && input != 2) {
                // This checks if a char was input
                // if the conditional (input != ...) check wasn't there
                // then this would execute every time, which causes the user
                // to have to input an extra newline
                cin.clear();
                cin.ignore(100, '\n');
            }
        } while (input != 1 && input != 2);

        if (input == 1) {
            rightAnswers++;
        } else {
            wrongAnswers++;
        }

        numAnsweredQs++;

        mQuiz->removeLast();

        cin.clear();
        cin.ignore(INT_MAX,'\n');

        clearScreen();

        // TODO: Add remaining questions count to output
        cout << rightAnswers << "/" << numAnsweredQs << endl << endl << endl;

    }

    cout << rightAnswers << " out of " << numAnsweredQs << " correct." << endl;

    // ************************
    // TODO: display wrong questions
    // ************************
}

void QuizProgram::clearScreen() {
    for (int i = 0; i < 35; i++) {
        cout << "\n";
    }
}
