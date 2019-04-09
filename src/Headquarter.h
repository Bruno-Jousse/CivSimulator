#ifndef _HQ_H
#define _HQ_H

#include "World.h"
#include "Grid.h"
#include "Building.h"
#include "Soldier.h"
#include "Worker.h"
#include <vector>
#include "RandomManager.h"
#include "TimeManager.h"

class Headquarter: public Building {
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
		private float i;
		public virtual createUnit() = 0;
		public IHQStrategy(){ i=0.0;}
	};
	class HQAggroStrategy : public IHQStrategy{
		public HQAggroStrategy() : IHQStrategy() {}
		public final createUnit(){
			while (metalStockBar.getMetalAmount() >= 25) {
				if(i%0.3==0){
					createAWorker();
				}
				else{
					createASoldier();
				}
				i+=0.01;
			}
		}
	};
	
	class HQDevelopmentStrategy : public IHQStrategy{
		public HQDevelopmentStrategy() : IHQStrategy() {}
		public final createUnit(){
			while (metalStockBar.getMetalAmount() >= 25) {
				if(i%0.3==0){
					createASoldier();
				}
				else{
					createAWorker();
				}
				i+=0.01;
			}
		}
	};
	
	class HQNeutralStrategy : public IHQStrategy{
		public HQNeutralStrategy() : IHQStrategy() {}
		public final createUnit(){
			while (metalStockBar.getMetalAmount() >= 25) {
				if(i%0.2==0){
					createAWorker();
				}
				else{
					createASoldier();
				}
				i+=0.01;
			}
		}
	};
	
    Headquarter(QColor color, int x=0, int y=0);
    virtual void suppression() override{
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

	void updateGrids(World& world);
	// inline grid getters
	const Grid& getGridAllyHeadquarter() const { return gridAllyHeadquarter; }
	const Grid& getGridAllyAgents() const { return gridAllyAgents; }
	const Grid& getGridEnemies() const { return gridEnemies; }
	const Grid& getGridResources() const { return gridResources; }

	// global constant
	static const int STARTING_HP;
    static const int METAL_STOCK_MAX;
private:
	IHQStrategy strategy;
	void initStrategy(){
		int r = RandomManager.getInstance().getRandomInt(3);
		if(r == 0){
			strategy = HQAggroStrategy();
		}
		else if (r == 1){
			strategy = HQDevelopmentStrategy();
		}
		else{
			strategy = HQNeutralStrategy();
		}
	}
};

#endif
