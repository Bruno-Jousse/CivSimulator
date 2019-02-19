#ifndef Headquarter_HPP
#define Headquarter_HPP

#include "Entity.h"
#include "Grid.h"

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

    void spawnMachine();
    void action() override; // TODO : update all grids before or at the beginning
protected:
    int hp;
    // the grids
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
