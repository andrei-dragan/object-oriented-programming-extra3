#pragma once

#include <QWidget>
#include "ui_UserWindow.h"
#include "Service.h"
#include "Observer.h"
#include "AnswersWindow.h"

class UserWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	UserWindow(std::string _user, Service& _serv, QWidget *parent = Q_NULLPTR);
	~UserWindow();

private:
	std::string user;
	Service& serv;
	Ui::UserWindow ui;

public:
	void populateList();
	void update() override;
	void addQuestion();
	void openAnswers();
	void addAnswer();
};
