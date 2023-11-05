/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayList
{
public:
    QAction *actAdd;
    QAction *actDelete;
    QAction *actLyrics;
    QAction *actPicture;
    QAction *actTop;
    QAction *actUp;
    QAction *actDown;
    QAction *actBottom;
    QListView *listView;

    void setupUi(QWidget *PlayList)
    {
        if (PlayList->objectName().isEmpty())
            PlayList->setObjectName(QString::fromUtf8("PlayList"));
        PlayList->resize(166, 318);
        actAdd = new QAction(PlayList);
        actAdd->setObjectName(QString::fromUtf8("actAdd"));
        actDelete = new QAction(PlayList);
        actDelete->setObjectName(QString::fromUtf8("actDelete"));
        actLyrics = new QAction(PlayList);
        actLyrics->setObjectName(QString::fromUtf8("actLyrics"));
        actPicture = new QAction(PlayList);
        actPicture->setObjectName(QString::fromUtf8("actPicture"));
        actTop = new QAction(PlayList);
        actTop->setObjectName(QString::fromUtf8("actTop"));
        actUp = new QAction(PlayList);
        actUp->setObjectName(QString::fromUtf8("actUp"));
        actDown = new QAction(PlayList);
        actDown->setObjectName(QString::fromUtf8("actDown"));
        actBottom = new QAction(PlayList);
        actBottom->setObjectName(QString::fromUtf8("actBottom"));
        listView = new QListView(PlayList);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(3, 23, 160, 271));

        retranslateUi(PlayList);

        QMetaObject::connectSlotsByName(PlayList);
    } // setupUi

    void retranslateUi(QWidget *PlayList)
    {
        PlayList->setWindowTitle(QCoreApplication::translate("PlayList", "Form", nullptr));
        actAdd->setText(QCoreApplication::translate("PlayList", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
#if QT_CONFIG(tooltip)
        actAdd->setToolTip(QCoreApplication::translate("PlayList", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actDelete->setText(QCoreApplication::translate("PlayList", "\345\210\240\351\231\244\346\255\214\346\233\262", nullptr));
#if QT_CONFIG(tooltip)
        actDelete->setToolTip(QCoreApplication::translate("PlayList", "\345\210\240\351\231\244\346\255\214\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actLyrics->setText(QCoreApplication::translate("PlayList", "\345\257\274\345\205\245\346\255\214\350\257\215", nullptr));
#if QT_CONFIG(tooltip)
        actLyrics->setToolTip(QCoreApplication::translate("PlayList", "\345\257\274\345\205\245\346\255\214\350\257\215", nullptr));
#endif // QT_CONFIG(tooltip)
        actPicture->setText(QCoreApplication::translate("PlayList", "\345\257\274\345\205\245\346\265\267\346\212\245", nullptr));
#if QT_CONFIG(tooltip)
        actPicture->setToolTip(QCoreApplication::translate("PlayList", "\345\257\274\345\205\245\346\265\267\346\212\245", nullptr));
#endif // QT_CONFIG(tooltip)
        actTop->setText(QCoreApplication::translate("PlayList", "\347\275\256\351\241\266", nullptr));
#if QT_CONFIG(tooltip)
        actTop->setToolTip(QCoreApplication::translate("PlayList", "\347\275\256\351\241\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actUp->setText(QCoreApplication::translate("PlayList", "\344\270\212\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        actUp->setToolTip(QCoreApplication::translate("PlayList", "\344\270\212\347\247\273\344\270\200\346\240\274", nullptr));
#endif // QT_CONFIG(tooltip)
        actDown->setText(QCoreApplication::translate("PlayList", "\344\270\213\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        actDown->setToolTip(QCoreApplication::translate("PlayList", "\344\270\213\347\247\273\344\270\200\346\240\274", nullptr));
#endif // QT_CONFIG(tooltip)
        actBottom->setText(QCoreApplication::translate("PlayList", "\347\275\256\345\272\225", nullptr));
#if QT_CONFIG(tooltip)
        actBottom->setToolTip(QCoreApplication::translate("PlayList", "\347\275\256\345\272\225", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class PlayList: public Ui_PlayList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
