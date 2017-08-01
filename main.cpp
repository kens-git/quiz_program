#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <memory>

#include <boost/filesystem.hpp>

#include "Question.hpp"
#include "CSVparser.hpp"
#include "ArgParser.hpp"
#include "QuizParser.hpp"
#include "Quiz.hpp"
#include "QuizProgram.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::make_unique;

namespace fs = boost::filesystem;

void clearScreen();

int main(int argc, char** argv) {
    vector<string> filepaths = ArgParser().parse(argc, argv);

    if (filepaths.size() == 0) {
        cout << endl << "Could not load any questions" << endl << endl;
        return 0;
    }
    
    QuizParser quizParser;
    QuizProgram quiz(make_unique<Quiz>(quizParser.fetchQuestions(filepaths)));

    // ****************************************
    // FIX THIS! (away from using atoi())
    // ****************************************
    int numQs = atoi(argv[1]);
    if (numQs == 0) { // the user has selected all questions from the provided categories
        numQs = 1000000000;
    }

    quiz.start(numQs, true);

    return 0;
}
