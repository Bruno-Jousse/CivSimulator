#ifndef Soldier_HPP
#define Soldier_HPP

#include "Agent.h"
namespace model{

class Soldier: public Agent
{
public:
    Soldier() = delete;
    Soldier(const Soldier & copy) = delete;

    Soldier(int x, int y, Headquarter* creator, unsigned currentDate);
    virtual ~Soldier();

    void defineStrategy(StrategyEnum type);

    void simulate(unsigned date, World& world) override;

    // global constants
    static const int STARTING_HP;
    static const int AVG_LIVING;
    static const int STDDEV_LIVING;
    static const int RANGE_SHOOT;
    void action(int phase);

    // global enum to choose a strategy
    enum StrategyEnum { PROTECTION, ATTACK, KAMIKAZE };

private:
    // nested classes
    class StrategySoldier // interface
    {
    public:
        StrategySoldier() = delete;
        StrategySoldier(StrategySoldier const&) = delete;
        virtual ~StrategySoldier();

        virtual void simulate(unsigned date, World& world) = 0;
    };
    class StrategyProtection: public Soldier::StrategySoldier
    {
    public:
        StrategyProtection(StrategyProtection const&) = delete;
        virtual ~StrategyProtection();

        void simulate(unsigned date, World& world) override;
    };
    class StrategyAttack: public Soldier::StrategySoldier
    {
    public:
        StrategyAttack(StrategyAttack const&) = delete;
        virtual ~StrategyAttack();

        void simulate(unsigned date, World& world) override;
    };
    class StrategyKamikaze: public Soldier::StrategySoldier
    {
    public:
        StrategyKamikaze(StrategyKamikaze const&) = delete;
        virtual ~StrategyKamikaze();

        void simulate(unsigned date, World& world) override;
    };

protected:
    StrategySoldier* strategy;
    Agent* attackTarget; // either it is nullptr when the soldier moves or it points at the target

    // friendship with strategies
    friend class StrategyProtection;
    friend class StrategyAttack;
    friend class StrategyKamikaze;
};
}
#endif // Soldier_HPP
