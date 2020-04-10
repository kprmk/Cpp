#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QObject>

#include <stdlib.h>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
