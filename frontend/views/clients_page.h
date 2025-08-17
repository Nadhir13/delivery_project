#pragma once
#include <QWidget>
namespace Ui { class ClientsPage; }
class ClientsPage : public QWidget {
    Q_OBJECT
public:
    explicit ClientsPage(QWidget *parent=nullptr);
    ~ClientsPage();
private:
    Ui::ClientsPage *ui;
    void setupTable();
};
