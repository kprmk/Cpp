#include "rect_m.h"

rect_m::rect_m(): QObject(), QGraphicsRectItem()
{
    qDebug() << "I've been created!";
}

void rect_m::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() < scene()->width() - rect().height())
            setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet * bl = new Bullet();
        qDebug() << "Bullet has been created";
        bl->setPos(x(), y());
        scene()->addItem(bl);
    }
}

void rect_m::spawn()
{
    // create enemy
    Enemy * nmy = new Enemy();
    scene()->addItem(nmy);
}
