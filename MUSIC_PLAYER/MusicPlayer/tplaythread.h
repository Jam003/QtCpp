#ifndef TPLAYTHREAD_H
#define TPLAYTHREAD_H

#include <QThread>
#include <playlist.h>

class TPlayThread : public QThread
{
    Q_OBJECT
private:
    PlayList *lst;
    QString Title;
    QUrl Path;
    QString Lyrics;
    QString Pic;
protected:
    void run();
public:
    explicit TPlayThread(QObject *parent = nullptr);
    PlayList* getList();
public slots:

signals:
    void sourceChanged(QUrl path, QString Title, QString Lyrics, QString Pic);
};

#endif // TPLAYTHREAD_H
