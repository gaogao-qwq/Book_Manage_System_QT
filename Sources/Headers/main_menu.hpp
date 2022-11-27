#ifndef BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_HPP
#define BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_HPP

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "browsebook.hpp"
#include "editbook.hpp"
#include "createbooklist.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class Main_Menu; }
QT_END_NAMESPACE

class Main_Menu : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit Main_Menu(QWidget *parent = nullptr, BookList *list = nullptr);

    // 析构函数
    ~Main_Menu() override;

    // 槽函数
private slots:
    void on_browsBookButton_clicked();
    void on_editBookButton_clicked();
    void on_exitSystemButton_clicked();
    void on_createBookListButton_clicked();

    // 私有成员变量&对象
private:
    Ui::Main_Menu *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_HPP
