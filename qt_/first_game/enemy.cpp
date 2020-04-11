#include "enemy.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    int random_pos = rand() % 800; // ?
    setPos(random_pos, 10);

    // draw
    setRect(0, 0, 100, 100);


    // connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move bullet
    setPos(x(), y() + 5);

    if (pos().y() + rect().height() < 0)
    {
//        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
