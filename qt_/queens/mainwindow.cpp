#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVBoxLayout"
#include "QLabel"
#include "QGridLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *lt = new QGridLayout(this);
    lt->
    QLabel *lbl1 = new QLabel("*****", this);
    QLabel *lbl2 = new QLabel("*****", this);
//    lbl->move(100, 100);
    lt->addWidget(lbl1);
    lt->addWidget(lbl2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

