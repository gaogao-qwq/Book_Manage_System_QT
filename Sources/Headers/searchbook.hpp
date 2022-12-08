#ifndef BOOK_MANAGE_SYSTEM_QT_SEARCHBOOK_HPP
#define BOOK_MANAGE_SYSTEM_QT_SEARCHBOOK_HPP

#include <QWidget>
#include "mainmenu.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class searchBook; }
QT_END_NAMESPACE

class searchBook : public QWidget {
Q_OBJECT

public:
    explicit searchBook(QWidget *parent = nullptr, BookList *list = nullptr);

    ~searchBook() override;

private:
    void updateTableWidget(std::vector<BookNode *> searchResult);

private slots:
    void on_searchButton_clicked();
    void on_backButton_clicked();

private:
    Ui::searchBook *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_SEARCHBOOK_HPP
