#include "Subject.h"

using namespace std;

void Subject::registerObserver(Observer* ob) {
	this->observers.push_back(ob);
}

void Subject::notify() {
	for (auto observer : this->observers) {
		observer->update();
	}
}


