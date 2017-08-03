#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <boost/lexical_cast.hpp>

#include "ArgParser.hpp"
#include "QuizParser.hpp"
#include "Quiz.hpp"
#include "QuizProgram.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::make_unique;

using boost::lexical_cast;
using boost::bad_lexical_cast;

void clearScreen();

int main(int argc, char** argv) {
    unsigned int numQs;

    try {
        numQs = lexical_cast<unsigned int>(argv[1]);
    } catch (const bad_lexical_cast &) {
        cout << endl << "Could not determine number of questions argument." << endl;
        cout << "Whole number expected but got: " << argv[1] << endl << endl;
        return 0;
    }

    if (numQs == 0) { // the user has selected all questions from the provided categories
        numQs = 1000000000;
    }

    vector<string> filepaths = ArgParser().parse(argc, argv);

    if (filepaths.size() == 0) {
        cout << endl << "Could not load any questions" << endl << endl;
        return 0;
    }
    
    QuizParser quizParser;
    QuizProgram quiz(make_unique<Quiz>(quizParser.fetchQuestions(filepaths)));

    quiz.start(numQs, true);

    return 0;
}
