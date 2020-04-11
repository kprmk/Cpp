#include "bullet.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // draw
    setRect(0, 0, 10, 50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with enemym destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;

        }
    }

    // move bullet
    setPos(x(), y() - 10);

    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet was deleted";
    }
}
