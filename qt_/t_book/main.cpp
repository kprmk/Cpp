#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QMessageBox::information(&w, "Open ***.txt",
//                             "For saving data");
//    QString file_name = QFileDialog::getSaveFileName(&w, "Save as");
//    QFile file(file_name);
//    if (!file.open(QFile::WriteOnly | QFile::Text))
//    {
//        QMessageBox::warning(&w, "Error",
//                             "File hasn't been opened: " + file.errorString());
//    }

    return a.exec();
}
