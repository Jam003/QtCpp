/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QPushButton *btnSongList;
    QLabel *labVolumn;
    QPushButton *btnNext;
    QPushButton *btnPlayOrPause;
    QPushButton *btnLast;
    QPushButton *btnPlayMode;
    QLabel *label;
    QSlider *SliderVolumn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(319, 290);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(0, 0, 321, 221));
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 64, 64);\n"
"border:none\n"
""));
        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(20, 20, 121, 111));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 121, 111));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(4, 4, 110, 102));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 222, 321, 91));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 32, 32);\n"
"border:1px solid rgb(0, 0, 0);\n"
"\n"
""));
        groupBox_2->setAlignment(Qt::AlignCenter);
        btnSongList = new QPushButton(groupBox_2);
        btnSongList->setObjectName(QString::fromUtf8("btnSongList"));
        btnSongList->setGeometry(QRect(127, 10, 30, 30));
        labVolumn = new QLabel(groupBox_2);
        labVolumn->setObjectName(QString::fromUtf8("labVolumn"));
        labVolumn->setGeometry(QRect(185, 20, 20, 15));
        labVolumn->setStyleSheet(QString::fromUtf8("border:0px"));
        btnNext = new QPushButton(groupBox_2);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(98, 10, 30, 30));
        btnNext->setIconSize(QSize(16, 16));
        btnPlayOrPause = new QPushButton(groupBox_2);
        btnPlayOrPause->setObjectName(QString::fromUtf8("btnPlayOrPause"));
        btnPlayOrPause->setGeometry(QRect(69, 10, 30, 30));
        btnLast = new QPushButton(groupBox_2);
        btnLast->setObjectName(QString::fromUtf8("btnLast"));
        btnLast->setGeometry(QRect(40, 10, 30, 30));
        btnLast->setStyleSheet(QString::fromUtf8(""));
        btnPlayMode = new QPushButton(groupBox_2);
        btnPlayMode->setObjectName(QString::fromUtf8("btnPlayMode"));
        btnPlayMode->setGeometry(QRect(11, 10, 30, 30));
        btnPlayMode->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(255, 45, 45, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:0px"));
        SliderVolumn = new QSlider(groupBox_2);
        SliderVolumn->setObjectName(QString::fromUtf8("SliderVolumn"));
        SliderVolumn->setGeometry(QRect(210, 20, 89, 15));
        SliderVolumn->setStyleSheet(QString::fromUtf8(""));
        SliderVolumn->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_2->setTitle(QString());
        btnSongList->setText(QString());
        labVolumn->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnNext->setText(QString());
        btnPlayOrPause->setText(QString());
        btnLast->setText(QString());
        btnPlayMode->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "0.0/0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
