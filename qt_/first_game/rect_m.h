#ifndef RECT_M_H
#define RECT_M_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>

#include "bullet.h"
#include "enemy.h"

class rect_m: public QObject, public QGraphicsRectItem
{
        Q_OBJECT
public:
    rect_m();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // RECT_M_H
