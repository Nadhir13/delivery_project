#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dashboard_page.h"
#include "orders_page.h"
#include "clients_page.h"
#include "settings_page.h"

#include <QFile>
#include <QToolButton>
#include <QButtonGroup>

static void loadQss(QWidget* w, const QString& path) {
    QFile f(path);
    if (f.open(QFile::ReadOnly)) {
        w->setStyleSheet(QString::fromUtf8(f.readAll()));
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    loadPages();
    wireNav();
    applyTheme("dark"); // start in dark
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::loadPages() {
    dash = new DashboardPage(this);
    orders = new OrdersPage(this);
    clients = new ClientsPage(this);
    settings = new SettingsPage(this);

    ui->stacked->removeWidget(ui->pageDashboard);
    ui->stacked->removeWidget(ui->pageOrders);
    ui->stacked->removeWidget(ui->pageClients);
    ui->stacked->removeWidget(ui->pageSettings);

    ui->stacked->addWidget(dash);      // index 0
    ui->stacked->addWidget(orders);    // index 1
    ui->stacked->addWidget(clients);   // index 2
    ui->stacked->addWidget(settings);  // index 3

    // theme from settings
    connect(settings, &SettingsPage::themeChanged, this, &MainWindow::applyTheme);
}

void MainWindow::wireNav() {
    // make nav tabs mutually exclusive
    auto buttons = new QButtonGroup(this);
    buttons->setExclusive(true);
    buttons->addButton(ui->btnDashboard);
    buttons->addButton(ui->btnOrders);
    buttons->addButton(ui->btnClients);
    buttons->addButton(ui->btnReports);

    connect(ui->btnDashboard, &QToolButton::clicked, this, [this]{ ui->stacked->setCurrentIndex(0); });
    connect(ui->btnOrders,    &QToolButton::clicked, this, [this]{ ui->stacked->setCurrentIndex(1); });
    connect(ui->btnClients,   &QToolButton::clicked, this, [this]{ ui->stacked->setCurrentIndex(2); });
    connect(ui->btnReports,   &QToolButton::clicked, this, [this]{ ui->stacked->setCurrentIndex(3); });

    connect(ui->btnTheme, &QToolButton::clicked, this, [this]{
        applyTheme(darkMode ? "light" : "dark");
    });
}

void MainWindow::applyTheme(const QString& which) {
    darkMode = (which.toLower()=="dark");
    const QString base = darkMode ? ":/../frontend/styles/app_dark.qss"
                                  : ":/../frontend/styles/app_light.qss";
    loadQss(this, base);
}
