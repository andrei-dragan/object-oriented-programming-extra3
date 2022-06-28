#pragma once

#include "Users.h"
#include "Questions.h"
#include "Answers.h"
#include "Subject.h"

class Service : public Subject {
private:
	Users users;
	Questions questions;
	Answers answers;
public:
	Service(Users _users, Questions _questions, Answers _answers) : users{ _users }, questions{ _questions }, answers{ _answers } {};
	std::vector<User>getUsers() { return this->users.getUsers(); }
	std::vector<Answer>getAnswers() { return this->answers.getAnswers(); }
	std::vector<Question>getQuestions() { return this->questions.getQuestions(); }

	std::vector<Question>getQuestionsByAnswers();
	std::vector<Answer>getTopAnswers(int qId);

	std::vector<std::string>getQuestion(std::string str, char delimiter) { return this->questions.getQuestion(str, delimiter); }

	void addQuestion(Question q);
	void addAnswer(Answer ans);

	void voteAnswer(int id, int newValue);
};
