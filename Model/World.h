#ifndef WORLD_H
#define WORLD_H

#include <random>
#include "Metal.h"
#include "Headquarter.h"
#include "QGraphicsScene"
#include "QGraphicsItem"
#include <cmath>
#include <iostream>
#include "Figure.h"
using namespace std;

static mt19937 generator (123);
static uniform_real_distribution<double> distribReal(0.0, 1.0);
static uniform_int_distribution<int> distribInt(0, RAND_MAX);
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
