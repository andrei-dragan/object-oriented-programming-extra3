#include "StackOverflow.h"
#include <QtWidgets/QApplication>

#include "Users.h"
#include "Questions.h"
#include "Answers.h"
#include "Service.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);

    Users users;
    Questions questions;
    Answers answers;

    Service serv{ users, questions, answers };
    StackOverflow w{serv};
    return a.exec();
}
