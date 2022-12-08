#include "searchbook.hpp"
#include "Forms/ui_searchBook.h"


searchBook::searchBook(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::searchBook), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void searchBook::updateTableWidget(std::vector<BookNode *> searchResult) {
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
    // 自动调整列宽并填充表格
    for (int i = 0; i < 5; ++i) {
        if (i == 1)
            ui->bookTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        else
            ui->bookTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

void searchBook::on_searchButton_clicked() {
    std::string str = ui->searchTextEdit->toPlainText().toStdString();
    if (str.empty()) {
        QMessageBox::warning(
            this,
            "喜报",
            "请先在搜索框中输入要搜索的内容",
            QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
            QMessageBox::StandardButton::Ok
        );
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
    ui->searchCountlabel->setAlignment(Qt::AlignVCenter);
    updateTableWidget(searchResult);
}

void searchBook::on_backButton_clicked() {
    auto w_mainMenu = new mainMenu(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

searchBook::~searchBook() {
    delete ui;
}