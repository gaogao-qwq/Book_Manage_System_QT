#include "main_menu.hpp"
#include "Forms/ui_Main_Menu.h"


// 构造函数
Main_Menu::Main_Menu(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::Main_Menu), bookList(list) {
    ui->setupUi(this);
}

void Main_Menu::on_createBookListButton_clicked() {
    auto w_createBook = new createBookList(nullptr, bookList);
    w_createBook->show();
    this->close();
}

void Main_Menu::on_browsBookButton_clicked() {
    auto w_browseBook = new browseBook(nullptr, bookList);
    w_browseBook->show();
    this->close();
}

void Main_Menu::on_editBookButton_clicked() {
    if (bookList->size == 0) {
        QMessageBox::warning(
            this,
            "喜报",
            "图书表为空或不存在",
            QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
            QMessageBox::StandardButton::Ok
        );
        return;
    }
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void Main_Menu::on_exitSystemButton_clicked() {
    this->close();
}

Main_Menu::~Main_Menu() {
    delete ui;
}
