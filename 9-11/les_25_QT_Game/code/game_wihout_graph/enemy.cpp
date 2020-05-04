#include "enemy.h"
#include "game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(),
    QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/pics/enemy.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y() + 5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}


