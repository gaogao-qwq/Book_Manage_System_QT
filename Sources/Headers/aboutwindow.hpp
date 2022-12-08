#ifndef BOOK_MANAGE_SYSTEM_QT_ABOUTWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_ABOUTWINDOW_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class aboutWindow; }
QT_END_NAMESPACE

class aboutWindow : public QWidget {
Q_OBJECT

public:
    explicit aboutWindow(QWidget *parent = nullptr);

    ~aboutWindow() override;

private slots:
    void on_backButton_clicked();

private:
    Ui::aboutWindow *ui;
};


#endif //BOOK_MANAGE_SYSTEM_QT_ABOUTWINDOW_HPP
