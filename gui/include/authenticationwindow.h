#ifndef AUTHENTICATIONWINDOW_H
#define AUTHENTICATIONWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuthenticationWindow;
}
QT_END_NAMESPACE

class IAuthenticationWindow {
    virtual void btnAuthentication() = 0;
    virtual void CheckForm() = 0;
    virtual void btnBack() = 0;
};

class AuthenticationWindow : public QDialog, public IAuthenticationWindow {
    Q_OBJECT

public:
    explicit AuthenticationWindow(QWidget *parent = nullptr);
    ~AuthenticationWindow();

private:
    Ui::AuthenticationWindow *ui;
    void btnAuthentication() override;
    void CheckForm() override;
    void btnBack() override;
};

#endif // AUTHENTICATIONWINDOW_H
