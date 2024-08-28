/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnFileSelect;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSlider *hSliderAngleY;
    QLineEdit *lineEditAngleX;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditAngleY;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSlider *hSliderAngleX;
    QPushButton *btnTexSelect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnFileSelect = new QPushButton(centralwidget);
        btnFileSelect->setObjectName("btnFileSelect");
        btnFileSelect->setGeometry(QRect(670, 20, 75, 24));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(550, 120, 200, 108));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        hSliderAngleY = new QSlider(groupBox);
        hSliderAngleY->setObjectName("hSliderAngleY");
        hSliderAngleY->setMaximum(360);
        hSliderAngleY->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(hSliderAngleY, 3, 0, 1, 4);

        lineEditAngleX = new QLineEdit(groupBox);
        lineEditAngleX->setObjectName("lineEditAngleX");

        gridLayout->addWidget(lineEditAngleX, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        lineEditAngleY = new QLineEdit(groupBox);
        lineEditAngleY->setObjectName("lineEditAngleY");

        gridLayout->addWidget(lineEditAngleY, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        hSliderAngleX = new QSlider(groupBox);
        hSliderAngleX->setObjectName("hSliderAngleX");
        hSliderAngleX->setMaximum(360);
        hSliderAngleX->setSingleStep(1);
        hSliderAngleX->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(hSliderAngleX, 1, 0, 1, 4);

        btnTexSelect = new QPushButton(centralwidget);
        btnTexSelect->setObjectName("btnTexSelect");
        btnTexSelect->setGeometry(QRect(670, 70, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnFileSelect->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "AngleY", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "AngleX", nullptr));
        btnTexSelect->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\272\271\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
