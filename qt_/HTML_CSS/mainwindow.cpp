#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->statusbar->showMessage("YES");
    }
    else{
        ui->statusbar->showMessage("NO");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked())
    {
        ui->statusbar->showMessage("YES");
    }
    else{
        ui->statusbar->showMessage("NO");
    }
}
