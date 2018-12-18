#include <QApplication>
#include <QtWidgets>
#include <string>
#include <iostream>
#include "Model/World.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 2){
        cout << "You must give as 1st parameter the number of civilisations." << endl;
        return 0;
    }

    int nbCivs = stoi(argv[1]);

    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 1000, 1000);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    World world();
    world.simulate();

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/grass_texture.jpg"));
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Civilisation Simulator"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

     //Créer et ajouter les objets à la scène

    return a.exec();
}
