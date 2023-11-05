#ifndef TPROCESS_H
#define TPROCESS_H

#include <QThread>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <playlist.h>
#include <QAudioBuffer>

class TProcess : public QThread
{
    Q_OBJECT
private:
    qint64 p;
    bool pause = false;
    QMediaPlayer *player;
    QUrl path;
public:
    explicit TProcess(QObject *parent = nullptr);
    ~TProcess();
    QMediaPlayer* getPlayer();
protected:
    void run();
public slots:
    void do_currentChanged(QString Title, QString Path, QString Lyrics, QString Pic);
    void set_pause(bool p);
    void set_volumn(int v);
    void set_process(int pr);
};

#endif // TPROCESS_H
