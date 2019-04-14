#ifndef _HQ_H
#define _HQ_H

//#include "World.h"
#include "Grid.h"
#include "Building.h"
#include "Soldier.h"
#include "Worker.h"
#include <vector>
#include "RandomManager.h"
#include "TimeManager.h"

//class World;

class Headquarter : public Building{
private: 

    QVector<Soldier*> soldiers;
    QVector<Worker*> workers;
    //1st int is number of month to wait, 2nd int represent: 0=worker, 1=soldier
    QVector< pair<int, int> > productionLine;
    Healthbar metalStockBar;

    void createAWorker();
    void createASoldier();

	Grid gridAllyHeadquarter;
	Grid gridAllyAgents;
	Grid gridEnemies;
	Grid gridResources;

public:
	class IHQStrategy{
    protected:
        uint i;
        Headquarter* hq;
    public:
        virtual void createUnit(int metalAmount) = 0;
        IHQStrategy(Headquarter* hq) : i(0), hq(hq) {}
        virtual ~IHQStrategy();
	};
	class HQAggroStrategy : public IHQStrategy{
    public:
        ~HQAggroStrategy() override;
        HQAggroStrategy(Headquarter* hq) : IHQStrategy(hq) {}
        void createUnit(int metalAmount) override{
            while (metalAmount >= 25) {
                if(i%3==0){
                    hq->createAWorker();
				}
				else{
                    hq->createASoldier();
				}
                i+=1;
			}
		}
	};
	
	class HQDevelopmentStrategy : public IHQStrategy{
    public:
        ~HQDevelopmentStrategy() override;
        HQDevelopmentStrategy(Headquarter* hq) : IHQStrategy(hq) {}
        void createUnit(int metalAmount) override{
            while (metalAmount >= 25) {
                if(i%3==0){
                    hq->createASoldier();
				}
				else{
                    hq->createAWorker();
				}
                i+=1;
			}
		}
	};
	
	class HQNeutralStrategy : public IHQStrategy{
    public:
        ~HQNeutralStrategy() override;
        HQNeutralStrategy(Headquarter* hq) : IHQStrategy(hq) {}
        void createUnit(int metalAmount) override{
            while (metalAmount >= 25) {
                if(i%2==0){
                    hq->createAWorker();
				}
				else{
                    hq->createASoldier();
				}
                i+=1;
			}
		}
	};
	
    Headquarter(World* w, QColor color, int x=0, int y=0);
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

    void updateGrids();
	// inline grid getters
	const Grid& getGridAllyHeadquarter() const { return gridAllyHeadquarter; }
	const Grid& getGridAllyAgents() const { return gridAllyAgents; }
    Grid& getGridEnemies() { return gridEnemies; }
	const Grid& getGridResources() const { return gridResources; }

	// global constant
	static const int STARTING_HP;
    static const int METAL_STOCK_MAX;

private:
    IHQStrategy* strategy;
	void initStrategy(){
        int r = RandomManager::getInstance().getRandomInt(3);
		if(r == 0){
            strategy = new HQAggroStrategy(this);
		}
		else if (r == 1){
            strategy = new HQDevelopmentStrategy(this);
		}
		else{
            strategy = new HQNeutralStrategy(this);
		}
	}
};

#endif
