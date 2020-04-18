#ifndef RECT_M_H
#define RECT_M_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <iostream>

class rect_m: public QGraphicsRectItem
{
public:
    rect_m();
    void keyPressEvent(QKeyEvent * event);
};

#endif // RECT_M_H
