#include "createbooklist.hpp"
#include "Forms/ui_createBookList.h"


createBookList::createBookList(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::createBookList), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 铺满表格
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
                "喜报",
                "目前图书表中存在数据，继续此操作会覆盖原图书表，是否继续？",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No)
        )) return;
    }
    auto w_mainMenu = new mainMenu(nullptr, newList);
    w_mainMenu->show();
    this->close();
}

void createBookList::on_inputButton_clicked() {
    if (newList->size != 0) {
        p->next = new BookNode(0, "", "", "", "", nullptr, p);
        p = p->next;
    }
    p->price = ui->priceTextEdit->toPlainText().toFloat(),
    p->ISBN = ui->ISBNTextEdit->toPlainText().toStdString(),
    p->book = ui->bookTextEdit->toPlainText().toStdString(),
    p->author = ui->authorTextEdit->toPlainText().toStdString(),
    p->press = ui->pressTextEdit->toPlainText().toStdString(),
    ++newList->size;
    // 添加至左侧预览框
    ui->bookTable->setRowCount(newList->size);
    int col = 0;
    ui->bookTable->setItem(newList->size - 1, col++, new QTableWidgetItem(ui->ISBNTextEdit->toPlainText()));
    ui->bookTable->setItem(newList->size - 1, col++, new QTableWidgetItem(ui->bookTextEdit->toPlainText()));
    ui->bookTable->setItem(newList->size - 1, col++, new QTableWidgetItem(ui->authorTextEdit->toPlainText()));
    ui->bookTable->setItem(newList->size - 1, col++, new QTableWidgetItem(ui->priceTextEdit->toPlainText()));
    ui->bookTable->setItem(newList->size - 1, col, new QTableWidgetItem(ui->pressTextEdit->toPlainText()));
    // 清除 textEdit
    ui->priceTextEdit->clear();
    ui->ISBNTextEdit->clear();
    ui->bookTextEdit->clear();
    ui->authorTextEdit->clear();
    ui->pressTextEdit->clear();
}

createBookList::~createBookList() {
    delete ui;
}
