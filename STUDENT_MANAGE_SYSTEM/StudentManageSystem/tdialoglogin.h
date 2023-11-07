#ifndef TDIALOGLOGIN_H
#define TDIALOGLOGIN_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class TDialogLogin;
}

class TDialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit TDialogLogin(QWidget *parent = nullptr);
    ~TDialogLogin();

private slots:
    void on_btnLogIn_clicked();
    void on_btnQuit_clicked();

private:
    Ui::TDialogLogin *ui;

};

#endif // TDIALOGLOGIN_H
