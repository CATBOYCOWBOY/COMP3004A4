/********************************************************************************
** Form generated from reading UI file 'computerview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTERVIEW_H
#define UI_COMPUTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComputerView
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTableWidget *tableWidget_Item_Data;
    QPushButton *refreshButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ComputerView)
    {
        if (ComputerView->objectName().isEmpty())
            ComputerView->setObjectName(QString::fromUtf8("ComputerView"));
        ComputerView->resize(800, 600);
        centralwidget = new QWidget(ComputerView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableWidget_Item_Data = new QTableWidget(centralwidget);
        if (tableWidget_Item_Data->columnCount() < 4)
            tableWidget_Item_Data->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Item_Data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Item_Data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Item_Data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Item_Data->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_Item_Data->setObjectName(QString::fromUtf8("tableWidget_Item_Data"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        tableWidget_Item_Data->setFont(font1);
        tableWidget_Item_Data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Item_Data->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget_Item_Data, 1, 0, 1, 1);

        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        gridLayout->addWidget(refreshButton, 2, 0, 1, 1);

        ComputerView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ComputerView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        ComputerView->setMenuBar(menubar);
        statusbar = new QStatusBar(ComputerView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ComputerView->setStatusBar(statusbar);

        retranslateUi(ComputerView);

        QMetaObject::connectSlotsByName(ComputerView);
    } // setupUi

    void retranslateUi(QMainWindow *ComputerView)
    {
        ComputerView->setWindowTitle(QCoreApplication::translate("ComputerView", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ComputerView", "Browse History Log", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Item_Data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ComputerView", "Start Datetime", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Item_Data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ComputerView", "Before Frequency", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Item_Data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ComputerView", "After Datetime", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Item_Data->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ComputerView", "After Frequency", nullptr));
        refreshButton->setText(QCoreApplication::translate("ComputerView", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComputerView: public Ui_ComputerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTERVIEW_H
