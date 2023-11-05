#include "spectrumwidget.h"

SpectrumWidget::SpectrumWidget(QWidget *parent)
    : QWidget{parent}
{
    FMOD_System_Create(&system,result);//初始化fmod系统对象
    FMOD_System_Init(system,32,FMOD_INIT_NORMAL,0); //参数2：最大通道数，参数3：初始化标志
    FMOD_System_GetChannel(system,0,&channel);  //初始化channel对象
}

SpectrumWidget::~SpectrumWidget()
{
    FMOD_Sound_Release(sound);
    FMOD_System_Close(system);
    FMOD_System_Release(system);
}

void SpectrumWidget::setPath(QString p)
{
    QByteArray ba = p.toLocal8Bit();
    path = ba.data();
    std::cout<<path;
    FMOD_System_CreateSound(system,path,FMOD_DEFAULT,0,&sound); //创建声音对象，参数3：使用的模式，参数4：驱动程序句柄
    FMOD_System_PlaySound(system,sound,nullptr,false,&channel);  //播放声音对象
}

void SpectrumWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  //平滑像素
    QPen pen;
    pen.setColor(Qt::red);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::green);
    painter.setBrush(brush);
    int width = this->width()/numValues;
    for(int i=0; i<numValues; i++)
    {
        int height = spectrum[i]*this->height();
        painter.drawRect(i*width, this->height()-height, width, height);
    }
    event->accept();
}

void SpectrumWidget::updateSpectrum()
{
    float frequency;
    for(int i=0; i<numValues; i++)
    {
        FMOD_Channel_GetFrequency(channel,&frequency);
        spectrum[i] = frequency;
    }
    this->update();
}


