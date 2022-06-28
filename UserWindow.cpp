#include "UserWindow.h"
#include <QMessageBox>

using namespace std;

UserWindow::UserWindow(string _user, Service& _serv, QWidget *parent)
	: user{_user}, serv{ _serv }, QWidget(parent)
{
	this->serv.registerObserver(this);
	ui.setupUi(this);
	this->populateList();

	connect(this->ui.pushButtonAdd, &QPushButton::clicked, this, &UserWindow::addQuestion);
	connect(this->ui.listWidgetQs, &QListWidget::itemClicked, this, &UserWindow::openAnswers);
	connect(this->ui.pushButtonAnswer, &QPushButton::clicked, this, &UserWindow::addAnswer);

	this->ui.listWidgetQs->setSelectionMode(QAbstractItemView::SingleSelection);
}

UserWindow::~UserWindow()
{
}

void UserWindow::populateList() {

	this->ui.listWidgetQs->clear();

	vector<Question>questions = this->serv.getQuestionsByAnswers();
	for (auto question : questions) {
		this->ui.listWidgetQs->addItem(QString::fromStdString(to_string(question.getId()) + "," + question.getText() + "," + question.getUser()));
	}
}

void UserWindow::update() {
	this->populateList();
}

void UserWindow::addQuestion() {
	string text = this->ui.lineEditQ->text().toStdString();

	int id = -1;
	bool found = true;
	while (found) {
		found = false;
		id = rand() % 500;
		for (auto question : this->serv.getQuestions()) {
			if (question.getId() == id) found = true;
		}
	}

	Question q{ id, text, this->user };
	try {
		this->serv.addQuestion(q);
		this->ui.lineEditQ->clear();
	}
	catch (exception& e) {
		QMessageBox* error = new QMessageBox{};
		error->setText(QString::fromStdString(e.what()));
		error->show();
		this->ui.lineEditQ->clear();
		return;
	}
}

void UserWindow::openAnswers() {
	if (this->ui.listWidgetQs->selectedItems().size() > 0) {
		string question = this->ui.listWidgetQs->selectedItems()[0]->text().toStdString();
		vector<string>tokens = this->serv.getQuestion(question, ',');
		AnswersWindow* w = new AnswersWindow{ stoi(tokens[0]), this->user, this->serv };
		w->show();
	}
}

void UserWindow::addAnswer() {
	if (this->ui.listWidgetQs->selectedItems().size() > 0) {
		string question = this->ui.listWidgetQs->selectedItems()[0]->text().toStdString();
		vector<string>tokens = this->serv.getQuestion(question, ',');
		
		string text = this->ui.lineEditAns->text().toStdString();

		int id = -1;
		bool found = true;
		while (found) {
			found = false;
			id = rand() % 500;
			for (auto answer : this->serv.getAnswers()) {
				if (answer.getId() == id) found = true;
			}
		}

		Answer ans{ id, stoi(tokens[0]), 0, this->user, text };
		try {
			this->serv.addAnswer(ans);
			this->ui.lineEditAns->clear();
		}
		catch (exception& e) {
			QMessageBox* error = new QMessageBox{};
			error->setText(QString::fromStdString(e.what()));
			error->show();
			this->ui.lineEditAns->clear();
			return;
		}
	}

}