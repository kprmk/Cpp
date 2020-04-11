#include "player.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    qDebug() << "I've been created!";
}

void Player::keyPressEvent(QKeyEvent *event)
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

void Player::spawn()
{
    // create enemy
    Enemy * nmy = new Enemy();
    scene()->addItem(nmy);
}
