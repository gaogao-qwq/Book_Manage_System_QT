#ifndef BOOK_MANAGE_SYSTEM_QT_EDITBOOKWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_EDITBOOKWINDOW_HPP

#include <QWidget>
#include <unordered_set>
#include "main_menu_window.hpp"
#include "data_structures/bookList.hpp"
#include "utils/pinyin_convert.hpp"
#include "editListSubWindow.hpp"
#include "insertListSubWindow.hpp"
#include "deduplicateListSubWindow.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class editBookWindow; }
QT_END_NAMESPACE

class editBookWindow : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit editBookWindow(QWidget *parent = nullptr, BookList *list = nullptr);
    // 析构函数
    ~editBookWindow() override;

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
    Ui::editBookWindow *ui;
    BookList *bookList;
    BookList *newList;
    std::unordered_map<std::string, std::string> m_pinyin;
};


#endif //BOOK_MANAGE_SYSTEM_QT_EDITBOOKWINDOW_HPP
