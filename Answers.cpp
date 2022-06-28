#include "Answers.h"
#include <sstream>
#include <fstream>

using namespace std;

Answers::Answers() {
	this->read();
}

vector<string> Answers::getAnswer(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string>tokens;
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void Answers::read() {
	ifstream f("answers.txt");
	string line;
	while (getline(f, line)) {
		vector<string> tokens = this->getAnswer(line, ',');
		Answer a{ stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]), tokens[3], tokens[4] };
		this->answers.push_back(a);
	}
}

void Answers::write() {
	ofstream g("answers.txt");
	for (auto answer : this->answers) {
		g << to_string(answer.getId()) + "," + to_string(answer.getQid()) + "," + to_string(answer.getVotes()) + "," + answer.getUser() + "," + answer.getText() << '\n';
	}
}

void Answers::addAnswer(Answer ans) {
	this->answers.push_back(ans);
	this->write();
}

void Answers::voteAnswer(int id, int newValue) {
	for (int i = 0; i < this->answers.size(); i++) {
		if (this->answers[i].getId() == id) {
			this->answers[i].setVotes(newValue);
		}
	}
	this->write();
}