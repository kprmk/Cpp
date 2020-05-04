#ifndef SCORE_H
#define SCORE_H

#include "headings_libs.h"

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
};

#endif // SCORE_H


