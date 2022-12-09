#include "insertlistsubwindow.hpp"
#include "Forms/ui_insertListSubWindow.h"


insertListSubWindow::insertListSubWindow(QWidget *parent, BookList *list, int row) :
        QWidget(parent), ui(new Ui::insertListSubWindow), bookList(list), p(list->head) {
    ui->setupUi(this);
    // 遍历私有成员指针 p 至链表所选结点
    for (int i = 0; i < row; ++i) p = p->next;
}

void insertListSubWindow::insertAtFront(BookList *l) {
    // 对于头插头结点
    if (p->prev == nullptr) {
        p->prev = new BookNode(
            ui->priceTextEdit->toPlainText().toFloat(),
            ui->ISBNTextEdit->toPlainText().toStdString(),
            ui->bookTextEdit->toPlainText().toStdString(),
            ui->authorTextEdit->toPlainText().toStdString(),
            ui->priceTextEdit->toPlainText().toStdString(),
            p, nullptr
        );
        l->head = l->head->prev;
        ++l->size;
        return;
    }
    auto newNode = new BookNode(
        ui->priceTextEdit->toPlainText().toFloat(),
        ui->ISBNTextEdit->toPlainText().toStdString(),
        ui->bookTextEdit->toPlainText().toStdString(),
        ui->authorTextEdit->toPlainText().toStdString(),
        ui->priceTextEdit->toPlainText().toStdString(),
        p, p->prev
    );
    p->prev->next = newNode, p->prev = newNode;
    ++l->size;
}

void insertListSubWindow::insertAtBack(BookList *l) {
    // 对于尾插尾结点
    if (p->next == nullptr) {
        p->next = new BookNode(
            ui->priceTextEdit->toPlainText().toFloat(),
            ui->ISBNTextEdit->toPlainText().toStdString(),
            ui->bookTextEdit->toPlainText().toStdString(),
            ui->authorTextEdit->toPlainText().toStdString(),
            ui->priceTextEdit->toPlainText().toStdString(),
            nullptr, p
        );
        ++l->size;
        return;
    }
    auto newNode = new BookNode(
        ui->priceTextEdit->toPlainText().toFloat(),
        ui->ISBNTextEdit->toPlainText().toStdString(),
        ui->bookTextEdit->toPlainText().toStdString(),
        ui->authorTextEdit->toPlainText().toStdString(),
        ui->priceTextEdit->toPlainText().toStdString(),
        p->next, p
    );
    p->next->prev = newNode, p->next = newNode;
    ++l->size;
}

void insertListSubWindow::on_cancelButton_clicked() {
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void insertListSubWindow::on_insertAtFrontButton_clicked() {
    insertAtFront(bookList);
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void insertListSubWindow::on_insertAtBackButton_clicked() {
    insertAtBack(bookList);
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

insertListSubWindow::~insertListSubWindow() {
    delete ui;
}
