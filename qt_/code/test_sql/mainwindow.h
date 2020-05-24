#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlQuery>

#include <QFileDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_tables_activated(int index);

    void on_columns_activated(int index);

private:
    Ui::MainWindow *ui;

    QSqlDatabase DB;
    QSqlQuery query;

    QString pathDB;

    void showData();
    void addTables();
    void makeRequest();
    void addColumns();
    void addValues(int index);
};
#endif // MAINWINDOW_H
