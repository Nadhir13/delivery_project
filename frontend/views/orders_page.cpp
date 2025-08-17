#include "orders_page.h"
#include "ui_orders_page.h"
#include <QTableWidget>

OrdersPage::OrdersPage(QWidget *parent) : QWidget(parent), ui(new Ui::OrdersPage) {
    ui->setupUi(this);
    setupTable();
}
OrdersPage::~OrdersPage(){ delete ui; }

void OrdersPage::setupTable() {
    auto t = ui->tableOrders;
    t->setColumnCount(6);
    t->setHorizontalHeaderLabels({"Order #","Client","Pickup","Delivery","Status","Amount"});
    t->setRowCount(5);
    for (int r=0;r<5;++r) {
        t->setItem(r,0,new QTableWidgetItem(QString("ORD-%1").arg(1000+r)));
        t->setItem(r,1,new QTableWidgetItem("Acme Ltd"));
        t->setItem(r,2,new QTableWidgetItem("Tunis"));
        t->setItem(r,3,new QTableWidgetItem("Sousse"));
        t->setItem(r,4,new QTableWidgetItem(r%2? "In Transit":"Delivered"));
        t->setItem(r,5,new QTableWidgetItem("$" + QString::number(50+r*10)));
    }
    t->resizeColumnsToContents();
}
