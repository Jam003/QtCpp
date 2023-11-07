#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QSqlDatabase DB;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitTable(DB,"student");
    ui->tableView->setModel(tabModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitTable(const QSqlDatabase& DB, QString&& tabName)
{
    tabModel = new QSqlTableModel(this,DB);
    tabModel->setTable(tabName);
    if(!tabModel->select())
        QMessageBox::critical(this,"消息提示","数据加载失败");
}

