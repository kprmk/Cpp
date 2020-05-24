#include "mainwindow.h"
#include "ui_mainwindow.h"

#define NOTE_HEIGHT 40


//Контекстное меню, если пользователь нажал на элемент правой кнопкой мыши
void MainWindow::ProvideContextMenu(const QPoint &pos)
{
    QPoint item = ui->listNotes->mapToGlobal(pos);

    QMenu menu;
    menu.addAction("Удалить");

    if (ui->listNotes->count() != 0){

        QAction *rightClick = menu.exec(item);
        if (rightClick && rightClick->text().contains("Удалить")){
            QMessageBox::StandardButton msg = QMessageBox::question(this, "Удалить",
                                                                    "Вы уверены что хотите удалить '" + ui->listNotes->currentItem()->text() + "'?",
                                                                    QMessageBox::Yes | QMessageBox::No);

            if (msg == QMessageBox::Yes){
                mapListNotes.remove(ui->listNotes->currentItem()->text());
                delete ui->listNotes->currentItem();

                if (ui->listNotes->count() == 0){
                    ui->mainText->setText("");
                    mapListNotes.clear();

                    sData->Save(&mapListNotes);
                }
            }

        }


    }

}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Строчки для контекстного меню, если пользователь нажал ПКМ на элемент
    ui->listNotes->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listNotes, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ProvideContextMenu(QPoint)));

    sData = new SaveData();
    lData = new LoadData();

    //Загружаем заметки из файла
    if (lData->Load()){
        mapListNotes = lData->getListNotes();
        int count = mapListNotes.count();

        QString noteName = "";
        int badNote = 0; //badNote - нужен т.к. есть баг, который создает пустую заметку без текста.
                         //Мы же будем вычислять пустые заметки (созданные ошибочно), и удалять
        for (int i = 0; i < count; i++){
            noteName = mapListNotes.keys().at(i);
            if (!noteName.isEmpty()) //Проверяем имя заметки на пустоту. Если все ОК, то добавляем
            {
                ui->listNotes->addItem(noteName);
            }
            else //Иначе записываем в badNote, то что мусорных заметок N
                badNote++;
        }

        //Устанавливаем высоту заметок
        for (int i = 0; i < count - badNote; i++){
            ui->listNotes->item(i)->setSizeHint(QSize(0, NOTE_HEIGHT));

            ui->listNotes->item(i)->setIcon(QIcon(NOTE_ICON));
        }
        //Выделяем заметку
        ui->listNotes->setCurrentRow(0);

        //И автоматом заполняем заметку текстом
        ui->mainText->setText(mapListNotes.value(ui->listNotes->currentItem()->text()));

    }

}



MainWindow::~MainWindow()
{
    //Перед выходом сохранимся
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(ui->listNotes->currentItem()->text(), ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    delete ui;
}



void MainWindow::on_btnCreateANote_clicked()
{
    //Перед созданием новой заметки, сохраняем текущую заметку
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(ui->listNotes->currentItem()->text(), ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    //Вызываем диалоговое окно и получаем имя нашей новой заметки
    crNote = new CreateNote();
    crNote->exec();

    QString noteName = crNote->getName();
    if (noteName.isEmpty())
        return;

    ui->listNotes->addItem(noteName); //Добавляем в QListWidget


    int lastAddedItem = ui->listNotes->count() - 1; //Это будет index последнего добавленного элемента
    ui->listNotes->item(lastAddedItem)->setSizeHint(QSize(0, NOTE_HEIGHT)); //Меняем размер элемента
    ui->listNotes->setCurrentRow(lastAddedItem); //Выделяем элемент
    ui->listNotes->item(lastAddedItem)->setIcon(QIcon(NOTE_ICON));
    ui->mainText->setFocus();

    mapListNotes.insert(noteName, ""); //Добавляем имя заметки в QMap
    ui->mainText->setText("");

    lastNote = noteName;

    delete crNote;
}

void MainWindow::on_btnSetBold_clicked()
{
    //Определяем размер шрифта
    QTextCharFormat cur = ui->mainText->currentCharFormat();
    QString text = ui->mainText->textCursor().selectedText();

    //Проверка на выделенный текст
    //50 - не выделенный текст
    if (cur.fontWeight() == 50)
        ui->mainText->insertHtml("<b>" + text + "</b>");
    else
        ui->mainText->insertHtml(text);
}

void MainWindow::on_btnSetItalic_clicked()
{
    QTextCharFormat cur = ui->mainText->currentCharFormat();
    QString text = ui->mainText->textCursor().selectedText();

    //Определяем, курсивом написан текст или нет
    if (!cur.fontItalic())
        ui->mainText->insertHtml("<i>" + text + "</i>"); //<i></i> - теги из HTML
    else
        ui->mainText->insertHtml(text);
}

void MainWindow::on_btnUnderLine_clicked()
{
    QTextCharFormat cur = ui->mainText->currentCharFormat();
    QString text = ui->mainText->textCursor().selectedText();

    //Определяем, подчеркнут текст или нет
    if (!cur.fontUnderline())
        ui->mainText->insertHtml("<u>" + text + "</u>"); //<u></u> - теги из HTML
    else
        ui->mainText->insertHtml(text);
}

void MainWindow::on_btnStrike_clicked()
{
    QTextCharFormat cur = ui->mainText->currentCharFormat();
    QString text = ui->mainText->textCursor().selectedText();

    //Определяем, зачеркнутый текст или нет
    if (!cur.fontStrikeOut())
        ui->mainText->insertHtml("<s>" + text + "</s>"); //<s></s> - теги из HTML
    else
        ui->mainText->insertHtml(text);
}

void MainWindow::on_listNotes_itemClicked(QListWidgetItem *item)
{
    //Перед переключением на другую заметку, сохраним текущую
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(lastNote, ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    ui->mainText->setFocus();
    ui->mainText->setText(mapListNotes.value(item->text())); //Если это старая заметка, то загружаем текст из QMap

    lastNote = item->text();
}
