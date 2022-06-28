#include "StackOverflow.h"
#include "UserWindow.h"

StackOverflow::StackOverflow(Service& _serv, QWidget *parent)
    : serv{ _serv }, QMainWindow(parent)
{
    ui.setupUi(this);

    SearchWindow* w = new SearchWindow{ this->serv };
    w->show();

    for (auto user : this->serv.getUsers()) {
        UserWindow* w = new UserWindow{ user.getName(), this->serv };
        w->setWindowTitle(QString::fromStdString(user.getName()));
        w->show();
    }
}
