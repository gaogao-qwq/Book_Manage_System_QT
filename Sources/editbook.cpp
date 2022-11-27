#include "editbook.hpp"
#include "Forms/ui_editBook.h"


editBook::editBook(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::editBook), bookList(list), newList(nullptr) {
    ui->setupUi(this);
    newList = deepCopy(bookList);
    editBook::updateTableWidget(newList);
}


BookList *editBook::deepCopy(BookList *l) {
    auto _newList = new BookList(new BookNode(), bookList->size);
    auto p1 = _newList->head, p2 = l->head;
    p1->ISBN = p2->ISBN,
    p1->book = p2->book,
    p1->author = p2->author,
    p1->press = p2->press,
    p1->price = p2->price,
    p2 = p2->next;
    for (int i = 1; i < bookList->size; ++i) {
        p1->next = new BookNode(), p1->next->prev = p1, p1 = p1->next,
        p1->ISBN = p2->ISBN,
        p1->book = p2->book,
        p1->author = p2->author,
        p1->press = p2->press,
        p1->price = p2->price,
        p2 = p2->next;
    }
    return _newList;
}

void editBook::updateTableWidget(BookList *l) {
    ui->bookTable->clearContents();
    BookNode *p = l->head;
    ui->bookTable->setRowCount(l->size);
    for (int row = 0; row < l->size; ++row) {
        int col = 0;
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(p->ISBN)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(p->book)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(p->author)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::number(p->price)));
        ui->bookTable->setItem(row, col, new QTableWidgetItem(QString::fromStdString(p->press)));
        p = p->next;
    }
}

void editBook::debugPrintList(BookList *l) {
    auto p = l->head;
    for (int i = 0; i < l->size; ++i, p = p->next)
        qDebug() << QString::number(p->price) << " ";
}

void editBook::on_sortByPriceButton_clicked() {
    newList->head = newList->sortByPrice(newList->head);
    editBook::updateTableWidget(newList);
}

void editBook::on_backButton_clicked() {
    auto w_mainMenu = new Main_Menu(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

void editBook::on_backSaveButton_clicked() {
    auto w_mainMenu = new Main_Menu(nullptr, newList);
    w_mainMenu->show();
    this->close();
}

editBook::~editBook() {
    delete ui;
}



