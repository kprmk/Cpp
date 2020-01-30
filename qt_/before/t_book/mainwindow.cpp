#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_number->setText("+");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{

    if(this->current_file == "")
    {
        QMessageBox::warning(this, "Error" , "Please, use 'READ' for creat new file or \n"
                                             "reading existing file, wich contains data.\n"
                                             "Otherwise you can not add new number" );
        return;
    }

    if(ui->line_name->text() == "" || ui->line_name->text() == "")
    {
        QMessageBox::warning(this, "Error" , "You don not enter any data for adding" );
        return;
    }

    QString new_added = ui->line_number->text();
    bool flag = false;
    for(int i = 1; i != new_added.size(); i++)
    {
        if(*(new_added.begin() + i) < '0' || *(new_added.begin() + i) > '9')
            flag = true;
    }
    if(flag)
    {
        QMessageBox::warning(this, "Error" , "You enter incorrect number" );
        return;
    }


     QFile file(current_file);
        if(!file.open(QIODevice::Append))
        {
            QMessageBox::warning(this, "Error" , "File does not save : " + file.errorString());
            return;
        }
    new_added = ui->line_name->text() + ' ' + ui->line_number->text() + '\n';
    QTextStream out (&file);
    out << new_added;
    ui->line_name->clear();
    ui->line_number->clear();
     ui->line_number->setText("+");
    file.close();
    this->show_data_from_file();

//    QString text_out = ui->text_area_for_nums->toPlainText();
//    out << text_out;
}

void MainWindow::on_Read_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file (fileName);
    current_file = fileName;
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error" , "File does not open : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
//    file.read();
    QTextStream in (&file);
    QString cur = in.readAll();
    ui->text_area_for_nums->setText(cur);
//    ui->textEdit->setText(cur);
    file.close();
}

void MainWindow::on_Delete_clicked()
{

        QFile file (current_file);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Error" , "File does not save : " + file.errorString());
        return;
    }

    ui->text_area_for_nums->clear();

    QTextStream out (&file);
    out << "";

//   QString new_added = ui->line_name->text() + ' ' + ui->line_number->text();
////    QMessageBox::about(this, "qwe", new_added);
//   QTextStream out (&file);
//   out << new_added;


    file.close();
}

void MainWindow::show_data_from_file()
{
    QFile file (current_file);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Error" , "File does not ");
    QTextStream st (&file);
    ui->text_area_for_nums->setText(st.readAll());
}
