#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ceasar.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/pic/pic/pic.png");
    ui->pix->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string input = ui->LineInputString->text().toStdString();
    int shift = ui->spinBox->value();

    ceasar result = ceasar(input, shift);
    result.code();
    ui->res->setText(QString::fromStdString(result.getter()));
}
