#include <QApplication>
#include <QtWidgets>

using namespace std;

mt19937 generator (123);
uniform_real_distribution<double> distribReal(0.0, 1.0);
uniform_int_distribution<int> distribInt(0, RAND_MAX);
//double randomRealBetweenZeroAndOne = distrib(generator);

int main(int argc, char *argv[])
{
    if(argc < 2){
        cout << "You must give as 1st parameter the number of civilisations." << endl;
        return 0;
    }

    int nbCivs = boost::lexical_cast<int>(argv[1]);

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
