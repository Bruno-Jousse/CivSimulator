#ifndef Headquarter_HPP
#define Headquarter_HPP

#include "Agent.h"
#include "Grid.h"
#include "Healthbar.h"

namespace model{

class Headquarter final: public Entity
{
public:
    Headquarter() = delete;
    Headquarter(Headquarter const&) = delete;
    
    Headquarter(int x, int y);
    virtual ~Headquarter();

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
    static const int MAX_STOCK_METAL;

    void spawnMachine();

    void action(int phase);
    int getHp(){ return healthbar.getHp(); }
    int getMetalAmount(){ return metalStockBar.getHp(); }
    void setHealthbar(Healthbar h){ healthbar = b;}
    void setMetalStockBar(Healthbar h){ metalStockBar = h; }

protected:
    int hp;
    // the grids
    Healthbar* metalStockBar;
    Healthbar* healthbar;
    Grid gridAllyHeadquarter;
    Grid gridAllyAgents;
    Grid gridEnemies;
    Grid gridResources;
    // the state TODO

private:
    void createAWorker();
    void createASoldier();
};

}
#endif // Headquarter_HPP
