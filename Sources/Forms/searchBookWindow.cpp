#include "forms/searchBookWindow.hpp"
#include "ui_searchBookWindow.h"


searchBookWindow::searchBookWindow(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::searchBookWindow), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void searchBookWindow::updateTableWidget(std::vector<BookNode *> searchResult) {
    ui->bookTable->clearContents();
    ui->bookTable->setRowCount((int)searchResult.size());
    for (int row = 0; row < searchResult.size(); ++row) {
        int col = 0;
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(searchResult[row]->ISBN)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(searchResult[row]->book)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(searchResult[row]->author)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::number(searchResult[row]->price)));
        ui->bookTable->setItem(row, col, new QTableWidgetItem(QString::fromStdString(searchResult[row]->press)));
    }
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void searchBookWindow::on_searchButton_clicked() {
    std::string str = ui->searchTextEdit->toPlainText().toStdString();
    if (str.empty()) {
        auto w_goodNews = new goodNewsWindow(this, "请先在搜索框中输入要搜索的内容");
        w_goodNews->show();
        return;
    }
    std::vector<BookNode *> searchResult;
    auto p = bookList->head;
    for (int i = 0; i < bookList->size; ++i) {
        if (str == p->ISBN || str == p->book || str == p->author || str == std::to_string(p->price) || str == p->press)
            searchResult.push_back(p);
        p = p->next;
    }
    ui->searchCountlabel->setText(QString::fromStdString("共找到 " + std::to_string(searchResult.size()) + "本符合搜索条件的书本"));
    updateTableWidget(searchResult);
}

void searchBookWindow::on_backButton_clicked() {
    auto w_mainMenu = new main_menu_window(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

searchBookWindow::~searchBookWindow() {
    delete ui;
}
