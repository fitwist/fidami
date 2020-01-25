/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *mainTabWidget;
    QWidget *lineChartTab;
    QVBoxLayout *verticalLayout_3;
    QFrame *lineChartFrame;
    QWidget *areaChartTab;
    QVBoxLayout *verticalLayout_2;
    QFrame *areaChartFrame;
    QWidget *barChartTab;
    QVBoxLayout *verticalLayout_4;
    QFrame *barChartFrame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainTabWidget = new QTabWidget(centralWidget);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        lineChartTab = new QWidget();
        lineChartTab->setObjectName(QString::fromUtf8("lineChartTab"));
        verticalLayout_3 = new QVBoxLayout(lineChartTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineChartFrame = new QFrame(lineChartTab);
        lineChartFrame->setObjectName(QString::fromUtf8("lineChartFrame"));
        lineChartFrame->setFrameShape(QFrame::NoFrame);
        lineChartFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(lineChartFrame);

        mainTabWidget->addTab(lineChartTab, QString());
        areaChartTab = new QWidget();
        areaChartTab->setObjectName(QString::fromUtf8("areaChartTab"));
        verticalLayout_2 = new QVBoxLayout(areaChartTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        areaChartFrame = new QFrame(areaChartTab);
        areaChartFrame->setObjectName(QString::fromUtf8("areaChartFrame"));
        areaChartFrame->setFrameShape(QFrame::NoFrame);
        areaChartFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(areaChartFrame);

        mainTabWidget->addTab(areaChartTab, QString());
        barChartTab = new QWidget();
        barChartTab->setObjectName(QString::fromUtf8("barChartTab"));
        verticalLayout_4 = new QVBoxLayout(barChartTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        barChartFrame = new QFrame(barChartTab);
        barChartFrame->setObjectName(QString::fromUtf8("barChartFrame"));
        barChartFrame->setFrameShape(QFrame::NoFrame);
        barChartFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(barChartFrame);

        mainTabWidget->addTab(barChartTab, QString());

        verticalLayout->addWidget(mainTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fidami", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(lineChartTab), QApplication::translate("MainWindow", "LineChart", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(areaChartTab), QApplication::translate("MainWindow", "AreaChart", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(barChartTab), QApplication::translate("MainWindow", "BarChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
