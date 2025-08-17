#pragma once
#include <QMainWindow>

class DashboardPage;
class OrdersPage;
class ClientsPage;
class SettingsPage;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DashboardPage *dash{};
    OrdersPage *orders{};
    ClientsPage *clients{};
    SettingsPage *settings{};
    bool darkMode{true};

    void loadPages();       // loads .ui pages into stacked
    void wireNav();         // buttons → stacked
    void applyTheme(const QString& which); // dark/light
};
