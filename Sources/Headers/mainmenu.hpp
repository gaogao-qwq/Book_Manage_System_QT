#ifndef BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP
#define BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP

#include <QMainWindow>
#include "browsebook.hpp"
#include "editbook.hpp"
#include "createbooklist.hpp"
#include "bookList.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class mainMenu; }
QT_END_NAMESPACE

class mainMenu : public QMainWindow {
Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr, BookList *list = nullptr);

    ~mainMenu() override;

// 槽函数
private slots:
    void on_browseBookButton_clicked();
    void on_editBookButton_clicked();
    void on_exitSystemButton_clicked();
    void on_createBookListButton_clicked();

// 私有成员变量
private:
    Ui::mainMenu *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP
