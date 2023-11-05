#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <playlist.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QScrollArea>
#include <tprocess.h>
#include <spectrumwidget.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap pic;
    QLabel *LabPic;
    QSlider *SliderProcess;
    QSlider *SliderVolumn;
    QPlainTextEdit *PlainTextEdit;
    PlayList *lst;
    //QMediaPlayer *player;
    bool loopPlay = true;
    QString durationTime;
    QString positionTime;
    TProcess *play;
    SpectrumWidget *spec;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnSongList_clicked();

    void on_btnPlayOrPause_clicked();

    void on_btnLast_clicked();
    void on_btnNext_clicked();

    void on_SliderVolumn_valueChanged(int value);

    void on_SliderProcess_valueChanged();

    void do_durationChanged(qint64 duration);
    void do_positionChanged(qint64 position);
    void do_currentChanged(QString Title, QString Path, QString Lyrics, QString Pic);

    void on_btnPlayMode_clicked();

signals:
    void tolastPath();
    void toNextPath();
    void pause(bool p);
    void volumn(int v);
    void process(int pr);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
