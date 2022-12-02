#ifndef BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLIST_HPP
#define BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLIST_HPP

#include <QWidget>
#include <QMessageBox>
#include "mainmenu.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class createBookList; }
QT_END_NAMESPACE

class createBookList : public QWidget {
Q_OBJECT

public:
    explicit createBookList(QWidget *parent = nullptr, BookList *list = nullptr);

    ~createBookList() override;

private slots:
    void on_backButton_clicked();
    void on_backSaveButton_clicked();
    void on_inputButton_clicked();

private:
    Ui::createBookList *ui;
    BookList *bookList;
    BookList *newList = new BookList(new BookNode(), 0);
    BookNode *p = newList->head;
};


#endif //BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLIST_HPP
