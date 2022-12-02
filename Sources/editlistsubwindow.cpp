#include "editlistsubwindow.hpp"
#include "Forms/ui_editListSubWindow.h"


editListSubWindow::editListSubWindow(QWidget *parent, BookList *list, int row) :
        QWidget(parent), ui(new Ui::editListSubWindow), bookList(list), p(list->head) {
    ui->setupUi(this);
    // 遍历私有成员指针 p 至链表所选结点
    for (int i = 0; i < row; ++i) p = p->next;
    // 把所选结点数据拷过来子窗口
    ui->priceTextEdit->setPlainText(QString::number(p->price));
    ui->ISBNTextEdit->setPlainText(QString::fromStdString(p->ISBN));
    ui->bookTextEdit->setPlainText(QString::fromStdString(p->book));
    ui->authorTextEdit->setPlainText(QString::fromStdString(p->author));
    ui->pressTextEdit->setPlainText(QString::fromStdString(p->press));
}


void editListSubWindow::on_cancelButton_clicked() {
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void editListSubWindow::on_editSaveButton_clicked() {
    p->price = ui->priceTextEdit->toPlainText().toFloat();
    p->ISBN = ui->ISBNTextEdit->toPlainText().toStdString();
    p->author = ui->authorTextEdit->toPlainText().toStdString();
    p->book = ui->bookTextEdit->toPlainText().toStdString();
    p->press = ui->pressTextEdit->toPlainText().toStdString();
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

editListSubWindow::~editListSubWindow() {
    delete ui;
}
