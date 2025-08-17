#pragma once
#include <QWidget>

namespace Ui { class DashboardPage; }

class DashboardPage : public QWidget {
    Q_OBJECT
public:
    explicit DashboardPage(QWidget *parent = nullptr);
    ~DashboardPage();
private:
    Ui::DashboardPage *ui;
    void populateDemo();
};
