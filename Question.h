#pragma once

#include <string>

class Question {
private:
	int id;
	std::string text, user;
public:
	Question(int _id, std::string _text, std::string _user) : id{ _id }, text{ _text }, user{ _user } {};
	int getId() { return this->id; }
	std::string getText() { return this->text; }
	std::string getUser() { return this->user; }
};