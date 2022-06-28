#include "Users.h"
#include <sstream>
#include <fstream>

using namespace std;

Users::Users() {
	this->read();
}

vector<string> Users::getUser(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string>tokens;
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void Users::read() {
	ifstream f("users.txt");
	string line;
	while (getline(f, line)) {
		vector<string>tokens = this->getUser(line, ',');
		User u{ tokens[0] };
		this->users.push_back(u);
	}
}

void Users::write() {
	ofstream g("users.txt");
	for (auto user : this->users) {
		g << user.getName() << '\n';
	}
}