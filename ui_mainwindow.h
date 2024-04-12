/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *batteryLowAction;
    QAction *batteryResetAction;
    QAction *actionComputer_view;
    QAction *computerViewAction;
    QAction *connectTerminalAction;
    QAction *disconnectTerminalAction;
    QAction *setWavesAction;
    QWidget *centralwidget;
    QTabWidget *primaryTabs;
    QWidget *tab;
    QProgressBar *treatmentProgress;
    QLabel *treatmentProgressLabel;
    QLabel *treatmentAlertLabel;
    QCustomPlot *waveDisplay;
    QLabel *waveLabel;
    QWidget *tab_3;
    QWidget *tab_2;
    QLCDNumber *yearDisplay;
    QLCDNumber *monthDisplay;
    QLCDNumber *dayDisplay;
    QLCDNumber *hourDisplay;
    QLCDNumber *minuteDisplay;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *menuTabTreatment;
    QLabel *menuTabLogs;
    QLabel *menuTabSettings;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pauseButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *playButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *stopButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *menuButton;
    QPushButton *powerButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *neuresetMenu;
    QMenu *batteryOptions;
    QMenu *menuEEG_terminals;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1014, 528);
        batteryLowAction = new QAction(MainWindow);
        batteryLowAction->setObjectName(QString::fromUtf8("batteryLowAction"));
        batteryResetAction = new QAction(MainWindow);
        batteryResetAction->setObjectName(QString::fromUtf8("batteryResetAction"));
        actionComputer_view = new QAction(MainWindow);
        actionComputer_view->setObjectName(QString::fromUtf8("actionComputer_view"));
        computerViewAction = new QAction(MainWindow);
        computerViewAction->setObjectName(QString::fromUtf8("computerViewAction"));
        connectTerminalAction = new QAction(MainWindow);
        connectTerminalAction->setObjectName(QString::fromUtf8("connectTerminalAction"));
        disconnectTerminalAction = new QAction(MainWindow);
        disconnectTerminalAction->setObjectName(QString::fromUtf8("disconnectTerminalAction"));
        setWavesAction = new QAction(MainWindow);
        setWavesAction->setObjectName(QString::fromUtf8("setWavesAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        primaryTabs = new QTabWidget(centralwidget);
        primaryTabs->setObjectName(QString::fromUtf8("primaryTabs"));
        primaryTabs->setGeometry(QRect(10, 10, 701, 471));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        treatmentProgress = new QProgressBar(tab);
        treatmentProgress->setObjectName(QString::fromUtf8("treatmentProgress"));
        treatmentProgress->setGeometry(QRect(200, 380, 281, 31));
        treatmentProgress->setValue(24);
        treatmentProgressLabel = new QLabel(tab);
        treatmentProgressLabel->setObjectName(QString::fromUtf8("treatmentProgressLabel"));
        treatmentProgressLabel->setGeometry(QRect(270, 340, 151, 16));
        treatmentAlertLabel = new QLabel(tab);
        treatmentAlertLabel->setObjectName(QString::fromUtf8("treatmentAlertLabel"));
        treatmentAlertLabel->setGeometry(QRect(200, 220, 281, 20));
        waveDisplay = new QCustomPlot(tab);
        waveDisplay->setObjectName(QString::fromUtf8("waveDisplay"));
        waveDisplay->setGeometry(QRect(90, 110, 481, 201));
        waveLabel = new QLabel(tab);
        waveLabel->setObjectName(QString::fromUtf8("waveLabel"));
        waveLabel->setGeometry(QRect(220, 60, 231, 20));
        primaryTabs->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        primaryTabs->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        yearDisplay = new QLCDNumber(tab_2);
        yearDisplay->setObjectName(QString::fromUtf8("yearDisplay"));
        yearDisplay->setGeometry(QRect(100, 100, 150, 120));
        yearDisplay->setFrameShape(QFrame::Box);
        yearDisplay->setFrameShadow(QFrame::Plain);
        yearDisplay->setLineWidth(1);
        monthDisplay = new QLCDNumber(tab_2);
        monthDisplay->setObjectName(QString::fromUtf8("monthDisplay"));
        monthDisplay->setGeometry(QRect(260, 100, 150, 120));
        monthDisplay->setFrameShadow(QFrame::Plain);
        dayDisplay = new QLCDNumber(tab_2);
        dayDisplay->setObjectName(QString::fromUtf8("dayDisplay"));
        dayDisplay->setGeometry(QRect(420, 100, 150, 120));
        QFont font;
        font.setPointSize(12);
        dayDisplay->setFont(font);
        dayDisplay->setFrameShadow(QFrame::Plain);
        hourDisplay = new QLCDNumber(tab_2);
        hourDisplay->setObjectName(QString::fromUtf8("hourDisplay"));
        hourDisplay->setGeometry(QRect(260, 270, 150, 120));
        hourDisplay->setFrameShadow(QFrame::Plain);
        minuteDisplay = new QLCDNumber(tab_2);
        minuteDisplay->setObjectName(QString::fromUtf8("minuteDisplay"));
        minuteDisplay->setGeometry(QRect(420, 270, 150, 120));
        minuteDisplay->setFrameShadow(QFrame::Plain);
        minuteDisplay->setSmallDecimalPoint(false);
        minuteDisplay->setMode(QLCDNumber::Dec);
        minuteDisplay->setSegmentStyle(QLCDNumber::Filled);
        primaryTabs->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayoutWidget_2 = new QWidget(tab_4);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(300, 180, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        menuTabTreatment = new QLabel(verticalLayoutWidget_2);
        menuTabTreatment->setObjectName(QString::fromUtf8("menuTabTreatment"));

        verticalLayout_2->addWidget(menuTabTreatment);

        menuTabLogs = new QLabel(verticalLayoutWidget_2);
        menuTabLogs->setObjectName(QString::fromUtf8("menuTabLogs"));

        verticalLayout_2->addWidget(menuTabLogs);

        menuTabSettings = new QLabel(verticalLayoutWidget_2);
        menuTabSettings->setObjectName(QString::fromUtf8("menuTabSettings"));

        verticalLayout_2->addWidget(menuTabSettings);

        primaryTabs->addTab(tab_4, QString());
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(800, 300, 151, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/assets/pauseIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon);

        horizontalLayout->addWidget(pauseButton);

        horizontalSpacer = new QSpacerItem(120, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/assets/playIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);

        horizontalLayout->addWidget(playButton);

        horizontalSpacer_2 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/assets/stopButton.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon2);

        horizontalLayout->addWidget(stopButton);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(860, 150, 31, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        upButton = new QPushButton(verticalLayoutWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/assets/uparrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon3);

        verticalLayout->addWidget(upButton);

        downButton = new QPushButton(verticalLayoutWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/assets/downarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon4);

        verticalLayout->addWidget(downButton);

        menuButton = new QPushButton(centralwidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(800, 110, 31, 23));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/assets/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuButton->setIcon(icon5);
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(899, 10, 101, 23));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1014, 22));
        neuresetMenu = new QMenu(menubar);
        neuresetMenu->setObjectName(QString::fromUtf8("neuresetMenu"));
        batteryOptions = new QMenu(neuresetMenu);
        batteryOptions->setObjectName(QString::fromUtf8("batteryOptions"));
        menuEEG_terminals = new QMenu(neuresetMenu);
        menuEEG_terminals->setObjectName(QString::fromUtf8("menuEEG_terminals"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(neuresetMenu->menuAction());
        neuresetMenu->addAction(menuEEG_terminals->menuAction());
        neuresetMenu->addAction(batteryOptions->menuAction());
        neuresetMenu->addAction(computerViewAction);
        batteryOptions->addAction(batteryLowAction);
        batteryOptions->addAction(batteryResetAction);
        menuEEG_terminals->addAction(connectTerminalAction);
        menuEEG_terminals->addAction(disconnectTerminalAction);

        retranslateUi(MainWindow);

        primaryTabs->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        batteryLowAction->setText(QCoreApplication::translate("MainWindow", "Set low", nullptr));
        batteryResetAction->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionComputer_view->setText(QCoreApplication::translate("MainWindow", "Computer view", nullptr));
        computerViewAction->setText(QCoreApplication::translate("MainWindow", "Computer view", nullptr));
        connectTerminalAction->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        disconnectTerminalAction->setText(QCoreApplication::translate("MainWindow", "disconnect", nullptr));
        setWavesAction->setText(QCoreApplication::translate("MainWindow", "Set Wave Values", nullptr));
        treatmentProgressLabel->setText(QCoreApplication::translate("MainWindow", "Treatment Progress", nullptr));
        treatmentAlertLabel->setText(QString());
        waveLabel->setText(QString());
        primaryTabs->setTabText(primaryTabs->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Page", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menuTabTreatment->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuTabLogs->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuTabSettings->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Page", nullptr));
        pauseButton->setText(QString());
        playButton->setText(QString());
        stopButton->setText(QString());
        upButton->setText(QString());
        downButton->setText(QString());
        menuButton->setText(QString());
        powerButton->setText(QCoreApplication::translate("MainWindow", "Power Button", nullptr));
        neuresetMenu->setTitle(QCoreApplication::translate("MainWindow", "NEURESET LENS SOFTWARE", nullptr));
        batteryOptions->setTitle(QCoreApplication::translate("MainWindow", "Battery drain", nullptr));
        menuEEG_terminals->setTitle(QCoreApplication::translate("MainWindow", "EEG terminals", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
