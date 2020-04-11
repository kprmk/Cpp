#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QKeyEvent>
#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QList>
#include <iostream>
#include <stdlib.h>

#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "score.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    Player *player = Player();
    Score * score;
};

#endif // GAME_H
