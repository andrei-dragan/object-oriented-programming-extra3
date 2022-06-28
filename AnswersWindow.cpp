#include "AnswersWindow.h"
#include <sstream>

using namespace std;

AnswersWindow::AnswersWindow(int _qId, std::string _user, Service& _serv, QWidget* parent)
	: qId{ _qId }, user{ _user }, serv{ _serv }, QWidget(parent)
{
	this->serv.registerObserver(this);
	ui.setupUi(this);
	this->populateList();
	this->ui.spinBox->hide();

	connect(this->ui.spinBox, &QSpinBox::valueChanged, this, &AnswersWindow::vote);
	connect(this->ui.listWidgetAns, &QListWidget::itemSelectionChanged, this, &AnswersWindow::editSpinBox);
	this->ui.listWidgetAns->setSelectionMode(QAbstractItemView::SingleSelection);
}

AnswersWindow::~AnswersWindow()
{
}

void AnswersWindow::populateList() {
	this->ui.listWidgetAns->clear();

	for (auto answer : this->serv.getAnswers()) {
		if (answer.getQid() == this->qId) {
			QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(to_string(answer.getId()) + "," + to_string(answer.getVotes()) + "," + answer.getText() + "," + answer.getUser()) };
			if (answer.getUser() == this->user) {
				item->setBackground(QBrush(Qt::yellow));
			}
			this->ui.listWidgetAns->addItem(item);
		}
	}
}

void AnswersWindow::update() {
	this->populateList();
	this->editSpinBox();
}

vector<string> AnswersWindow::tokenizeQuestion(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string>tokens;
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void AnswersWindow::vote() {
	if (this->ui.listWidgetAns->selectedItems().size() > 0) {
		string answer = this->ui.listWidgetAns->selectedItems()[0]->text().toStdString();
		vector<string>tokens = this->tokenizeQuestion(answer, ',');
		
		int newValue = this->ui.spinBox->value();
		this->serv.voteAnswer(stoi(tokens[0]), newValue);
	}
}

void AnswersWindow::editSpinBox() {
	if (this->ui.listWidgetAns->selectedItems().size() > 0) {
		this->ui.spinBox->show();
		this->ui.spinBox->setDisabled(false);
		string answer = this->ui.listWidgetAns->selectedItems()[0]->text().toStdString();
		vector<string>tokens = this->tokenizeQuestion(answer, ',');

		this->ui.spinBox->setValue(stoi(tokens[1]));
		if (this->user == tokens[3]) {
			this->ui.spinBox->setDisabled(true);
		}
	}
	else {
		this->ui.spinBox->hide();
	}
}