#include "forms/goodNewsWindow.hpp"
#include "ui_goodNewsWindow.h"


goodNewsWindow::goodNewsWindow(QWidget *parent, const QString& text) :
        QWidget(parent), ui(new Ui::goodNewsWindow) {
    // 阻塞其它窗口
    this->setWindowFlags(Qt::Dialog);
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    ui->text->setText(text);
}

void goodNewsWindow::on_backButton_clicked() {
    this->close();
}

void goodNewsWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/lib/lib/xibao.png"), QRect());
}

goodNewsWindow::~goodNewsWindow() {
    delete ui;
}
