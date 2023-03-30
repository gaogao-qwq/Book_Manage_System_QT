#include "forms/browseBookWindow.hpp"
#include "ui_browseBookWindow.h"


browseBookWindow::browseBookWindow(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::browseBookWindow), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 铺满表格
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    browseBookWindow::updateTableWidget(bookList);
}

void browseBookWindow::updateTableWidget(BookList *l) {
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

void browseBookWindow::on_backButton_clicked() {
    auto w_mainMenu = new main_menu_window(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

browseBookWindow::~browseBookWindow() {
    delete ui;
}
