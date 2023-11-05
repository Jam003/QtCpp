#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SliderProcess = new QSlider(ui->groupBox_2);
    SliderVolumn = new QSlider(ui->groupBox_2);
    PlainTextEdit = new QPlainTextEdit(this);
    LabPic = new QLabel(ui->scrollArea_2);
    lst = new PlayList();
    play = new TProcess(this);
    spec = new SpectrumWidget(this);


    this->setWindowTitle("MusicPlayer");
    SliderProcess->setStyleSheet("QSlider:horizontal{border:0px}"
                                 "QSlider::groove:horizontal{border:0px solid}"
                                 "QSlider::add-page:horizontal{background:rgb(0,0,0);border-radius:2px;margin-top:5px;margin-bottom:5px}"
                                 "QSlider::sub-page:horizontal{background:rgb(255,255,0);border-radius:2px;margin-top:5px;margin-bottom:5px}"
                                 "QSlider::handle:horizontal{background:rgb(255,255,255);width:5px;border:1px solid;border-radius:2px;margin-top:3px;margin-bottom:3px}");
    SliderProcess->setGeometry(10,45,236,15);
    SliderProcess->setOrientation(Qt::Horizontal);
    SliderProcess->setTracking(true);
    SliderVolumn->setStyleSheet("QSlider:horizontal{border:0px}"
                                "QSlider::groove:horizontal{border:0px solid}"
                                "QSlider::add-page:horizontal{background:rgb(0,0,0);border-radius:2px;margin-top:5px;margin-bottom:5px}"
                                "QSlider::sub-page:horizontal{background:rgb(255,255,0);border-radius:2px;margin-top:5px;margin-bottom:5px}"
                                "QSlider::handle:horizontal{background:rgb(255,255,255);width:5px;border:1px solid;border-radius:2px;margin-top:3px;margin-bottom:3px}");
    SliderVolumn->setGeometry(210,20,89,15);
    SliderVolumn->setOrientation(Qt::Horizontal);
    PlainTextEdit->setGeometry(150,20,151,191);
    PlainTextEdit->setReadOnly(true);
    PlainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    PlainTextEdit->setStyleSheet("color:rgb(255,255,255)"
                                );
    LabPic->setGeometry(4,4,110,102);
    QPoint p = this->geometry().topRight();
    lst->move(p.x()+800,p.y()+350);
    lst->setVisible(false);
    //player->setAudioOutput(audioOutput);
    ui->btnLast->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\上一个2.png"));
    ui->btnPlayOrPause->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\播放（实心）.png"));
    ui->btnNext->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\下一个2.png"));
    ui->btnSongList->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\横排（菜单）2.png"));
    ui->labVolumn->setPixmap(QPixmap("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\声音（开）2.png").scaled(ui->labVolumn->width(),ui->labVolumn->height()));
    SliderVolumn->setValue(50);
    spec->setGeometry(20,150,121,51);


    connect(ui->btnLast,&QAbstractButton::clicked,lst,&PlayList::do_toLastPath);
    connect(ui->btnNext,&QAbstractButton::clicked,lst,&PlayList::do_toNextPath);
    connect(play->getPlayer(),&QMediaPlayer::positionChanged,this,&MainWindow::do_positionChanged,Qt::QueuedConnection);
    connect(play->getPlayer(),&QMediaPlayer::durationChanged,this,&MainWindow::do_durationChanged,Qt::QueuedConnection);
    connect(SliderProcess,&QSlider::sliderReleased,this,&MainWindow::on_SliderProcess_valueChanged);
    connect(SliderVolumn,&QSlider::valueChanged,this,&MainWindow::on_SliderVolumn_valueChanged);
    connect(lst,&PlayList::currentChanged,this,&MainWindow::do_currentChanged);
    connect(lst,&PlayList::currentChanged,play,&TProcess::do_currentChanged);
    connect(this,&MainWindow::pause,play,&TProcess::set_pause);
    connect(this,&MainWindow::volumn,play,&TProcess::set_volumn);
    connect(this,&MainWindow::process,play,&TProcess::set_process);


    play->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete play;
    play = nullptr;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    lst->setVisible(false);
    ui->btnSongList->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(play->isRunning())
    {
        play->terminate();   //终止线程的运行，但不是立即终止，需要等待操作系统结束线程，所以在后面调用wait阻塞该线程，直到线程被终止
        play->wait();
    }
    event->accept();
}


void MainWindow::on_btnSongList_clicked()
{
    lst->setVisible(true);
    ui->btnSongList->setEnabled(false);
}


void MainWindow::do_currentChanged(QString Title, QString Path, QString Lyrics, QString Pic)
{
    Q_UNUSED(Path);
    Q_UNUSED(Title);
    //player->setSource(QUrl(Path));
    //ui->EditSongTitle->setText(Title);
    PlainTextEdit->setPlainText(Lyrics);
    qDebug("%s",qPrintable(Pic));   //qPrintable将QString转换成c字符串
    pic.load(Pic);
    LabPic->setPixmap(pic.scaled(ui->scrollArea_2->width(),ui->scrollArea_2->height()));
    //player->play();
    ui->btnPlayOrPause->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\暂停（圆）.png"));

    //spec->setPath(Path);
}


void MainWindow::on_btnPlayOrPause_clicked()
{
    if(play->getPlayer()->playbackState() == QMediaPlayer::PlayingState)
    {
        emit(pause(true));
        //player->pause();
        ui->btnPlayOrPause->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\播放（实心）.png"));
    }
    else if(play->getPlayer()->playbackState() == QMediaPlayer::PausedState)
    {
        emit(pause(false));
        //player->play();
        ui->btnPlayOrPause->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\暂停（圆）.png"));
    }
}


void MainWindow::on_btnLast_clicked()
{
    emit tolastPath();
}


void MainWindow::on_btnNext_clicked()
{
    emit toNextPath();
}


void MainWindow::on_SliderVolumn_valueChanged(int value)
{
    emit(volumn(value));
    if(value == 0)
        ui->labVolumn->setPixmap(QPixmap("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\声音（关）2.png").scaled(ui->labVolumn->width(),ui->labVolumn->height()));
    else
        ui->labVolumn->setPixmap(QPixmap("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\声音（开）2.png").scaled(ui->labVolumn->width(),ui->labVolumn->height()));
    //player->audioOutput()->setVolume(value/100.0);
}


void MainWindow::on_SliderProcess_valueChanged()
{
    int value = SliderProcess->value();
    emit(process(value));
    //player->setPosition(value);
}


void MainWindow::do_durationChanged(qint64 duration)
{
    SliderProcess->setMaximum(duration);   //这里传过来的参数是毫秒数
    int secs = duration/1000;
    int mins = secs/60;
    secs = secs%60;
    durationTime = QString::asprintf("%d:%d",mins,secs);
    ui->label->setText(positionTime+"/"+durationTime);
}


void MainWindow::do_positionChanged(qint64 position)
{
    if(SliderProcess->isSliderDown())
        return;
    SliderProcess->setSliderPosition(position);
    int secs = position/1000;
    int mins = secs/60;
    secs = secs%60;
    positionTime = QString::asprintf("%d:%d",mins,secs);
    ui->label->setText(positionTime+"/"+durationTime);
}



void MainWindow::on_btnPlayMode_clicked()
{

}

