#ifndef BOOK_MANAGE_SYSTEM_QT_GOODNEWS_HPP
#define BOOK_MANAGE_SYSTEM_QT_GOODNEWS_HPP

#include <QWidget>
#include <QLabel>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class goodNews; }
QT_END_NAMESPACE

class goodNews : public QWidget {
Q_OBJECT

public:
    explicit goodNews(QWidget *parent = nullptr, const QString& text = "");

    ~goodNews() override;

private:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_backButton_clicked();

private:
    Ui::goodNews *ui;
};


#endif //BOOK_MANAGE_SYSTEM_QT_GOODNEWS_HPP
