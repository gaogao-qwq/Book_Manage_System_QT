#include "browsebook.hpp"
#include "Forms/ui_browseBook.h"


browseBook::browseBook(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::browseBook), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    browseBook::updateTableWidget(bookList);
}

void browseBook::updateTableWidget(BookList *l) {
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
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void browseBook::on_backButton_clicked() {
    auto w_mainMenu = new mainMenu(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

browseBook::~browseBook() {
    delete ui;
}
