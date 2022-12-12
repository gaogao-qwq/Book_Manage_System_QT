#include "deduplicatelistsubwindow.hpp"
#include "Forms/ui_deduplicatelistSubWindow.h"


deduplicateListSubWindow::deduplicateListSubWindow(QWidget *parent, BookList *list, const std::unordered_set<std::string>& duplicatedISBN) :
        QWidget(parent), ui(new Ui::deduplicateListSubWindow), bookList(list) {
    ui->setupUi(this);
    // 只允许选中一行
    ui->bookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookTable->setSelectionMode(QAbstractItemView::SingleSelection);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 深拷贝
    newList = deepCopy(bookList);
    auto p = newList->head;
    for (int i = 0; i < newList->size; ++i) {
        if (duplicatedISBN.find(p->ISBN) != duplicatedISBN.end())
            duplicatedNode.push_back(p);
        p = p->next;
    }
    updateTableWidget();
}

BookList *deduplicateListSubWindow::deepCopy(BookList *l) {
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

void deduplicateListSubWindow::deleteNode(int row) {
    // 对于删除头结点
    if (duplicatedNode[row]->prev == nullptr) {
        newList->head = newList->head->next;
        // 当头结点不为最后一个结点时
        if (newList->head != nullptr) newList->head->prev = nullptr;
        duplicatedNode.erase(duplicatedNode.begin() + row);
        --newList->size;
        return;
    }
    // 对于删除尾结点
    if (duplicatedNode[row]->next == nullptr) {
        duplicatedNode[row]->prev->next = nullptr;
        duplicatedNode.erase(duplicatedNode.begin() + row);
        --newList->size;
        return;
    }
    duplicatedNode[row]->prev->next = duplicatedNode[row]->next;
    duplicatedNode[row]->next->prev = duplicatedNode[row]->prev;
    duplicatedNode.erase(duplicatedNode.begin() + row);
    --newList->size;
}

void deduplicateListSubWindow::updateTableWidget() {
    // 更新 label
    ui->label->setText(QString::fromStdString("共有 " + std::to_string(duplicatedNode.size()) + "本 ISBN 重复的图书"));

    // 更新 bookTable
    ui->bookTable->clearContents();
    ui->bookTable->setRowCount((int)duplicatedNode.size());
    for (int row = 0; row < duplicatedNode.size(); ++row) {
        int col = 0;
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(duplicatedNode[row]->ISBN)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(duplicatedNode[row]->book)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(duplicatedNode[row]->author)));
        ui->bookTable->setItem(row, col++, new QTableWidgetItem(QString::number(duplicatedNode[row]->price)));
        ui->bookTable->setItem(row, col, new QTableWidgetItem(QString::fromStdString(duplicatedNode[row]->press)));
    }
}

void deduplicateListSubWindow::on_deleteButton_clicked() {
    auto items = ui->bookTable->selectedItems();
    if (items.empty()) {
        auto w_goodNews = new goodNews(this, "请先在右侧列表中选择你要删除的图书行");
        w_goodNews->show();
        return;
    }
    deleteNode(items.at(0)->row());
    updateTableWidget();
}

void deduplicateListSubWindow::on_backButton_clicked() {
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void deduplicateListSubWindow::on_backSaveButton_clicked() {
    auto w_editBook = new editBook(nullptr, newList);
    w_editBook->show();
    this->close();
}

deduplicateListSubWindow::~deduplicateListSubWindow() {
    delete ui;
}
