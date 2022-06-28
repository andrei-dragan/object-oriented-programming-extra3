#pragma once

#include <QWidget>
#include "ui_AnswersWindow.h"
#include "Observer.h"
#include "Service.h"

class AnswersWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	AnswersWindow(int _qId, std::string _user, Service& _serv, QWidget *parent = Q_NULLPTR);
	~AnswersWindow();

private:
	int qId;
	std::string user;
	Service& serv;
	Ui::AnswersWindow ui;

public:
	void populateList();
	void update() override;
	void vote();
	void editSpinBox();
	std::vector<std::string> tokenizeQuestion(std::string, char delimiter);
};
