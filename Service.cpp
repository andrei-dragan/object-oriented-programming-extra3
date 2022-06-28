#include "Service.h"
#include <algorithm>

using namespace std;

vector <Question> Service::getQuestionsByAnswers() {
	vector<Question>questions = this->getQuestions();

	sort(questions.begin(), questions.end(), [this](Question A, Question B) {
		int nrA = 0;
		int nrB = 0;
		for (auto answer : this->getAnswers()) {
			if (answer.getQid() == A.getId()) nrA++;
			if (answer.getQid() == B.getId()) nrB++;
		}
		return (nrA > nrB);
	});

	return questions;
}

vector <Answer> Service::getTopAnswers(int qId) {
	vector<Answer>answers;

	for (auto answer : this->getAnswers()) {
		if (answer.getQid() == qId) {
			answers.push_back(answer);
		}
	}

	sort(answers.begin(), answers.end(), [](Answer A, Answer B) {
		return A.getVotes() > B.getVotes();
	});
	return answers;
}

void Service::addQuestion(Question q) {
	if (q.getText() == "") {
		throw exception{ "The question should not be left empty!" };
	}
	this->questions.addQuestion(q);
	this->notify();
}

void Service::addAnswer(Answer ans) {
	if (ans.getText() == "") {
		throw exception{ "The answer should not be left empty!" };
	}
	this->answers.addAnswer(ans);
	this->notify();
}

void Service::voteAnswer(int id, int newValue) {
	this->answers.voteAnswer(id, newValue);
	this->notify();
}