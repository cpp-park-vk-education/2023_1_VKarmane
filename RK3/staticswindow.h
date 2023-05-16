#ifndef STATICSWINDOW_H
#define STATICSWINDOW_H

#include <QDialog>

namespace Ui {
class StaticsWindow;
}

class StaticsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StaticsWindow(QWidget *parent = nullptr);
    ~StaticsWindow();

private:
    Ui::StaticsWindow *ui;
};

#endif // STATICSWINDOW_H
