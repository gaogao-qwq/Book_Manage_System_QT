#ifndef BOOK_MANAGE_SYSTEM_QT_DEDUPLICATELISTSUBWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_DEDUPLICATELISTSUBWINDOW_HPP

#include <QWidget>
#include <sstream>
#include "editBookWindow.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class deduplicateListSubWindow; }
QT_END_NAMESPACE

class deduplicateListSubWindow : public QWidget {
Q_OBJECT

public:
    explicit deduplicateListSubWindow(QWidget *parent = nullptr, BookList *list = nullptr, const std::unordered_set<std::string>& duplicatedISBN = {});

    ~deduplicateListSubWindow() override;

private slots:
    void on_deleteButton_clicked();
    void on_backButton_clicked();
    void on_backSaveButton_clicked();

private:
    BookList *deepCopy(BookList *l);
    void deleteNode(int row);
    void updateTableWidget();

private:
    Ui::deduplicateListSubWindow *ui;
    BookList *bookList;
    BookList *newList;
    std::vector<BookNode *> duplicatedNode;
};


#endif //BOOK_MANAGE_SYSTEM_QT_DEDUPLICATELISTSUBWINDOW_HPP
