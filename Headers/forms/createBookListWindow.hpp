#ifndef BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLISTWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLISTWINDOW_HPP

#include <QWidget>
#include <QMessageBox>
#include "main_menu_window.hpp"
#include "data_structures/bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class createBookListWindow; }
QT_END_NAMESPACE

class createBookListWindow : public QWidget {
Q_OBJECT

public:
    explicit createBookListWindow(QWidget *parent = nullptr, BookList *list = nullptr);

    ~createBookListWindow() override;

private slots:
    void on_backButton_clicked();
    void on_backSaveButton_clicked();
    void on_inputButton_clicked();

private:
    Ui::createBookListWindow *ui{};
    BookList *bookList;
    BookList *newList = new BookList(new BookNode(), 0);
    BookNode *p = newList->head;
};


#endif //BOOK_MANAGE_SYSTEM_QT_CREATEBOOKLISTWINDOW_HPP
