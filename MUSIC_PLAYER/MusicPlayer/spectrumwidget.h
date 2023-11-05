#ifndef SPECTRUMWIDGET_H
#define SPECTRUMWIDGET_H

#include <QWidget>
#include <fmod.h>
#include <fmod_errors.h>
#include <fmod_output.h>
#include <QPainter>
#include <QPaintEvent>
#include <QAudioBuffer>
#include <string.h>
#include <iostream>
using namespace std;


class SpectrumWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpectrumWidget(QWidget *parent = nullptr);
    ~SpectrumWidget();
    void setPath(QString p);
protected:
    void paintEvent(QPaintEvent *event);
private:
    FMOD_SYSTEM *system;
    FMOD_SOUND *sound;
    FMOD_CHANNEL *channel;
    FMOD_RESULT result;
    QTimer *timer;
    char* path;

    static const int numValues = 64;
    float spectrum[numValues];
public slots:
    void updateSpectrum();
};

#endif // SPECTRUMWIDGET_H
