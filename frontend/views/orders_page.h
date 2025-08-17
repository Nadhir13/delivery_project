// orders_page.h
#pragma once
#include <QWidget>
namespace Ui { class OrdersPage; }
class OrdersPage : public QWidget {
    Q_OBJECT
public:
    explicit OrdersPage(QWidget *parent=nullptr);
    ~OrdersPage();
private:
    Ui::OrdersPage *ui;
    void setupTable();
};
