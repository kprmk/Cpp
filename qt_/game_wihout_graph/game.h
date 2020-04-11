#ifndef GAME_H
#define GAME_H

#include "headings_libs.h"
#include "player.h"
#include "score.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
};

#endif // GAME_H
