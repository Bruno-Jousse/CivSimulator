#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"

class Soldier: public Machine {
protected:

	// nested classes
	class StrategySoldier // interface
	{
	public:
        World* w;
        Soldier* owner;
        StrategySoldier(World* w, Soldier* hq) : w(w), owner(hq){}
		StrategySoldier(StrategySoldier const&) = delete;
		virtual ~StrategySoldier();

        virtual void simulate() = 0;
	};
    class StrategyProtection : public Soldier::StrategySoldier
	{
	public:
        StrategyProtection(World* w, Soldier* hq) : StrategySoldier(w, hq){}
		StrategyProtection(StrategyProtection const&) = delete;
        virtual ~StrategyProtection() override;

        void simulate() override;
	};
	class StrategyAttack : public Soldier::StrategySoldier
	{
	public:
        StrategyAttack(World* w, Soldier* hq) : StrategySoldier(w, hq){}
		StrategyAttack(StrategyAttack const&) = delete;
        virtual ~StrategyAttack() override;

        void simulate() override;
	};
	class StrategyKamikaze : public Soldier::StrategySoldier
	{
	public:
        StrategyKamikaze(World* w, Soldier* hq) : StrategySoldier(w, hq){}
		StrategyKamikaze(StrategyKamikaze const&) = delete;
        virtual ~StrategyKamikaze() override;

        void simulate() override;
	};

protected:
	StrategySoldier* strategy;
	Agent* attackTarget; // either it is nullptr when the soldier moves or it points at the target

						 // friendship with strategies
	friend class StrategyProtection;
	friend class StrategyAttack;
	friend class StrategyKamikaze;

public:

    // global enum to choose a strategy
    enum StrategyEnum { PROTECTION, ATTACK, KAMIKAZE };

    Soldier(World* w, Headquarter* creator, QColor color, int x=0, int y=0);
    void action() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	void defineStrategy(StrategyEnum type);
	void suppression() override;

	// global constants
	static const int STARTING_HP;
	static const int AVG_LIVING;
	static const int STDDEV_LIVING;
	static const int RANGE_SHOOT;
	static const int DMG;


};

#endif //_SOLDIER_H
