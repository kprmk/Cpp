#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ipt_nums->setText("+");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(name);
    this->file_name = name;
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error",\
                             "Description: " + file.errorString());
        return ;
    }
    setWindowTitle(this->file_name);
    QTextStream in(&file);
    QString cur = in.readAll();
    ui->output_area->setText(cur);
    file.close();
}

void MainWindow::on_add_clicked()
{
    if (this->file_name == "")
    {
        QMessageBox::critical(this, "Error", "asdfasdf");
        return;
    }
    if(ui->ipt_name->text() == " " || ui->ipt_nums->text() == "")
    {
        QMessageBox::warning(this, "ERROR", "____");
        return;
    }
    QFile file(this->file_name);
    if (!file.open(QIODevice::Append))
    {
        QMessageBox::warning(this, "ERROR", "---");
        return;
    }
    QString new_line = ui->ipt_name->text() + '\t' + ui->ipt_nums->text() + '\n';
    QTextStream out(&file);
    out << new_line;
    ui->ipt_name->clear();
    ui->ipt_nums->setText("+");
    file.close();
    this->show_data();
}

void MainWindow::show_data()
{
    QFile file(this->file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::question(this, "Error", "Descr");
    else
    {
        QTextStream out(&file);
        ui->output_area->setText(out.readAll());
    }
}

void MainWindow::on_del_clicked()
{
    QFile file(this->file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::warning(this, "Test", "Set");
    }
    QTextStream st(&file);
    ui->output_area->clear();
    st << "";
    file.close();
}
