#include "loaddata.h"

#define FOLDER "/SNNotes"
#define NOTES_FILE "/notes_data.svk"

QMap<QString, QString> LoadData::getListNotes() const
{
    return listNotes;
}

LoadData::LoadData()
{
    //Узнаем имя пользователя
    userName = QDir::homePath();

}

bool LoadData::Load()
{

    //Ищем файл с сохраненными заметками
    QFile fileNotes(userName + FOLDER + NOTES_FILE);

    //Проверяем, существует файл или нет
    if (!fileNotes.open(QIODevice::ReadOnly)){
        qDebug() << "File '" << fileNotes.fileName() << "' is not found!";
        fileNotes.close();
        return false;
    }

    //Если файл существует, то открываем его в бинарном режиме
    QDataStream binFile(&fileNotes);

    //Переменная для хранения кол-ва заметок
    int count = 0;

    //Считываем кол-во заметок из файла.
    binFile >> count;

    //Если, все таки, файл существует, то это не повод сразу загружать из него заметки.
    //Для начала нужно проверить, сколько заметок в файле. Если 0 то возвращем false
    if (count == 0){
        fileNotes.close();
        return false;
    }

    QString tNote = ""; //Временная переменная для хранения имени заметки
    QString tText = ""; //Временная переменная для хранения текста из заметки

    QByteArray arrNote;
    QByteArray arrText;

    //Идем по циклу и считываем из файла заметки и текст, а после записываем во временный контейнер
    for (int i = 0; i < count; i++){
        binFile >> arrNote;
        binFile >> arrText;

        tNote = qUncompress(arrNote);
        tText = qUncompress(arrText);

        listNotes.insert(tNote, tText);
    }

    fileNotes.close();
    return true;

}
