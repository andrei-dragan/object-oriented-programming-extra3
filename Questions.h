#pragma once

#include "Question.h"
#include <vector>

class Questions {
private:
	std::vector<Question>questions;
public:
	Questions();
	void read();
	void write();
	std::vector<std::string> getQuestion(std::string str, char delimiter);

	std::vector<Question> getQuestions() { return this->questions; }
	void addQuestion(Question q);
};