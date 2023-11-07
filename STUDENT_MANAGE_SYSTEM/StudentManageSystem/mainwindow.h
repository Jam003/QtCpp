#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlTableModel *tabModel;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitTable(const QSqlDatabase& DB, QString&& tabName);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
