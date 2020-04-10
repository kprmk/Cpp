#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 300, 300);

    // add the item to the scene
    scene->addItem(rect);

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);


    view->show();

    return a.exec();
}
