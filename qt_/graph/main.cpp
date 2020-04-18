//#include <QApplication>
//#include <QGraphicsScene>
//#include <QGraphicsRectItem>
//#include <QGraphicsView>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QGraphicsScene * scene = new QGraphicsScene();

//    QGraphicsRectItem * rect = new QGraphicsRectItem();
//    rect->setRect(0, 0, 400, 700);

//    scene->addItem(rect);

//    QGraphicsView *view = new QGraphicsView(scene);

//    view->show();


//    return a.exec();
//}




#include <QGraphicsScene>
#include <QGraphicsView>
#include "rect_m.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    rect_m * rect= new rect_m();
    rect->setRect(0, 0, 300, 300);


    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    std::cout << "test cout!" << std::endl;

    view->show();

    return a.exec();
}
