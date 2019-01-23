/********************************************************************************
** Form generated from reading UI file 'DDSInQT.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDSINQT_H
#define UI_DDSINQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDSInQTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DDSInQTClass)
    {
        if (DDSInQTClass->objectName().isEmpty())
            DDSInQTClass->setObjectName(QStringLiteral("DDSInQTClass"));
        DDSInQTClass->resize(600, 400);
        menuBar = new QMenuBar(DDSInQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DDSInQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DDSInQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DDSInQTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DDSInQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DDSInQTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DDSInQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DDSInQTClass->setStatusBar(statusBar);

        retranslateUi(DDSInQTClass);

        QMetaObject::connectSlotsByName(DDSInQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *DDSInQTClass)
    {
        DDSInQTClass->setWindowTitle(QApplication::translate("DDSInQTClass", "DDSInQT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DDSInQTClass: public Ui_DDSInQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDSINQT_H
