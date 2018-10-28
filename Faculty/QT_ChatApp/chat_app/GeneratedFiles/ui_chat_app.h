/********************************************************************************
** Form generated from reading UI file 'chat_app.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_APP_H
#define UI_CHAT_APP_H

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

class Ui_chat_appClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chat_appClass)
    {
        if (chat_appClass->objectName().isEmpty())
            chat_appClass->setObjectName(QStringLiteral("chat_appClass"));
        chat_appClass->resize(600, 400);
        menuBar = new QMenuBar(chat_appClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        chat_appClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chat_appClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chat_appClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(chat_appClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chat_appClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(chat_appClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chat_appClass->setStatusBar(statusBar);

        retranslateUi(chat_appClass);

        QMetaObject::connectSlotsByName(chat_appClass);
    } // setupUi

    void retranslateUi(QMainWindow *chat_appClass)
    {
        chat_appClass->setWindowTitle(QApplication::translate("chat_appClass", "chat_app", 0));
    } // retranslateUi

};

namespace Ui {
    class chat_appClass: public Ui_chat_appClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_APP_H
