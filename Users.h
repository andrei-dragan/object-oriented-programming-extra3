#pragma once

#include "User.h"
#include <vector>

class Users {
private:
	std::vector<User>users;
public:
	Users();
	void read();
	void write();
	std::vector<std::string>getUser(std::string str, char delimiter);

	std::vector<User>getUsers() { return this->users; }
};