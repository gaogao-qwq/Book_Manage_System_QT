#ifndef BOOK_MANAGE_SYSTEM_QT_EDITLISTSUBWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_EDITLISTSUBWINDOW_HPP

#include <QWidget>
#include "bookList.hpp"
#include "editbook.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class editListSubWindow; }
QT_END_NAMESPACE

class editListSubWindow : public QWidget {
Q_OBJECT

// 构造函数
public:
    explicit editListSubWindow(QWidget *parent = nullptr, BookList *list = nullptr, int row = 0);

    ~editListSubWindow() override;

// 私有成员变量
private:
    Ui::editListSubWindow *ui;
    BookList *bookList;
    BookNode *p;

// 槽函数
private slots:
    void on_cancelButton_clicked();
    void on_editSaveButton_clicked();
};


#endif //BOOK_MANAGE_SYSTEM_QT_EDITLISTSUBWINDOW_HPP
