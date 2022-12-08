#ifndef BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP
#define BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP

#include <QWidget>
#include <unordered_set>
#include "mainmenu.hpp"
#include "bookList.hpp"
#include "convert.hpp"
#include "editlistsubwindow.hpp"
#include "insertlistsubwindow.hpp"
#include "deduplicatelistsubwindow.hpp"


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
    // Debug 用打印函数
    static void debugPrintList(BookList *l);
    // 排序
    BookNode *sortByPrice(BookNode *h);
    BookNode *sortByISBN(BookNode *h);
    BookNode *sortByBook(BookNode *h);
    BookNode *sortByAuthor(BookNode *h);
    BookNode *sortByPress(BookNode *h);
    // 删除
    void deleteNode(BookList *l, int row);

// 槽函数
private slots:
    void on_sortByPriceButton_clicked();
    void on_sortByISBNButton_clicked();
    void on_sortByBookButton_clicked();
    void on_sortByAuthorButton_clicked();
    void on_sortByPressButton_clicked();

    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_insertButton_clicked();

    void on_deduplicateButton_clicked();

    void on_backButton_clicked();
    void on_backSaveButton_clicked();

// 私有成员变量
private:
    Ui::editBook *ui;
    BookList *bookList;
    BookList *newList;
    std::map<std::string, std::string> m_pinyin;
};


#endif //BOOK_MANAGE_SYSTEM_QT_EDITBOOK_HPP
