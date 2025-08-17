#include "settings_page.h"
#include "ui_settings_page.h"
#include <QComboBox>

SettingsPage::SettingsPage(QWidget *parent) : QWidget(parent), ui(new Ui::SettingsPage) {
    ui->setupUi(this);
    wire();
}
SettingsPage::~SettingsPage(){ delete ui; }

void SettingsPage::wire() {
    connect(ui->cmbTheme, &QComboBox::currentTextChanged, this, [this](const QString& t){
        emit themeChanged(t.toLower());
    });
}
