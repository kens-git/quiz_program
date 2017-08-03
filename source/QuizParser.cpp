#include <iostream>

#include "QuizParser.hpp"
#include "CSVparser.hpp"

#include "Quiz.hpp"

using std::cout;
using std::endl;

Quiz QuizParser::fetchQuestions(vector<string> filepaths) {
    Quiz quiz;
    
    for (string filepath : filepaths) {
        try {
            csv::Parser file = csv::Parser(filepath);
            
            for (int j = 0; j < file.rowCount(); j++) {
                quiz.addQuestion(Question(file[j][0], file[j][1]));
            }
        } catch (csv::Error& e) {
            cout << "Error in " << filepath << ":" << endl;
            cout << e.what() << endl;
        }
    }
    
    return quiz;
}
