#ifndef LOADDATA_H
#define LOADDATA_H

#include <QFile>
#include <QMap>
#include <QDataStream>
#include <QDir>
#include <QDebug>

class LoadData
{
    QString userName;
    QMap<QString, QString> listNotes;

public:
    LoadData();

    bool Load();
    QMap<QString, QString> getListNotes() const;
};

#endif // LOADDATA_H

