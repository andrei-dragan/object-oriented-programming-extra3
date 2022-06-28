#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StackOverflow.h"
#include "Service.h"
#include "SearchWindow.h"

class StackOverflow : public QMainWindow
{
    Q_OBJECT

public:
    StackOverflow(Service& _serv, QWidget *parent = Q_NULLPTR);

private:
    Service& serv;
    Ui::StackOverflowClass ui;
};
