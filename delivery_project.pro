QT       += widgets
# (optional if you later add QtCharts)
# QT       += charts

CONFIG   += c++17

# UI forms
FORMS += \
    frontend/views/clients_page.ui \
    frontend/views/dashboard_page.ui \
    frontend/views/mainwindow.ui \
    frontend/views/orders_page.ui \
    frontend/views/settings_page.ui

# headers/sources
HEADERS += \
    frontend/views/clients_page.h \
    frontend/views/dashboard_page.h \
    frontend/views/mainwindow.h \
    frontend/views/orders_page.h \
    frontend/views/settings_page.h

SOURCES += \
    frontend/views/clients_page.cpp \
    frontend/views/dashboard_page.cpp \
    frontend/views/orders_page.cpp \
    frontend/views/settings_page.cpp \
    main.cpp \
    frontend/views/mainwindow.cpp

RESOURCES += resources/resources.qrc
