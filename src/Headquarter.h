/**
 * Project Untitled
 */


#ifndef _HEADQUARTER_H
#define _HEADQUARTER_H

#include "Building.h"
#include "Soldier.h"
#include "Worker.h"
#include "Grid.h"
#include <vector>

class Headquarter: public Building {
private: 

    int metalAmount;
    int aggressivity;
    QVector<Soldier*> soldiers;
    QVector<Worker*> workers;
    //1st int is number of month to wait, 2nd int represent: 0=worker, 1=soldier
    QVector< pair<int, int> > productionLine;
    
    void createAWorker();
    void createASoldier();

	Grid gridAllyHeadquarter;
	Grid gridAllyAgents;
	Grid gridEnemies;
	Grid gridResources;

public:
    Headquarter(QColor color, int x, int y, int w, int h, int metalAmount=100, int aggressivity=1, int hp=100);
    Headquarter(int metalAmount=100, int aggressivity=1, int hp=100);
    void suppression() override{
        Entity::suppression();
        for(int i=0; i<soldiers.size(); i++){
            soldiers.at(i)->suppression();
        }
        for(int i=0; i<workers.size(); i++){
            workers.at(i)->suppression();
        }
    }
    int getMetalAmount() const;
    void setMetalAmount(int value);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QVector<Soldier*> getSoldiers() const;
    QVector<Worker*> getWorkers() const;
    QVector< pair<int, int> > getProductionLine() const;

    void spawnMachine();
    void action() override;

	// create agent and choose a strategy
	void simulate(unsigned date, World& world) override;

	void updateGrids(World& world);
	// inline grid getters
	const Grid& getGridAllyHeadquarter() const { return gridAllyHeadquarter; }
	const Grid& getGridAllyAgents() const { return gridAllyAgents; }
	const Grid& getGridEnemies() const { return gridEnemies; }
	const Grid& getGridResources() const { return gridResources; }

	// global constant
	static const int STARTING_HP;

};

#endif //_HEADQUARTER_H
