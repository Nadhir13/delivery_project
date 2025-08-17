#pragma once
#include <QWidget>
namespace Ui { class SettingsPage; }
class SettingsPage : public QWidget {
    Q_OBJECT
public:
    explicit SettingsPage(QWidget *parent=nullptr);
    ~SettingsPage();
signals:
    void themeChanged(const QString& theme); // "dark" or "light"
private:
    Ui::SettingsPage *ui;
    void wire();
};
