#include "aboutwindow.hpp"
#include "Forms/ui_aboutWindow.h"


aboutWindow::aboutWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::aboutWindow) {
    // 阻塞其它窗口
    this->setWindowFlags(Qt::Dialog);
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    ui->label->setOpenExternalLinks(true);
}

void aboutWindow::on_backButton_clicked() {
    this->close();
}

aboutWindow::~aboutWindow() {
    delete ui;
}
