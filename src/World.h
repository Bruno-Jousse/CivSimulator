#ifndef WORLD_H
#define WORLD_H

#include <random>
#include "Metal.h"
#include "Headquarter.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include <cmath>
#include <iostream>
#include "Entity.h"
#include <time.h>
#include <algorithm>

using namespace std;

class World : public Entity
{
protected:
    int nbCivs;
    QVector<Resource*> resources;
    QVector<Headquarter*> factions;
    QVector<Machine*> agents;

public:
    World(int nbCivs, int w, int h);
    void advance(int phase) override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;

    bool isOccupiedByHQ(QRect obj);
    bool collider(QRect r1, QRect r2);
    bool isOccupied(QRect obj);
    void init();

	// Manhattan distance
    int distanceBetween(Entity& a, Entity& b);

    bool isNextToResource(Entity& e);

    QVector<Machine*> getAgentOf(Headquarter* hq);
    int distanceMin(Entity* e, QVector<Machine*>& vect);
    QVector<Machine*> getEnemiesVisibleBy(Headquarter* hq);
    QVector<Headquarter*> getHeadquartersVisibleBy(Headquarter* hq);
    QVector<Resource*> getResourcesVisibleBy(Headquarter* hq);
    QVector<Machine*> getAgentsTargetableBy(Soldier& soldier);
    QVector<Machine*> getEntitiesOf(Headquarter* hq);

    // global constants
       static const int NB_ROW;
       static const int NB_COL;
       static const int VISIBILITY_RANGE;

       int getWView(){ return NB_COL*30; }
       int getHView(){ return NB_ROW*30;}
};

#endif // WORLD_H
