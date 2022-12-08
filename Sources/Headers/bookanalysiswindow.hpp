#ifndef BOOK_MANAGE_SYSTEM_QT_BOOKANALYSISWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_BOOKANALYSISWINDOW_HPP

#include <QWidget>
#include <unordered_set>
#include <vector>
#include "mainmenu.hpp"
#include "bookList.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class bookAnalysisWindow; }
QT_END_NAMESPACE

class bookAnalysisWindow : public QWidget {
Q_OBJECT

public:
    explicit bookAnalysisWindow(QWidget *parent = nullptr, BookList *list = nullptr);

    ~bookAnalysisWindow() override;

// 槽函数
private slots:
    // 按钮
    void on_exitButton_clicked();
    // comboBox
    void on_pressComboBox_currentTextChanged(const QString &text);
    void on_authorComboBox_currentTextChanged(const QString &text);

private:
    Ui::bookAnalysisWindow *ui;
    BookList *bookList;
    std::unordered_map<std::string, std::vector<BookNode *>> press;
    std::unordered_map<std::string, std::vector<BookNode *>> author;
};


#endif //BOOK_MANAGE_SYSTEM_QT_BOOKANALYSISWINDOW_HPP
