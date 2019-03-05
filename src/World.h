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

static mt19937::result_type seed = time(0);
static auto distribReal = std::bind(uniform_real_distribution<double> (0.0, 1.0), mt19937(seed));
static auto distribInt = std::bind(uniform_int_distribution<int> (0, 100000), mt19937(seed));
//double randomRealBetweenZeroAndOne = distrib(generator);

class World : public Entity
{
protected:
    int nbCivs;
    QVector<Ressource*> ressources;
    QVector<Headquarter*> factions;

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

	void simulateOneTurn(unsigned date);

	// Manhattan distance
	int distanceBetween(const Entity& a, const Entity& b);

	bool isNextToResource(const Entity& e);

	std::vector<Agent*> getAgentOf(Headquarter* hq);
	int distanceMin(Entity* e, std::vector<Agent*>& vect);
	std::vector<Agent*> getEnemiesVisibleBy(Headquarter* hq);
	std::vector<Headquarter*> getHeadquartersVisibleBy(Headquarter* hq);
	std::vector<Resource*> getResourcesVisibleBy(Headquarter* hq);
	std::vector<Agent*> getAgentsTargetableBy(const Soldier& soldier);

};

#endif // WORLD_H
