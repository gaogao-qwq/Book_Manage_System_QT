#include "createbooklist.hpp"
#include "Forms/ui_createBookList.h"


createBookList::createBookList(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::createBookList), bookList(list) {
    ui->setupUi(this);
}

void createBookList::on_backButton_clicked() {
    auto w_mainMenu = new mainMenu(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

void createBookList::on_backSaveButton_clicked() {
    // 若原图书表存在（长度大于 0）弹出警告
    if (bookList->size > 0) {
        // 由于 QT6.2 已经弃用了旧的 StandardButton，所以这里要用 StandardButtons 形参的 warning() 重载函数
        if (QMessageBox::StandardButton::No == QMessageBox::warning(
                this,
                "注意",
                "目前图书表中存在数据，继续此操作会覆盖原图书表，是否继续？",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No)
        )) return;
    }
    auto w_mainMenu = new mainMenu(nullptr, newList);
    w_mainMenu->show();
    this->close();
}

void createBookList::on_inputButton_clicked() {
    if (newList->size == 0) {
        p->price = ui->priceTextEdit->toPlainText().toFloat(),
        p->ISBN = ui->ISBNTextEdit->toPlainText().toStdString(),
        p->book = ui->bookTextEdit->toPlainText().toStdString(),
        p->author = ui->authorTextEdit->toPlainText().toStdString(),
        p->press = ui->pressTextEdit->toPlainText().toStdString(),
        ++newList->size;
        ui->priceTextEdit->clear();
        ui->ISBNTextEdit->clear();
        ui->bookTextEdit->clear();
        ui->authorTextEdit->clear();
        ui->pressTextEdit->clear();
        return;
    }
    p->next = new BookNode(
        ui->priceTextEdit->toPlainText().toFloat(),
        ui->ISBNTextEdit->toPlainText().toStdString(),
        ui->bookTextEdit->toPlainText().toStdString(),
        ui->authorTextEdit->toPlainText().toStdString(),
        ui->pressTextEdit->toPlainText().toStdString(),
        nullptr, p
    );
    ++newList->size, p = p->next;
    ui->priceTextEdit->clear();
    ui->ISBNTextEdit->clear();
    ui->bookTextEdit->clear();
    ui->authorTextEdit->clear();
    ui->pressTextEdit->clear();
}

createBookList::~createBookList() {
    delete ui;
}
