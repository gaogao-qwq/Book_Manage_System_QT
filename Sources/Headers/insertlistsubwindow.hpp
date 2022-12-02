#ifndef BOOK_MANAGE_SYSTEM_QT_INSERTLISTSUBWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_INSERTLISTSUBWINDOW_HPP

#include <QWidget>
#include "bookList.hpp"
#include "editbook.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class insertListSubWindow; }
QT_END_NAMESPACE

class insertListSubWindow : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit insertListSubWindow(QWidget *parent = nullptr, BookList *list = nullptr, int row = 0);
    // 析构函数
    ~insertListSubWindow() override;

// 私有成员函数
private:
    void insertAtFront(BookList *l);
    void insertAtBack(BookList *l);

private slots:
    void on_cancelButton_clicked();
    void on_insertAtFrontButton_clicked();
    void on_insertAtBackButton_clicked();

// 私有成员变量
private:
    Ui::insertListSubWindow *ui;
    BookList *bookList;
    BookNode *p;
};


#endif //BOOK_MANAGE_SYSTEM_QT_INSERTLISTSUBWINDOW_HPP
