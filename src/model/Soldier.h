#ifndef Soldier_HPP
#define Soldier_HPP

#include "Agent.h"

class Soldier: public Agent
{
public:
    Soldier() = delete;
    Soldier(const Soldier & copy) = delete;

    Soldier(int x, int y, Headquarter* creator);
    virtual ~Soldier();

    void simulate(unsigned date) override;

    // global constants
    static const int STARTING_HP;
    static const int AVG_LIVING;
    static const int STDDEV_LIVING;
    static const int RANGE_SHOOT;

private:
    // nested classes
    class StrategySoldier // interface
    {
    public:
        StrategySoldier() = delete;
        StrategySoldier(StrategySoldier const&) = delete;
        virtual ~StrategySoldier();

        virtual void simulate(unsigned date) = 0;
    };
    class StrategyProtection: public Soldier::StrategySoldier
    {
    public:
        StrategyProtection(StrategyProtection const&) = delete;
        virtual ~StrategyProtection();

        void simulate(unsigned date) override;
    };
    class StrategyAttack: public Soldier::StrategySoldier
    {
    public:
        StrategyAttack(StrategyAttack const&) = delete;
        virtual ~StrategyAttack();

        void simulate(unsigned date) override;
    };
    class StrategyKamikaze: public Soldier::StrategySoldier
    {
    public:
        StrategyKamikaze(StrategyKamikaze const&) = delete;
        virtual ~StrategyKamikaze();

        void simulate(unsigned date) override;
    };

protected:
    StrategySoldier* strategy;

    // friendship with strategies
    friend class StrategyProtection;
    friend class StrategyAttack;
    friend class StrategyKamikaze;
};

#endif // Soldier_HPP