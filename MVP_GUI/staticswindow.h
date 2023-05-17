#ifndef STATICSWINDOW_H
#define STATICSWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class StaticsWindow;
}
QT_BEGIN_NAMESPACE

class IStaticsWindow {
    virtual void showSpeed() = 0;
    virtual void showGraph() = 0;
    virtual void btnBack() = 0;
};

class StaticsWindow : public QDialog, public IStaticsWindow {
    Q_OBJECT

public:
    explicit StaticsWindow(QWidget *parent = nullptr);
    ~StaticsWindow();

private:
    Ui::StaticsWindow *ui;

private slots:
    void showSpeed() override;
    void showGraph() override;
    void btnBack() override;

};

#endif // STATICSWINDOW_H
