#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlQuery>

#include <QFileDialog>
#include <QDebug>

#include <QRegExp>

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

    void on_search_for_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QSqlDatabase DB;
    QSqlQuery query;

    QString pathDB;

    QStringList *list;

    void showData();
    void addTables();
    void makeRequest();
    void addColumns();
    void addValues(int index);

    void refreshList();
};
#endif // MAINWINDOW_H
