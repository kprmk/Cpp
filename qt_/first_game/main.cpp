#include <QApplication>
#include "rect_m.h"

#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    rect_m * player = new rect_m();
    player->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view-> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view-> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    // view's origin and scene's origin are the same
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2, view->height() - player->rect().height());

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(1000);

    return a.exec();
}
