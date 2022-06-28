#include "Questions.h"
#include <fstream>
#include <sstream>

using namespace std;

Questions::Questions() {
	this->read();
}

vector<string> Questions::getQuestion(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string>tokens;
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void Questions::read() {
	ifstream f("questions.txt");
	string line;
	while (getline(f, line)) {
		vector<string>tokens = this->getQuestion(line, ',');
		Question q{ stoi(tokens[0]), tokens[1], tokens[2] };
		this->questions.push_back(q);
	}
}

void Questions::write() {
	ofstream g("questions.txt");
	for (auto question : this->questions) {
		g << to_string(question.getId()) + "," + question.getText() + "," + question.getUser() << '\n';
	}
}

void Questions::addQuestion(Question q) {
	this->questions.push_back(q);
	this->write();
}