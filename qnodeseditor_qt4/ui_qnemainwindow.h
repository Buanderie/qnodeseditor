/********************************************************************************
** Form generated from reading UI file 'qnemainwindow.ui'
**
** Created: Tue 17. Apr 16:01:26 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEMAINWINDOW_H
#define UI_QNEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QNEMainWindow
{
public:
    QAction *action_Save;
    QAction *action_Load;
    QAction *action_Quit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QNEMainWindow)
    {
        if (QNEMainWindow->objectName().isEmpty())
            QNEMainWindow->setObjectName(QString::fromUtf8("QNEMainWindow"));
        QNEMainWindow->resize(540, 389);
        action_Save = new QAction(QNEMainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Load = new QAction(QNEMainWindow);
        action_Load->setObjectName(QString::fromUtf8("action_Load"));
        action_Quit = new QAction(QNEMainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        centralWidget = new QWidget(QNEMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        QNEMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QNEMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        QNEMainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(QNEMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QNEMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Load);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(QNEMainWindow);

        QMetaObject::connectSlotsByName(QNEMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QNEMainWindow)
    {
        QNEMainWindow->setWindowTitle(QApplication::translate("QNEMainWindow", "QNodesEditor Demo (c) 2012 STANISLAW ADASZEWSKI, http://algoholic.eu", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("QNEMainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        action_Load->setText(QApplication::translate("QNEMainWindow", "&Load", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("QNEMainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("QNEMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("QNEMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QNEMainWindow: public Ui_QNEMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEMAINWINDOW_H
