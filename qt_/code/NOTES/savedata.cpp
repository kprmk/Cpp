#include "savedata.h"

#define FOLDER "/SNNotes"
#define NOTES_FILE "/notes_data.svk"

SaveData::SaveData()
{
    userName = QDir::homePath();
    QDir().mkdir(userName + FOLDER);
}

void SaveData::Save(QMap<QString, QString> *listNotes)
{
    //Переменная для хранения кол-ва элементов
    int count = listNotes->count();

    //Создаем файл
    QFile fileNotes(userName + FOLDER + NOTES_FILE);

    //Открываем файл
    if (fileNotes.open(QIODevice::WriteOnly)){

        //Открываем файл в бинарном режиме
        QDataStream binFile(&fileNotes);

        //Сначала записываем кол-во элементов
        binFile << count;

        QByteArray keyArr;
        QByteArray lavueArr;

        //Потом записываем все значения, заметок и текста, в бинарный файл
        for (int i = 0; i < count; i++){
            keyArr = listNotes->keys().at(i).toUtf8();
            lavueArr = listNotes->values().at(i).toUtf8();
            binFile << qCompress(keyArr) << qCompress(lavueArr);
        }
    }

    fileNotes.close();

}
