#include "forms/about_window.hpp"
#include "ui_aboutWindow.h"


about_window::about_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::about_window) {
    // 阻塞其它窗口
    this->setWindowFlags(Qt::Dialog);
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    ui->label->setOpenExternalLinks(true);
}

void about_window::on_backButton_clicked() {
    this->close();
}

about_window::~about_window() {
    delete ui;
}
