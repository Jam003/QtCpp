#include "tdialoglogin.h"
#include "ui_tdialoglogin.h"
#include <iostream>
#include <QMessageBox>

QSqlDatabase DB;
QSqlQuery query;

TDialogLogin::TDialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TDialogLogin)
{
    ui->setupUi(this);
    ui->editPassword->setEchoMode(QLineEdit::Password);
    this->setWindowFlags(Qt::SplashScreen);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("G:\\QtProgram\\STUDENT_MANAGE_SYSTEM\\StudentManageSystem\\StudentMS.db");    //用绝对路径
    if(DB.open())
    {
        query = QSqlQuery(DB);
        QString sql = "SELECT * FROM user WHERE account = :account";
        query.prepare(sql);
    }
    else
        QMessageBox::critical(this,"消息提示","数据库未打开");
}

TDialogLogin::~TDialogLogin()
{
    delete ui;
}

void TDialogLogin::on_btnLogIn_clicked()
{
    QString account = ui->editAccount->text();
    QString password = ui->editPassword->text();
    query.bindValue(":account",account);       //参数绑定
    query.exec();
    if(query.next())
    {
        if(password == query.value("password").toString())
            this->accept();
    }
    else
    {
        QMessageBox::critical(this,"消息提示","账号或密码输入错误！");
        ui->editAccount->clear();
        ui->editPassword->clear();
    }
}


void TDialogLogin::on_btnQuit_clicked()
{
    this->reject();
}

