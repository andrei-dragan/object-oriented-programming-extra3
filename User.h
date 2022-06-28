#pragma once

#include <string>

class User {
private:
	std::string name;
public:
	User(std::string _name) : name{ _name } {};
	std::string getName() { return this->name; }
};