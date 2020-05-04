#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    dataBase = QSqlDatabase::addDatabase("QSQLITE");
//    dataBase.setDatabaseName("user.db");

//    if (dataBase.open())
//    {
//        sqlQuery = QSqlQuery(dataBase);

//        sqlQuery.exec("CREATE TABLE humans (name TEXT, age INTEGER)");
//        sqlQuery.exec("INSERT INTO humans VALUES ('GOD', 123456789)");
//        sqlQuery.exec("INSERT INTO humans VALUES ('DENIS', 1)");
//        sqlQuery.exec("INSERT INTO humans VALUES ('Nastya', 12)");
//                sqlQuery.exec("INSERT INTO humans VALUES ('Kirill', 20)");

//        sqlQuery.exec("SELECT * FROM humans");

//        for (const QString & tableName : dataBase.tables())
//            qDebug() << tableName;

//        for (int i = 0; i < sqlQuery.record().count(); i++)
//            qDebug() << sqlQuery.record().field(i).name();

//        while (sqlQuery.next())
//            qDebug() << sqlQuery.value(1).toString();
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    pathDB = QFileDialog::getOpenFileName(this, "Open file", "", "DataBase(*db)");

    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(pathDB);

    if (dataBase.open())
    {
        sqlQuery = QSqlQuery(dataBase);

        fillingData();
    }
}

void MainWindow::fillingData()
{
    addTables();
    makeRequest();
    addColumns();
    addValues(0);
}

void MainWindow::addTables()
{
    ui->comboBox->clear();

    for (const QString &tableName : dataBase.tables())
        ui->comboBox->addItem(tableName);
}

void MainWindow::makeRequest()
{
    QString tableName = ui->comboBox->currentText();
    sqlQuery.exec("SELECT * FROM " + tableName + "");
}

void MainWindow::addColumns()
{
    ui->comboBox_2->clear();

    int col_counter = sqlQuery.record().count();
    for (int i = 0; i < col_counter; i++)
        ui->comboBox_2->addItem(sqlQuery.record().field(i).name());
}

void MainWindow::addValues(int index)
{
    ui->listWidget->clear();

    while (sqlQuery.next())
        ui->listWidget->addItem(sqlQuery.value(index).toString());
}






