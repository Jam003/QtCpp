#include "mainwindow.h"
#include "tdialoglogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TDialogLogin digLogin;
    if(digLogin.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
