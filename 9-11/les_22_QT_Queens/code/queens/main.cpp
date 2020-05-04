#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>
#include "queen.h"

#define N 8
#define W 700
#define H 700

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    srand(time(0));

    queen test(N);
    test.solve();
    auto x = test.getter_ans()[rand() % test.getter_counter()];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            QLabel * lbl = new QLabel();
            if (x[i] == j)
            {
                QPixmap pix(":/img/q.png");
                pix = pix.scaled(W / N, H / N);
                lbl->setStyleSheet("background-color: #00FFFF; ");
                lbl->setPixmap(pix);
            }
            else
                lbl->setStyleSheet("background-color: #ffff00");
            layout->addWidget(lbl, i, j);
        }
    }

    window->setGeometry(0, 0, W, H);
    window->setLayout(layout);
    window->show();

    return a.exec();
}


