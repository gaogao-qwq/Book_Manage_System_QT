#include "goodnews.hpp"
#include "Forms/ui_goodNews.h"


goodNews::goodNews(QWidget *parent, const QString& text) :
        QWidget(parent), ui(new Ui::goodNews) {
    // 阻塞其它窗口
    this->setWindowFlags(Qt::Dialog);
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    ui->text->setText(text);
}

void goodNews::on_backButton_clicked() {
    this->close();
}

void goodNews::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/lib/lib/xibao.png"), QRect());
}

goodNews::~goodNews() {
    delete ui;
}
