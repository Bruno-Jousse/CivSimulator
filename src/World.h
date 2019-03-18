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
    QVector<Resource*> ressources;
    QVector<Headquarter*> factions;
    std::vector<Machine*> agents;
    std::vector<Headquarter*> headquarters;

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
	int distanceBetween(const Entity& a, const Entity& b);

	bool isNextToResource(const Entity& e);

	std::vector<Agent*> getAgentOf(Headquarter* hq);
	int distanceMin(Entity* e, std::vector<Agent*>& vect);
	std::vector<Agent*> getEnemiesVisibleBy(Headquarter* hq);
	std::vector<Headquarter*> getHeadquartersVisibleBy(Headquarter* hq);
	std::vector<Resource*> getResourcesVisibleBy(Headquarter* hq);
	std::vector<Agent*> getAgentsTargetableBy(const Soldier& soldier);

    // global constants
       static const int NB_ROW;
       static const int NB_COL;
       static const int VISIBILITY_RANGE;

       int getWidth(){ return NB_COL*30; }
       int getHeight(){ return NB_ROW*30;}


};

#endif // WORLD_H
