#ifndef BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_WINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_WINDOW_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <QFileDialog>
#include <QMainWindow>
#include "browseBookWindow.hpp"
#include "editBookWindow.hpp"
#include "createBookListWindow.hpp"
#include "data_structures/bookList.hpp"
#include "forms/about_window.hpp"
#include "searchBookWindow.hpp"
#include "forms/book_analysis_window.hpp"
#include "goodNewsWindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class main_menu_window; }
QT_END_NAMESPACE

class main_menu_window : public QMainWindow {
Q_OBJECT

public:
    explicit main_menu_window(QWidget *parent = nullptr, BookList *list = nullptr);

    ~main_menu_window() override;

// 私有成员函数
private:
    void exportBookList(BookList *l);
    BookList *importBookList(const std::string& fileName);

// 槽函数
private slots:
    // 按钮
    void on_browseBookButton_clicked();
    void on_editBookButton_clicked();
    void on_exitSystemButton_clicked();
    void on_createBookListButton_clicked();
    void on_searchBookButton_clicked();
    void on_importBookListButton_clicked();
    void on_exportBookListButton_clicked();
    void on_bookAnalysisButton_clicked();
    // Action
    void on_aboutAction_triggered();
    void on_importBookListAction_triggered();
    void on_exportBookListAction_triggered();

// 私有成员变量
private:
    Ui::main_menu_window *ui;
    BookList *bookList;
};

#endif //BOOK_MANAGE_SYSTEM_QT_MAIN_MENU_WINDOW_HPP
