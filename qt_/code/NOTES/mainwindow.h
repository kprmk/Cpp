#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>
#include <QMap>
#include <QMessageBox>

#include "createnote.h"
#include "savedata.h"
#include "loaddata.h"

#define NOTE_ICON ":/images/icon_note.png"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    CreateNote *crNote;
    SaveData *sData;
    LoadData *lData;

    QMap<QString, QString> mapListNotes; //<Имя заметки, текст>

    QString lastNote = "";


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void ProvideContextMenu(const QPoint &pos);

    void on_btnCreateANote_clicked();

    void on_btnSetBold_clicked();

    void on_btnSetItalic_clicked();

    void on_btnUnderLine_clicked();

    void on_btnStrike_clicked();

    void on_listNotes_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
