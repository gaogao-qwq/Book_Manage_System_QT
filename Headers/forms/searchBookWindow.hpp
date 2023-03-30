#ifndef BOOK_MANAGE_SYSTEM_QT_SEARCHBOOKWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_SEARCHBOOKWINDOW_HPP

#include <QWidget>
#include "main_menu_window.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class searchBookWindow; }
QT_END_NAMESPACE

class searchBookWindow : public QWidget {
Q_OBJECT

public:
    explicit searchBookWindow(QWidget *parent = nullptr, BookList *list = nullptr);

    ~searchBookWindow() override;

private:
    void updateTableWidget(std::vector<BookNode *> searchResult);

private slots:
    void on_searchButton_clicked();
    void on_backButton_clicked();

private:
    Ui::searchBookWindow *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_SEARCHBOOKWINDOW_HPP
