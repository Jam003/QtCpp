/********************************************************************************
** Form generated from reading UI file 'tdialoglogin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDIALOGLOGIN_H
#define UI_TDIALOGLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_TDialogLogin
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *editAccount;
    QLineEdit *editPassword;
    QPushButton *btnLogIn;
    QPushButton *btnQuit;

    void setupUi(QDialog *TDialogLogin)
    {
        if (TDialogLogin->objectName().isEmpty())
            TDialogLogin->setObjectName(QString::fromUtf8("TDialogLogin"));
        TDialogLogin->resize(369, 193);
        gridLayout = new QGridLayout(TDialogLogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(TDialogLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        label = new QLabel(TDialogLogin);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        editAccount = new QLineEdit(TDialogLogin);
        editAccount->setObjectName(QString::fromUtf8("editAccount"));

        gridLayout->addWidget(editAccount, 0, 2, 1, 2);

        editPassword = new QLineEdit(TDialogLogin);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));

        gridLayout->addWidget(editPassword, 1, 2, 1, 2);

        btnLogIn = new QPushButton(TDialogLogin);
        btnLogIn->setObjectName(QString::fromUtf8("btnLogIn"));

        gridLayout->addWidget(btnLogIn, 2, 1, 1, 1);

        btnQuit = new QPushButton(TDialogLogin);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));

        gridLayout->addWidget(btnQuit, 2, 3, 1, 1);


        retranslateUi(TDialogLogin);

        QMetaObject::connectSlotsByName(TDialogLogin);
    } // setupUi

    void retranslateUi(QDialog *TDialogLogin)
    {
        TDialogLogin->setWindowTitle(QCoreApplication::translate("TDialogLogin", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("TDialogLogin", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("TDialogLogin", "\350\264\246\345\217\267", nullptr));
        btnLogIn->setText(QCoreApplication::translate("TDialogLogin", "\347\241\256\345\256\232", nullptr));
        btnQuit->setText(QCoreApplication::translate("TDialogLogin", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TDialogLogin: public Ui_TDialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDIALOGLOGIN_H
