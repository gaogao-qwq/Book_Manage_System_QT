#include "forms/editBookWindow.hpp"
#include "ui_editBookWindow.h"

editBookWindow::editBookWindow(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::editBookWindow), bookList(list), newList(nullptr) {
    ui->setupUi(this);
    // 只允许选中一行
    ui->bookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookTable->setSelectionMode(QAbstractItemView::SingleSelection);
    // 不允许编辑
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 深拷贝
    newList = deepCopy(bookList);
    editBookWindow::updateTableWidget(newList);
    if (Convert::getPinYinMap(m_pinyin) == -1) {
        auto w_goodNews = new goodNewsWindow(this, "找不到或不存在拼音字库文件 pinyin.txt");
        w_goodNews->show();
    }
}


BookList *editBookWindow::deepCopy(BookList *l) {
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

void editBookWindow::updateTableWidget(BookList *l) {
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

void editBookWindow::debugPrintList(BookList *l) {
    auto p = l->head;
    for (int i = 0; i < l->size; ++i, p = p->next)
        qDebug() << QString::number(p->price) << " ";
}

BookNode *editBookWindow::sortByPrice(BookNode *h) {
    // 分割递归终止条件
    if(h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while(fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后慢指针指向链表中间结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr, tmp->prev = nullptr;
    auto left = sortByPrice(h);
    auto right = sortByPrice(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    // 因为是双链表，所以要把结点缓存下来方便前向指针的更新
    BookNode *prevTmp = nullptr;
    while(left != nullptr && right != nullptr) {
        if(left->price < right->price) {
            _h->next = left;
            prevTmp = left;
            left = left->next;
        } else {
            _h->next = right;
            prevTmp = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right, _h->next->prev = prevTmp;
    return res->next;
}

BookNode *editBookWindow::sortByISBN(BookNode *h) {
    // 分割递归终止条件
    if (h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后慢指针指向链表中间结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr, tmp->prev = nullptr;
    auto left = sortByISBN(h);
    auto right = sortByISBN(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    // 因为是双链表，所以要把结点缓存下来方便前向指针的更新
    BookNode *prevTmp = nullptr;
    while (left != nullptr && right != nullptr) {
        if (left->ISBN < right->ISBN) {
            _h->next = left;
            prevTmp = left;
            left = left->next;
        } else {
            _h->next = right;
            prevTmp = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right, _h->next->prev = prevTmp;
    return res->next;
}

BookNode *editBookWindow::sortByBook(BookNode *h) {
    // 分割递归终止条件
    if (h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后慢指针指向链表中间结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr, tmp->prev = nullptr;
    auto left = sortByBook(h);
    auto right = sortByBook(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    // 因为是双链表，所以要把结点缓存下来方便前向指针的更新
    BookNode *prevTmp = nullptr;
    while (left != nullptr && right != nullptr) {
        if (Convert::convertZhToPinyin(left->book, m_pinyin) < Convert::convertZhToPinyin(right->book, m_pinyin)) {
            _h->next = left;
            prevTmp = left;
            left = left->next;
        } else {
            _h->next = right;
            prevTmp = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right, _h->next->prev = prevTmp;
    return res->next;
}

BookNode *editBookWindow::sortByAuthor(BookNode *h) {
    // 分割递归终止条件
    if (h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后慢指针指向链表中间结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr, tmp->prev = nullptr;
    auto left = sortByAuthor(h);
    auto right = sortByAuthor(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    // 因为是双链表，所以要把结点缓存下来方便前向指针的更新
    BookNode *prevTmp = nullptr;
    while (left != nullptr && right != nullptr) {
        if (Convert::convertZhToPinyin(left->author, m_pinyin) < Convert::convertZhToPinyin(right->author, m_pinyin)) {
            _h->next = left;
            prevTmp = left;
            left = left->next;
        } else {
            _h->next = right;
            prevTmp = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right, _h->next->prev = prevTmp;
    return res->next;
}

BookNode *editBookWindow::sortByPress(BookNode *h) {
    // 分割递归终止条件
    if (h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后慢指针指向链表中间结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr, tmp->prev = nullptr;
    auto left = sortByPress(h);
    auto right = sortByPress(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    // 因为是双链表，所以要把结点缓存下来方便前向指针的更新
    BookNode *prevTmp = nullptr;
    while (left != nullptr && right != nullptr) {
        if (Convert::convertZhToPinyin(left->press, m_pinyin) < Convert::convertZhToPinyin(right->press, m_pinyin)) {
            _h->next = left;
            prevTmp = left;
            left = left->next;
        } else {
            _h->next = right;
            prevTmp = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right, _h->next->prev = prevTmp;
    return res->next;
}

void editBookWindow::deleteNode(BookList *l, int row) {
    auto p = l->head;
    if (row > l->size) {
        auto w_goodNews = new goodNewsWindow(this, "所选择要编辑的图书行数超出了链表长度，请重新输入！");
        w_goodNews->show();
        return;
    }
    for (int i = 0; i < row; ++i) p = p->next;
    // 对于删除头结点
    if (p->prev == nullptr) {
        l->head = l->head->next;
        // 当头结点不为最后一个结点时
        if (l->head != nullptr) l->head->prev = nullptr;
        --newList->size;
        delete(p);
        return;
    }
    // 对于删除尾结点
    if (p->next == nullptr) {
        p->prev->next = nullptr;
        --newList->size;
        delete(p);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    --newList->size;
    delete(p);
}


void editBookWindow::on_sortByPriceButton_clicked() {
    newList->head = editBookWindow::sortByPrice(newList->head);
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_sortByISBNButton_clicked() {
    newList->head = editBookWindow::sortByISBN(newList->head);
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_sortByBookButton_clicked() {
    newList->head = editBookWindow::sortByBook(newList->head);
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_sortByAuthorButton_clicked() {
    newList->head = editBookWindow::sortByAuthor(newList->head);
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_sortByPressButton_clicked() {
    newList->head = editBookWindow::sortByPress(newList->head);
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_editButton_clicked() {
    auto items = ui->bookTable->selectedItems();
    if (items.empty()) {
        auto w_goodNews = new goodNewsWindow(this, "请先在右侧列表中选择你要编辑的图书行");
        w_goodNews->show();
        return;
    }
    auto w_editListSubWindow = new editListSubWindow(nullptr, newList, (int)items.at(0)->row());
    w_editListSubWindow->show();
    this->close();
}

void editBookWindow::on_deleteButton_clicked() {
    auto items = ui->bookTable->selectedItems();
    if (items.empty()) {
        auto w_goodNews = new goodNewsWindow(this, "请先在右侧列表中选择你要编辑的图书行");
        w_goodNews->show();
        return;
    }
    editBookWindow::deleteNode(newList, (int) items.at(0)->row());
    editBookWindow::updateTableWidget(newList);
}

void editBookWindow::on_insertButton_clicked() {
    auto items = ui->bookTable->selectedItems();
    if (items.empty()) {
        auto w_goodNews = new goodNewsWindow(this, "请先在右侧列表中选择你要编辑的图书行");
        w_goodNews->show();
        return;
    }
    auto w_insertListSubWindow = new insertListSubWindow(nullptr, newList, items.at(0)->row());
    w_insertListSubWindow->show();
    this->close();
}

void editBookWindow::on_deduplicateButton_clicked() {
    std::unordered_set<std::string> unorderedSet, duplicatedISBN;
    auto p = newList->head;
    for (int i = 0; i < newList->size; ++i) {
        if (unorderedSet.find(p->ISBN) != unorderedSet.end()) {
            duplicatedISBN.emplace(p->ISBN);
            p = p->next;
            continue;
        }
        unorderedSet.emplace(p->ISBN);
        p = p->next;
    }
    if (duplicatedISBN.empty()) {
        auto w_goodNews = new goodNewsWindow(this, "没有找到 ISBN 相同的书本");
        w_goodNews->show();
        return;
    }
    auto w_deduplicateListSubWindow = new deduplicateListSubWindow(nullptr, newList, duplicatedISBN);
    w_deduplicateListSubWindow->show();
    this->close();
}

void editBookWindow::on_backButton_clicked() {
    auto w_mainMenu = new main_menu_window(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

void editBookWindow::on_backSaveButton_clicked() {
    auto w_mainMenu = new main_menu_window(nullptr, newList);
    w_mainMenu->show();
    this->close();
}


editBookWindow::~editBookWindow() {
    delete ui;
}

