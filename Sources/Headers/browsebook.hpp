#ifndef BOOK_MANAGE_SYSTEM_QT_BROWSEBOOK_HPP
#define BOOK_MANAGE_SYSTEM_QT_BROWSEBOOK_HPP

#include <QWidget>
#include "mainmenu.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class browseBook; }
QT_END_NAMESPACE

class browseBook : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit browseBook(QWidget *parent = nullptr, BookList *list = nullptr);
    // 析构函数
    ~browseBook() override;

private:
    // 更新 tableWidget 组件函数
    void updateTableWidget(BookList *l);

private slots:
    void on_backButton_clicked();

private:
    Ui::browseBook *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_BROWSEBOOK_HPP
