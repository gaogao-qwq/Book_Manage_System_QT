#ifndef BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP
#define BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP

#include <QWidget>
#include "main_menu.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class editBook; }
QT_END_NAMESPACE

class editBook : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit editBook(QWidget *parent = nullptr, BookList *list = nullptr);
    // 析构函数
    ~editBook() override;

// 私有成员函数
private:
    // 深拷贝链表函数
    BookList *deepCopy(BookList *l);
    // 更新 tableWidget 组件函数
    void updateTableWidget(BookList *l);
    // Debug 用
    static void debugPrintList(BookList *l);

// 槽函数
private slots:
    void on_sortByPriceButton_clicked();
    void on_backButton_clicked();
    void on_backSaveButton_clicked();

private:
    Ui::editBook *ui;
    BookList *bookList;
    BookList *newList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP
