#pragma once

#include <string>

using std::string;

class Question {
	public:
		Question(string question, string answer) { mQuestion = question; mAnswer = answer; }
		
		string getQuestion() { return mQuestion; }
		string getAnswer() { return mAnswer; }
	
	private:
		string mQuestion;
		string mAnswer;
};
