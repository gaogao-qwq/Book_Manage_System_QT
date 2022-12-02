#include "mainmenu.hpp"
#include "Forms/ui_mainMenu.h"


mainMenu::mainMenu(QWidget *parent, BookList *list) :
        QMainWindow(parent), ui(new Ui::mainMenu), bookList(list) {
    ui->setupUi(this);
}

void mainMenu::on_createBookListButton_clicked() {
    auto w_createBook = new createBookList(nullptr, bookList);
    w_createBook->show();
    this->close();
}

void mainMenu::on_browseBookButton_clicked() {
    auto w_browsBook = new browseBook(nullptr, bookList);
    w_browsBook->show();
    this->close();
}

void mainMenu::on_editBookButton_clicked() {
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void mainMenu::on_exitSystemButton_clicked() {
    this->close();
}

mainMenu::~mainMenu() {
    delete ui;
}
