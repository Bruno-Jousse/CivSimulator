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
using namespace std;

static mt19937::result_type seed = time(0);
static auto distribReal = std::bind(uniform_real_distribution<double> (0.0, 1.0), mt19937(seed));
static auto distribInt = std::bind(uniform_int_distribution<int> (0, 100000), mt19937(seed));
//double randomRealBetweenZeroAndOne = distrib(generator);

class World : public QGraphicsItem
{
protected:
    int nbCivs;
    int width;
    int length;
    QVector<Ressource*> ressources;
    QVector<Headquarter*> factions;

public:
    World(int nbCivs=0, int width=20, int length=20);
    void advance(int phase) override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;

    bool isOccupiedByHQ(QRect obj);
    bool collider(QRect r1, QRect r2);
    bool isOccupied(QRect obj);
    void init();

};

#endif // WORLD_H
