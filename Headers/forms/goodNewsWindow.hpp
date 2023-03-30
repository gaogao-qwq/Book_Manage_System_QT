#ifndef BOOK_MANAGE_SYSTEM_QT_GOODNEWSWINDOW_HPP
#define BOOK_MANAGE_SYSTEM_QT_GOODNEWSWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class goodNewsWindow; }
QT_END_NAMESPACE

class goodNewsWindow : public QWidget {
Q_OBJECT

public:
    explicit goodNewsWindow(QWidget *parent = nullptr, const QString& text = "");

    ~goodNewsWindow() override;

private:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_backButton_clicked();

private:
    Ui::goodNewsWindow *ui;
};


#endif //BOOK_MANAGE_SYSTEM_QT_GOODNEWSWINDOW_HPP
