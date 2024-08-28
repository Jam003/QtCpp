#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MyOpenglWidget* openglW;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void do_update();
    void do_btnFileSelect_clicked();
    void do_btnTexSelect_clicked();
    void do_hSliderAngleX_valueChanged(int value);
    void do_hSliderAngleY_valueChanged(int value);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
