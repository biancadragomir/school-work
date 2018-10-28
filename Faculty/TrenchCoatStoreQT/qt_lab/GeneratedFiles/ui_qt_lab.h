/********************************************************************************
** Form generated from reading UI file 'qt_lab.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_LAB_H
#define UI_QT_LAB_H

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

class Ui_qt_labClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_labClass)
    {
        if (qt_labClass->objectName().isEmpty())
            qt_labClass->setObjectName(QStringLiteral("qt_labClass"));
        qt_labClass->resize(600, 400);
        menuBar = new QMenuBar(qt_labClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qt_labClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_labClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_labClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qt_labClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qt_labClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qt_labClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_labClass->setStatusBar(statusBar);

        retranslateUi(qt_labClass);

        QMetaObject::connectSlotsByName(qt_labClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_labClass)
    {
        qt_labClass->setWindowTitle(QApplication::translate("qt_labClass", "qt_lab", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_labClass: public Ui_qt_labClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_LAB_H
