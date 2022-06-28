#pragma once

#include "Answer.h"
#include <vector>

class Answers {
private:
	std::vector<Answer>answers;
public:
	Answers();
	void read();
	void write();
	std::vector<std::string> getAnswer(std::string str, char delimiter);

	std::vector<Answer> getAnswers() { return this->answers; }

	void addAnswer(Answer ans);
	void voteAnswer(int id, int newValue);
};