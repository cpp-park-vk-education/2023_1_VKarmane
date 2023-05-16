#ifndef AUTHENTICATIONWINDOW_H
#define AUTHENTICATIONWINDOW_H

#include <QDialog>

namespace Ui {
class AuthenticationWindow;
}

class AuthenticationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthenticationWindow(QWidget *parent = nullptr);
    ~AuthenticationWindow();

private:
    Ui::AuthenticationWindow *ui;
};

#endif // AUTHENTICATIONWINDOW_H
