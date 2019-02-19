#ifndef Headquarter_HPP
#define Headquarter_HPP

#include "Entity.h"

namespace model{

class Headquarter final: public Entity
{
public:
    Headquarter() = delete;
    Headquarter(Headquarter const&) = delete;
    
    Headquarter(int x, int y);
    virtual ~Headquarter();

    // global constant
    static const int STARTING_HP;

    void spawnMachine();
    void action(int phase) override;
protected:
    int hp;

    int metalAmount;
    int aggressivity;
    // the grids TODO
    // the state TODO

private:
    void createAWorker();
    void createASoldier();
};

}
#endif // Headquarter_HPP
