#ifndef WORLD_H
#define WORLD_H

#include "Metal.h"
#include "Headquarter.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include <iostream>
#include "Entity.h"
#include "../model/RandomManager.h"
#include "../model/World.h"
using namespace std;

namespace view{


class World : public Entity
{
private:
    //model::World isn't derived from entity
    model::World* data;
protected:

    QVector<Resource*> ressources;
    QVector<Headquarter*> factions;

public:
    World(int nbCivs, int w, int h);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;

    bool isOccupiedByHQ(QRect obj);
    bool collider(QRect r1, QRect r2);
    bool isOccupied(QRect obj);
    model::World* getData();
};
}
#endif // WORLD_H
