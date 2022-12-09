#ifndef BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP
#define BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <QFileDialog>
#include <QMainWindow>
#include "browsebook.hpp"
#include "editbook.hpp"
#include "createbooklist.hpp"
#include "bookList.hpp"
#include "aboutwindow.hpp"
#include "searchbook.hpp"
#include "bookanalysiswindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class mainMenu; }
QT_END_NAMESPACE

class mainMenu : public QMainWindow {
Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr, BookList *list = nullptr);

    ~mainMenu() override;

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
    Ui::mainMenu *ui;
    BookList *bookList;
};

#endif //BOOK_MANAGE_SYSTEM_QT_MAINMENU_HPP
