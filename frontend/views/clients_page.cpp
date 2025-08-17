// clients_page.cpp
#include "clients_page.h"
#include "ui_clients_page.h"
#include <QTableWidget>

ClientsPage::ClientsPage(QWidget *parent) : QWidget(parent), ui(new Ui::ClientsPage) {
    ui->setupUi(this);
    setupTable();
}
ClientsPage::~ClientsPage(){ delete ui; }

void ClientsPage::setupTable() {
    auto t = ui->tableClients;
    t->setColumnCount(5);
    t->setHorizontalHeaderLabels({"Client","Email","Phone","City","Created"});
    t->setRowCount(5);
    for (int r=0;r<5;++r) {
        t->setItem(r,0,new QTableWidgetItem("Acme Ltd"));
        t->setItem(r,1,new QTableWidgetItem("contact@acme.com"));
        t->setItem(r,2,new QTableWidgetItem("+216 20 000 000"));
        t->setItem(r,3,new QTableWidgetItem("Tunis"));
        t->setItem(r,4,new QTableWidgetItem("2025-01-10"));
    }
    t->resizeColumnsToContents();
}
