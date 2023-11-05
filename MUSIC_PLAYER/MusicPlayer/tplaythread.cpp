#include "tplaythread.h"


TPlayThread::TPlayThread(QObject *parent)
    : QThread{parent}
{
    lst = new PlayList();
    //lst->move(p.x()+800,p.y()+350);
    lst->setVisible(false);
}

PlayList *TPlayThread::getList()
{
    return lst;
}


void TPlayThread::run()
{
    while(1)
    {
        QUrl source = QUrl(lst->getPath());
        Path = source;
        Title = lst->getTitle();
        Lyrics = lst->getLyrics();
        Pic = lst->getPic();
        emit sourceChanged(Path,Title,Lyrics,Pic);
    }

}


