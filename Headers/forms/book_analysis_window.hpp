#ifndef BOOK_MANAGE_SYSTEM_QT_BOOK_ANALYSIS_WINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_BOOK_ANALYSIS_WINDOW_HPP

#include <QWidget>
#include <unordered_set>
#include <vector>
#include "main_menu_window.hpp"
#include "data_structures/bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class book_analysis_window; }
QT_END_NAMESPACE

class book_analysis_window : public QWidget {
Q_OBJECT

public:
    explicit book_analysis_window(QWidget *parent = nullptr, BookList *list = nullptr);

    ~book_analysis_window() override;

// 槽函数
private slots:
    // 按钮
    void on_exitButton_clicked();
    // comboBox
    void on_pressComboBox_currentTextChanged(const QString &text);
    void on_authorComboBox_currentTextChanged(const QString &text);

private:
    Ui::book_analysis_window *ui;
    BookList *bookList;
    std::unordered_map<std::string, std::vector<BookNode *>> press;
    std::unordered_map<std::string, std::vector<BookNode *>> author;
};


#endif //BOOK_MANAGE_SYSTEM_QT_BOOK_ANALYSIS_WINDOW_HPP
