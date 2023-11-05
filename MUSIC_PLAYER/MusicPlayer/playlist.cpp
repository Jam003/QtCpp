#include "playlist.h"
#include "ui_playlist.h"
#include <mainwindow.h>

PlayList::PlayList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);
    tbtnAdd = new QToolButton(this);
    tbtnDelete = new QToolButton(this);
    tbtnLyrics = new QToolButton(this);
    tbtnPicture = new QToolButton(this);
    tbtnTop = new QToolButton(this);
    tbtnUp = new QToolButton(this);
    tbtnDown = new QToolButton(this);
    tbtnBottom = new QToolButton(this);

    tbtnAdd->setDefaultAction(ui->actAdd);
    tbtnDelete->setDefaultAction(ui->actDelete);
    tbtnLyrics->setDefaultAction(ui->actLyrics);
    tbtnPicture->setDefaultAction(ui->actPicture);
    tbtnTop->setDefaultAction(ui->actTop);
    tbtnUp->setDefaultAction(ui->actUp);
    tbtnDown->setDefaultAction(ui->actDown);
    tbtnBottom->setDefaultAction(ui->actBottom);

    tbtnAdd->setGeometry(3,2,41,21);
    tbtnDelete->setGeometry(43,2,41,21);
    tbtnLyrics->setGeometry(83,2,41,21);
    tbtnPicture->setGeometry(123,2,41,21);
    tbtnTop->setGeometry(3,295,41,21);
    tbtnUp->setGeometry(43,295,41,21);
    tbtnDown->setGeometry(83,295,41,21);
    tbtnBottom->setGeometry(123,295,41,21);

    tbtnAdd->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\添加（圆）.png"));
    tbtnDelete->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\删除.png"));
    tbtnLyrics->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\提交，上传，提取.png"));
    tbtnPicture->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\图片文件.png"));
    tbtnTop->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\向上（双线）.png"));
    tbtnUp->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\向上（箭头）.png"));
    tbtnDown->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\向下（箭头）.png"));
    tbtnBottom->setIcon(QIcon("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\icons\\向下（双线）.png"));

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\Music.db");
    if(!DB.open())
        QMessageBox::warning(this,"错误","数据库加载失败");
    else
        OpenTable();

}

PlayList::~PlayList()
{
    delete ui;
}


void PlayList::OpenTable()
{
    tabModel = new QSqlTableModel(this,DB);
    selModel = new QItemSelectionModel(tabModel,this);
    tabModel->setTable("Music");
    tabModel->setEditStrategy(QSqlTableModel::OnRowChange);
    if(!(tabModel->select()))
    {
        QMessageBox::critical(this,"错误","打开数据表错误\n"+tabModel->lastError().text());
        return;
    }

    ui->listView->setModel(tabModel);
    ui->listView->setSelectionModel(selModel);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


void PlayList::on_actAdd_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"添加歌曲","G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\Songs","音频文件(*.mp3)");
    for(int i=0; i<files.count(); i++)
    {
        QFileInfo aFile(files.at(i));
        QSqlRecord rec = tabModel->record();
        rec.setValue(tabModel->fieldIndex("Title"),aFile.fileName());
        rec.setValue(tabModel->fieldIndex("Path"),aFile.filePath());
        tabModel->insertRecord(tabModel->rowCount(),rec);
        tabModel->submit();
    }
}


void PlayList::on_actDelete_triggered()
{
    QModelIndex index = selModel->currentIndex();
    tabModel->removeRow(index.row());
    tabModel->submit();
    tabModel->select();
}


void PlayList::on_actLyrics_triggered()
{
    QString aFile = QFileDialog::getOpenFileName(this,"导入歌词","G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\Songs","歌词文件(*.lrc)");
    QFile file(aFile);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::critical(this,"错误","文件打开失败");
    QString lyrics = file.readAll();
    int row = selModel->currentIndex().row();
    QSqlRecord rec = tabModel->record(row);
    rec.setValue(tabModel->fieldIndex("Lyrics"),lyrics);
    tabModel->setRecord(row,rec);
    tabModel->submitAll();
}


void PlayList::on_actPicture_triggered()
{
    QString aFile = QFileDialog::getOpenFileName(this,"导入歌词","G:\\QtLearn_ProgramTest\\MUSIC_PLAYER\\Songs","歌曲海报(*.jpg *.webp)");
    int row = selModel->currentIndex().row();
    QSqlRecord rec = tabModel->record(row);
    rec.setValue(tabModel->fieldIndex("Picture"),aFile);
    tabModel->setRecord(row,rec);
    tabModel->submitAll();
}


void PlayList::on_actTop_triggered()
{
    int cur = selModel->currentIndex().row();
    QModelIndex index = QModelIndex();   //建立一个空的索引作为头节点索引，对于tabModel来说，每个节点没有父节点，头节点就是每个节点的父节点
    tabModel->moveRow(index,cur,index,0);
    tabModel->submit();
    tabModel->select();
}


void PlayList::on_actUp_triggered()
{
    int cur = selModel->currentIndex().row();
    QModelIndex index = QModelIndex();
    tabModel->moveRow(index,cur,index,cur-1);
    tabModel->submitAll();
    tabModel->select();
}


void PlayList::on_actDown_triggered()
{
    int cur = selModel->currentIndex().row();
    QModelIndex index = QModelIndex();
    tabModel->moveRow(index,cur,index,cur+2);
    tabModel->submit();
    tabModel->select();
}


void PlayList::on_actBottom_triggered()
{
    int cur = selModel->currentIndex().row();
    QModelIndex index = QModelIndex();
    tabModel->moveRow(index,cur,index,tabModel->rowCount());
    tabModel->submit();
    tabModel->select();
}



void PlayList::on_listView_doubleClicked(const QModelIndex &index)
{
    QSqlRecord record = tabModel->record(index.row());
    Title = record.value("Title").toString();
    Path = record.value("Path").toString();
    Lyrics = record.value("Lyrics").toString();
    Pic = record.value("Picture").toString();
    emit currentChanged(Title, Path, Lyrics, Pic);
}

void PlayList::do_toLastPath()
{
    int cur = selModel->currentIndex().row();
    if(cur == 0)
        return;
    QSqlRecord record = tabModel->record(cur-1);
    Title = record.value("Title").toString();
    Path = record.value("Path").toString();
    Lyrics = record.value("Lyrics").toString();
    Pic = record.value("Picture").toString();
    QModelIndex index = tabModel->index(cur-1,0);
    selModel->setCurrentIndex(index,QItemSelectionModel::Current);
    emit currentChanged(Title, Path, Lyrics, Pic);
}

void PlayList::do_toNextPath()
{
    int cur = selModel->currentIndex().row();
    if(cur == tabModel->rowCount()-1)
        return;
    QSqlRecord record = tabModel->record(cur+1);
    Title = record.value("Title").toString();
    Path = record.value("Path").toString();
    Lyrics = record.value("Lyrics").toString();
    Pic = record.value("Picture").toString();
    QModelIndex index = tabModel->index(cur+1,0);
    selModel->setCurrentIndex(index,QItemSelectionModel::Current);
    emit currentChanged(Title, Path, Lyrics, Pic);
}









