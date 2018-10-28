/********************************************************************************
** Form generated from reading UI file 'project1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT1_H
#define UI_PROJECT1_H

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

class Ui_project1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *project1Class)
    {
        if (project1Class->objectName().isEmpty())
            project1Class->setObjectName(QStringLiteral("project1Class"));
        project1Class->resize(600, 400);
        menuBar = new QMenuBar(project1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        project1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(project1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        project1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(project1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        project1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(project1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        project1Class->setStatusBar(statusBar);

        retranslateUi(project1Class);

        QMetaObject::connectSlotsByName(project1Class);
    } // setupUi

    void retranslateUi(QMainWindow *project1Class)
    {
        project1Class->setWindowTitle(QApplication::translate("project1Class", "project1", 0));
    } // retranslateUi

};

namespace Ui {
    class project1Class: public Ui_project1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT1_H
