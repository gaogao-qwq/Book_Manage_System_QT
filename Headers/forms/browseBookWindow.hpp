#ifndef BOOK_MANAGE_SYSTEM_QT_BROWSEBOOKWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_BROWSEBOOKWINDOW_HPP

#include <QWidget>
#include "main_menu_window.hpp"
#include "data_structures//bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class browseBookWindow; }
QT_END_NAMESPACE

class browseBookWindow : public QWidget {
Q_OBJECT

public:
    // 构造函数
    explicit browseBookWindow(QWidget *parent = nullptr, BookList *list = nullptr);
    // 析构函数
    ~browseBookWindow() override;

private:
    // 更新 tableWidget 组件函数
    void updateTableWidget(BookList *l);

private slots:
    void on_backButton_clicked();

private:
    Ui::browseBookWindow *ui;
    BookList *bookList;
};


#endif //BOOK_MANAGE_SYSTEM_QT_BROWSEBOOKWINDOW_HPP
