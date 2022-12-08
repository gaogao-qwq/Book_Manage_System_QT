#include "mainmenu.hpp"
#include "Forms/ui_mainMenu.h"


mainMenu::mainMenu(QWidget *parent, BookList *list) :
        QMainWindow(parent), ui(new Ui::mainMenu), bookList(list) {
    ui->setupUi(this);
}

void mainMenu::exportBookList(BookList *l) {
    QString fileName = QFileDialog::getSaveFileName(this, tr("导出图书表至文件"), "", tr("文本文档(*.txt)"));
    std::ofstream os(fileName.toStdString(), std::ios::out);
    if (!os.is_open()) {
        QMessageBox::warning(
                this,
                "喜报",
                "文件路径无效或无法导出文件。",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
                QMessageBox::StandardButton::Ok
        );
        os.close();
        return;
    }

    os << l->size << std::endl;
    auto p = bookList->head;
    for (int i = 0; i < l->size; ++i) {
        os << p->ISBN   << "|";
        os << p->book   << "|";
        os << p->author << "|";
        os << p->price  << "|";
        os << p->press  << std::endl;
        p = p->next;
    }
    QMessageBox::warning(
        this,
        "喜报",
        "导出成功",
        QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
        QMessageBox::StandardButton::Ok
    );
    os.close();
}

BookList *mainMenu::importBookList(std::string fileName) {
    std::ifstream is(fileName, std::ios::in);
    if (!is.is_open()) {
        QMessageBox::warning(
            this,
            "喜报",
            "文件路径无效或无法读文件。",
            QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
            QMessageBox::StandardButton::Ok
        );
        is.close();
        return bookList;
    }

    std::string listSize;
    try {
        std::getline(is, listSize);
    }
    catch (...) {
        QMessageBox::warning(
            this,
            "喜报",
            "导入的文件格式错误！",
            QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
            QMessageBox::StandardButton::Ok
        );
        is.close();
        return bookList;
    }

    auto newList = new BookList(new BookNode(), std::stoi(listSize));
    auto p = newList->head;
    for (int i = 0; i < newList->size; ++i) {
        if (i > 0) {
            p->next = new BookNode(0.0, "", "", "", "", nullptr, p);
            p = p->next;
        }
        std::string currLn;
        std::getline(is, currLn);
        size_t left = 0, right = currLn.find_first_of('|');
        p->ISBN = currLn.substr(left, right - left);
        left = right + 1, right = currLn.find_first_of('|', left);
        p->book = currLn.substr(left, right - left);
        left = right + 1, right = currLn.find_first_of('|', left);
        p->author = currLn.substr(left, right - left);
        left = right + 1, right = currLn.find_first_of('|', left);
        p->price = std::stof(currLn.substr(left, right - left));
        left = right + 1;
        p->press = currLn.substr(left, currLn.length() - left);
    }
    QMessageBox::warning(
        this,
        "喜报",
        "导入图书表成功！",
        QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
        QMessageBox::StandardButton::Ok
    );
    is.close();
    return newList;
}

void mainMenu::on_createBookListButton_clicked() {
    auto w_createBook = new createBookList(nullptr, bookList);
    w_createBook->show();
    this->close();
}

void mainMenu::on_browseBookButton_clicked() {
    if (bookList->size == 0) {
        QMessageBox::warning(
                this,
                "喜报",
                "图书表不存在，请新建或者导入一个。",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
                QMessageBox::StandardButton::Ok
        );
        return;
    }
    auto w_browsBook = new browseBook(nullptr, bookList);
    w_browsBook->show();
    this->close();
}

void mainMenu::on_editBookButton_clicked() {
    if (bookList->size == 0) {
        QMessageBox::warning(
                this,
                "喜报",
                "图书表不存在，请新建或者导入一个。",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
                QMessageBox::StandardButton::Ok
        );
        return;
    }
    auto w_editBook = new editBook(nullptr, bookList);
    w_editBook->show();
    this->close();
}

void mainMenu::on_searchBookButton_clicked() {
    if (bookList->size == 0) {
        QMessageBox::warning(
            this,
            "喜报",
            "图书表不存在，请新建或者导入一个。",
            QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
            QMessageBox::StandardButton::Ok
        );
        return;
    }
    auto w_searchBook = new searchBook(nullptr, bookList);
    w_searchBook->show();
    this->close();
}

void mainMenu::on_bookAnalysisButton_clicked() {
    auto w_bookAnalysis = new bookAnalysisWindow(nullptr, bookList);
    w_bookAnalysis->show();
    this->close();
}

void mainMenu::on_importBookListButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("从文件导入图书表"), "", tr("文本文档(*.txt)"));
    bookList = importBookList(fileName.toStdString());
}

void mainMenu::on_exportBookListButton_clicked() {
    if (bookList->size == 0) {
        QMessageBox::warning(
                this,
                "喜报",
                "图书表不存在，请新建或者导入一个。",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
                QMessageBox::StandardButton::Ok
        );
        return;
    }
    exportBookList(bookList);
}

void mainMenu::on_exitSystemButton_clicked() {
    this->close();
}

void mainMenu::on_importBookListAction_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("从文件导入图书表"), "", tr("文本文档(*.txt)"));
    bookList = importBookList(fileName.toStdString());
}

void mainMenu::on_exportBookListAction_triggered() {
    if (bookList->size == 0) {
        QMessageBox::warning(
                this,
                "喜报",
                "图书表不存在，请新建或者导入一个。",
                QMessageBox::StandardButtons(QMessageBox::StandardButton::Ok),
                QMessageBox::StandardButton::Ok
        );
        return;
    }
    exportBookList(bookList);
}

void mainMenu::on_aboutAction_triggered() {
    auto w_aboutWindow = new aboutWindow(this);
    // 设置子窗口开启后阻塞主窗口
    w_aboutWindow->setWindowFlags(Qt::Dialog);
    w_aboutWindow->setWindowModality(Qt::ApplicationModal);
    w_aboutWindow->show();
}

mainMenu::~mainMenu() {
    delete ui;
}
