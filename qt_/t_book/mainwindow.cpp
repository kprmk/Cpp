#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tel_line->setText("+");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_but_clicked()
{
    if(this->file_name == "")
    {
        QMessageBox::warning(this, "Error" , "Please, use 'READ' for creating new file or \n"
                                             "reading existing file, wich contains data.\n"
                                             "Otherwise you can not add new member" );
        return;
    }

    if(ui->tel_line->text() == "" || ui->tel_line->text() == "+")
    {
        QMessageBox::warning(this, "Error" , "You haven't entered any data for adding" );
        return;
    }

    QString new_member = ui->tel_line->text();
    bool flag = true;
    for (auto i = (new_member.begin() + 1); i != new_member.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            flag = false;
    }
    if(!flag)
    {
        QMessageBox::warning(this, "Error" , "You've entered incorrect number" );
        return;
    }

    QFile file(this->file_name);
    if(!file.open(QIODevice::Append))
    {
        QMessageBox::warning(this, "Error" , "File haven't been openned\n" + file.errorString());
        return;
    }

    new_member = ui->name_line->text() + ", " + ui->tel_line->text() + '\n';
    QTextStream out (&file);
    out << new_member;
    ui->name_line->clear();
    ui->tel_line->setText("+");
    file.close();
    this->show_data();

}

void MainWindow::show_data()
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Error" , "There has been an error with openning");
    QTextStream st (&file);
    ui->output->setText(st.readAll());
    file.close();
}

void MainWindow::on_read_but_clicked()
{
    this->file_name = QFileDialog::getOpenFileName(this, "Open the file or create one");
    QFile file(this->file_name);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error" , "There has been an error with openning"\
                             + file.errorString());
        return;
    }
    setWindowTitle(this->file_name);
    QTextStream st(&file);
    ui->output->setText(st.readAll());
    file.close();
}

void MainWindow::on_del_but_clicked()
{
    QFile file(this->file_name);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Error" , "There has been an error with openning"\
                             + file.errorString());
        return;
    }
    ui->output->clear();

    QTextStream out (&file);
    out << "";

    file.close();
}
