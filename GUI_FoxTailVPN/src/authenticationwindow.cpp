#include "authenticationwindow.h"
#include "ui_authenticationwindow.h"

AuthenticationWindow::AuthenticationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthenticationWindow) {
    ui->setupUi(this);
}

AuthenticationWindow::~AuthenticationWindow() {
    delete ui;
}

void AuthenticationWindow::btnAuthentication() {

}

void AuthenticationWindow::CheckForm() {

}

void AuthenticationWindow::btnBack() {

}
