#ifndef CONFIGURATIONWINDOW_H
#define CONFIGURATIONWINDOW_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class ConfigurationWindow;
}
QT_END_NAMESPACE

class IConfigurationWindow {
    virtual void btnSave() = 0;
    virtual void btnDelete() = 0;
    virtual void btnBack() = 0;
};

class ConfigurationWindow : public QDialog, public IConfigurationWindow {
    Q_OBJECT

public:
    explicit ConfigurationWindow(QWidget *parent = nullptr);
    ~ConfigurationWindow();

private:
    Ui::ConfigurationWindow *ui;
    bool configAdded;

signals:
    void backMainWindow();
    void valueChangedConfigAdded(bool value);

private slots:
    void btnSave() override;
    void btnDelete() override;
    void btnBack() override;
};

#endif // CONFIGURATIONWINDOW_H
