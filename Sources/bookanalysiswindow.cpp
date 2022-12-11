#include "bookanalysiswindow.hpp"
#include "Forms/ui_bookAnalysisWindow.h"


bookAnalysisWindow::bookAnalysisWindow(QWidget *parent, BookList *list) :
        QWidget(parent), ui(new Ui::bookAnalysisWindow), bookList(list) {
    ui->setupUi(this);
    // 不允许编辑
    ui->pressBookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->authorBookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->bookCountLabel->setText(QString::fromStdString("图书表中共有 " + std::to_string(bookList->size) + "本书"));
    // 遍历链表并构建 unordered_map
    auto p = bookList->head;
    for (int i = 0; i < bookList->size; ++i) {
        press[p->press].push_back(p);
        author[p->author].push_back(p);
        p = p->next;
    }
    ui->pressCountLabel->setText(QString::fromStdString("共有 " + std::to_string(press.size()) + "个出版社"));
    ui->authorCountLabel->setText(QString::fromStdString("共有 " + std::to_string(author.size()) + "位作者"));
    // 遍历 unordered_map 并添加 comboBox 下拉选项
    for (const std::pair<const std::string, std::vector<BookNode *>> &i : press)
        ui->pressComboBox->addItem(QString::fromStdString(i.first));
    for (const std::pair<const std::string, std::vector<BookNode *>> &i : author)
        ui->authorComboBox->addItem(QString::fromStdString(i.first));
}

void bookAnalysisWindow::on_pressComboBox_currentTextChanged(const QString &text) {
    ui->selectedPressCountLabel->setText(QString::fromStdString("所选出版社共有 " + std::to_string(press[text.toStdString()].size()) + "本书"));
    ui->pressBookTable->clearContents();
    ui->pressBookTable->setRowCount((int)press[text.toStdString()].size());
    int row = 0;
    for (BookNode *i : press[text.toStdString()]) {
        int col = 0;
        ui->pressBookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(i->ISBN)));
        ui->pressBookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(i->book)));
        ui->pressBookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(i->author)));
        ui->pressBookTable->setItem(row, col, new QTableWidgetItem(QString::number(i->price)));
        ++row;
    }
    ui->pressBookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void bookAnalysisWindow::on_authorComboBox_currentTextChanged(const QString &text) {
    ui->selectedAuthorCountLabel->setText(QString::fromStdString("所选作者共有 " + std::to_string(author[text.toStdString()].size()) + "本书"));
    ui->authorBookTable->clearContents();
    ui->authorBookTable->setRowCount((int)author[text.toStdString()].size());
    int row = 0;
    for (BookNode *i : author[text.toStdString()]) {
        int col = 0;
        ui->authorBookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(i->ISBN)));
        ui->authorBookTable->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(i->book)));
        ui->authorBookTable->setItem(row, col++, new QTableWidgetItem(QString::number(i->price)));
        ui->authorBookTable->setItem(row, col, new QTableWidgetItem(QString::fromStdString(i->author)));
        ++row;
    }
    ui->authorBookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void bookAnalysisWindow::on_exitButton_clicked() {
    auto w_mainMenu = new mainMenu(nullptr, bookList);
    w_mainMenu->show();
    this->close();
}

bookAnalysisWindow::~bookAnalysisWindow() {
    delete ui;
}
