#include <QApplication>
#include <QtWidgets>
#include <string>
#include <iostream>
#include "Model/World.h"
using namespace std;

int main(int argc, char *argv[])
{
    int nbCivs = 2;
    int length = 1000;
    int width = 1000;
    if(argc >= 4){
        nbCivs = stoi(argv[1]);
        length = stoi(argv[2]);
        width = stoi(argv[3]);
    }
    else{
        cout << "You can give following parameters: number of civilisations | length of the world | width of the world." << endl;
    }

    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, width, length);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    cout << "Application creation." <<endl;

    World world(nbCivs, length, width);
    world.setPos(0,0);
    scene.addItem(&world);
    world.init();

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/grass_texture.jpg"));
    view.setCacheMode(QGraphicsView::CacheBackground    );
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Civilisation Simulator"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

    return a.exec();
}
