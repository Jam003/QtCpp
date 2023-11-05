#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QItemSelection>
#include <QtSql>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QScreen>
#include <QToolButton>

namespace Ui {
class PlayList;
}

class PlayList : public QWidget
{
    Q_OBJECT
private:
    QToolButton *tbtnAdd;
    QToolButton *tbtnDelete;
    QToolButton *tbtnLyrics;
    QToolButton *tbtnPicture;
    QToolButton *tbtnTop;
    QToolButton *tbtnUp;
    QToolButton *tbtnDown;
    QToolButton *tbtnBottom;
    QString Title;
    QString Path;
    QString Lyrics;
    QString Pic;
    QSqlDatabase DB;
    QSqlTableModel *tabModel;
    QItemSelectionModel *selModel;
    void OpenTable();
public:
    explicit PlayList(QWidget *parent = nullptr);
    ~PlayList();
private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

    void on_actAdd_triggered();

    void on_actDelete_triggered();

    void on_actLyrics_triggered();

    void on_actPicture_triggered();

    void on_actTop_triggered();

    void on_actUp_triggered();

    void on_actDown_triggered();

    void on_actBottom_triggered();

public slots:
    void do_toLastPath();
    void do_toNextPath();
signals:
    void currentChanged(QString Title, QString Path, QString Lyrics, QString Pic);
private:
    Ui::PlayList *ui;
};

#endif // PLAYLIST_H
