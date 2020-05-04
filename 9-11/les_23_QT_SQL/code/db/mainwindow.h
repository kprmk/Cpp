#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlQuery>

#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSqlDatabase    dataBase;
    QSqlQuery       sqlQuery;

    QString pathDB;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void fillingData();
    void addTables();
    void makeRequest();
    void addColumns();
    void addValues(int index);
};
#endif // MAINWINDOW_H
