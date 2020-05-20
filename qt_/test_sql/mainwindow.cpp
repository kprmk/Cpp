#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->DB = QSqlDatabase::addDatabase("QSQLITE");
    this->DB.setDatabaseName("C:/Users/mi/Desktop/auto.db");

    if (this->DB.open())
    {
        this->query = QSqlQuery(this->DB);

        this->query.exec("CREATE TABLE IF NOT EXISTS cars (name TEXT, price REAL)");
        this->query.exec("CREATE TABLE IF NOT EXISTS toys (name TEXT, price REAL, color TEXT)");

        this->query.exec("INSERT INTO cars VALUES ('BMV', 1000)");
        this->query.exec("INSERT INTO cars VALUES ('AUDIO', 1000)");
        this->query.exec("INSERT INTO cars VALUES ('MERS', 2000)");

        this->query.exec("INSERT INTO toys VALUES ('Princ', 10, 'purple')");

        qDebug() << this->query.exec("SELECT * FROM cars");

        for (const QString & tableName : this->DB.tables())
            qDebug() << tableName;

        for (int i = 0; i < query.record().count(); i++)
            qDebug() << query.record().field(i).name();

        while (query.next())
            qDebug() << query.value(0).toString();

//        this->query.exec("DROP TABLE cars");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_clicked()
{
    this->pathDB = QFileDialog::getOpenFileName(this, "Open file", "", "DataBase (*db)");

    qDebug() << this->pathDB << '\n';

    this->DB = QSqlDatabase::addDatabase("QSQLITE");
    this->DB.setDatabaseName(pathDB);

    if (this->DB.open())
    {
        this->query = QSqlQuery(this->DB);
        this->showData();
    }
}

void MainWindow::showData()
{
    this->addTables();
    this->makeRequest();
    this->addColumns();
    this->addValues(0);
}

void MainWindow::addTables()
{
    ui->tables->clear();

    for (const QString &table_name: DB.tables())
        ui->tables->addItem(table_name);
}

void MainWindow::makeRequest()
{
    QString table_name = ui->tables->currentText();
    this->query.exec("SELECT * FROM " + table_name + "");
}

void MainWindow::addColumns()
{
    ui->columns->clear();

    int quantity = this->query.record().count();
    for (int i = 0; i < quantity; ++i)
        ui->columns->addItem(this->query.record().field(i).name());
}


void MainWindow::addValues(int index)
{
    ui->output->clear();

    while(this->query.next())
        ui->output->addItem(this->query.value(index).toString());
}


void MainWindow::on_tables_activated(int index)
{
    this->makeRequest();
    this->addColumns();
    this->addValues(0);
}

void MainWindow::on_columns_activated(int index)
{
    this->makeRequest();
    this->addColumns();
    this->addValues(index);
}
