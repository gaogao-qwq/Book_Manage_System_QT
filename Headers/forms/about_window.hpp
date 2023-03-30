#ifndef BOOK_MANAGE_SYSTEM_QT_ABOUT_WINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_ABOUT_WINDOW_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class about_window; }
QT_END_NAMESPACE

class about_window : public QWidget {
Q_OBJECT

public:
    explicit about_window(QWidget *parent = nullptr);

    ~about_window() override;

private slots:
    void on_backButton_clicked();

private:
    Ui::about_window *ui;
};


#endif //BOOK_MANAGE_SYSTEM_QT_ABOUT_WINDOW_HPP
