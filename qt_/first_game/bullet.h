#ifndef BULLET_H
#define BULLET_H

#include "game.h"

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent = 0);
public slots:
    void move();
};

#endif // BULLET_H
