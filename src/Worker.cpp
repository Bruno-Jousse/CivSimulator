#include "Worker.h"
#include "World.h"

const int Worker::STOCK_MAX = 5;
const int Worker::STARTING_HP = 5;
const int Worker::AVG_LIVING = 100;
const int Worker::STDDEV_LIVING = 10;


Worker::Worker(World* w, Headquarter * creator, QColor color, int x, int y) : Machine(w, creator, color, x, y, STARTING_HP), metalStockBar(Qt::gray, 0, getH()-10, getW(), 10, STOCK_MAX), willHarvest(false) {
    deathDate = TimeManager::getInstance().getMonth() + static_cast<int>(round(RandomManager::getInstance().getGaussian(Worker::AVG_LIVING, Worker::STDDEV_LIVING) ));
    metalStockBar.setParentItem(this);
}

void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter,"W");
}

void Worker::action(){
    if (isDead()) // simulate only for living agents
        return;

    // the AI of the worker
    willHarvest = false;
    Grid decisionGrid(world->getW(), world->getH());
    if (getMetalAmount() >= STOCK_MAX)
    {
        decisionGrid = hq->getGridAllyHeadquarter() - hq->getGridEnemies();
    }
    else if (deathDate - TimeManager::getInstance().getFrame() == world->distanceBetween(*this, *hq) && getMetalAmount() != 0)
    {
        decisionGrid = hq->getGridAllyHeadquarter();
    }
    else if (world->isNextToResource(*this))
    {
        willHarvest = true;
    }
    else
    {
        double ratio = 1.0*getMetalAmount() / STOCK_MAX;
        decisionGrid = ratio*hq->getGridAllyHeadquarter() + (1 - ratio)*hq->getGridResources()
            - hq->getGridEnemies();
    }

    if (!willHarvest)
        chooseBestNeighbor(decisionGrid, getX(), getY(), nextX, nextY);
}
