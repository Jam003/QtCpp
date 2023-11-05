#include "tprocess.h"

TProcess::TProcess(QObject *parent)
    : QThread{parent}
{
    player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
}

TProcess::~TProcess()
{
    delete player;
    player = nullptr;
}

QMediaPlayer *TProcess::getPlayer()
{
    return player;
}



void TProcess::run()
{
    while(player != nullptr)  //避免野指针的问题
    {
        if(!pause)
            player->play();
        else
            player->pause();
    }
    quit();
}

void TProcess::do_currentChanged(QString Title, QString Path, QString Lyrics, QString Pic)
{
    Q_UNUSED(Title);
    Q_UNUSED(Lyrics);
    Q_UNUSED(Pic);
    path = QUrl(Path);
    player->setSource(path);
}

void TProcess::set_pause(bool p)
{
    pause = p;
}

void TProcess::set_volumn(int v)
{
    player->audioOutput()->setVolume(v/100.0);
}

void TProcess::set_process(int pr)
{
    player->setPosition(pr);
}

