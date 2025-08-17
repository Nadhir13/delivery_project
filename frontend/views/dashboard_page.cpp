#include "dashboard_page.h"
#include "ui_dashboard_page.h"
#include <QTableWidget>
#include <QDate>

DashboardPage::DashboardPage(QWidget *parent) : QWidget(parent), ui(new Ui::DashboardPage) {
    ui->setupUi(this);
    populateDemo();
}
DashboardPage::~DashboardPage() { delete ui; }

void DashboardPage::populateDemo() {
    auto t = ui->tableActivity;
    t->setColumnCount(2);
    t->setHorizontalHeaderLabels({ "Day", "Count" });
    t->setRowCount(7);
    QStringList days = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    for (int i=0;i<7;++i) {
        t->setItem(i,0,new QTableWidgetItem(days[i]));
        t->setItem(i,1,new QTableWidgetItem(QString::number(120 + (i*40)%300)));
    }
    t->resizeColumnsToContents();
}
