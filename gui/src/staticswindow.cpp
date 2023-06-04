#include "staticswindow.h"
#include "ui_staticswindow.h"

StaticsWindow::StaticsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaticsWindow) {
    ui->setupUi(this);
}

StaticsWindow::~StaticsWindow() {
    delete ui;
}

void StaticsWindow::showSpeed() {

}

void StaticsWindow::showGraph() {

}

void StaticsWindow::btnBack() {

}
