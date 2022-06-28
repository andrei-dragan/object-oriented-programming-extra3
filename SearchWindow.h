#pragma once

#include <QWidget>
#include "ui_SearchWindow.h"
#include "Service.h"
#include "Observer.h"

class SearchWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	SearchWindow(Service& _serv, QWidget *parent = Q_NULLPTR);
	~SearchWindow();

private:
	Service& serv;
	Ui::SearchWindow ui;

public:
	void showResults();
	void update() override;
};
