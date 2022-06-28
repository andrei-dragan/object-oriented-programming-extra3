#pragma once

#include <string>

class Answer {
private:
	int id, qid, votes;
	std::string user, text;
public:
	Answer(int _id, int _qid, int _votes, std::string _user, std::string _text) : id{ _id }, qid{ _qid }, votes{ _votes }, user{ _user }, text{ _text } {};
	int getId() { return this->id; }
	int getQid() { return this->qid; }
	int getVotes() { return this->votes; }
	void setVotes(int newValue) { this->votes = newValue; }
	std::string getUser() { return this->user; }
	std::string getText() { return this->text; }
};