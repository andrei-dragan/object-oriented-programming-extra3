#include "SearchWindow.h"
#include <cmath>

using namespace std;

SearchWindow::SearchWindow(Service& _serv, QWidget *parent)
	: serv{ _serv }, QWidget(parent)
{
	this->serv.registerObserver(this);
	ui.setupUi(this);
	connect(this->ui.lineEditsearchQ, &QLineEdit::textChanged, this, &SearchWindow::showResults);
}

SearchWindow::~SearchWindow()
{
}

void SearchWindow::showResults() {
	this->ui.listWidget->clear();

	string searchText = this->ui.lineEditsearchQ->text().toStdString();
	int maxMatchingLetters = 0;
	int qId = -1;

	for (auto question : this->serv.getQuestions()) {
		int n = question.getText().length();
		int m = searchText.length();
		int matchingLetters = 0;
		for (int i = 0; i < min(n, m); i++) {
			if (searchText[i] != ' ' && searchText[i] == question.getText()[i]) matchingLetters++;
		}
		if (matchingLetters > maxMatchingLetters) {
			maxMatchingLetters = matchingLetters;
			qId = question.getId();
		}
	}

	if (maxMatchingLetters > 0) {
		for (auto question : this->serv.getQuestions()) {
			if (question.getId() == qId) {
				this->ui.listWidget->addItem(QString::fromStdString(to_string(question.getId()) + "," + question.getText() + "," + question.getUser()));
				break;
			}
		}

		vector<Answer>answers = this->serv.getTopAnswers(qId);

		int i = 0;
		for (auto answer : answers) {
			i++; 
			this->ui.listWidget->addItem(QString::fromStdString("\t" + to_string(answer.getId()) + "," + to_string(answer.getQid()) + "," + to_string(answer.getVotes()) + "," + answer.getText() + "," + answer.getUser()));
			if (i == 3) break;
		}
	}
}

void SearchWindow::update() {
	this->showResults();
}