#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"
#include "Building.h"


class Soldier: public Machine {
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
	class StrategyProtection : public Soldier::StrategySoldier
	{
	public:
		StrategyProtection(StrategyProtection const&) = delete;
		virtual ~StrategyProtection();

		void simulate(unsigned date, World& world) override;
	};
	class StrategyAttack : public Soldier::StrategySoldier
	{
	public:
		StrategyAttack(StrategyAttack const&) = delete;
		virtual ~StrategyAttack();

		void simulate(unsigned date, World& world) override;
	};
	class StrategyKamikaze : public Soldier::StrategySoldier
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

public:

    // global enum to choose a strategy
    enum StrategyEnum { PROTECTION, ATTACK, KAMIKAZE };

    Soldier( Headquarter* creator, QColor color, int x=0, int y=0);
    void action() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	void defineStrategy(StrategyEnum type);
	void suppression() override;
	void simulate(unsigned date, World& world) override;

	// global constants
	static const int STARTING_HP;
	static const int AVG_LIVING;
	static const int STDDEV_LIVING;
	static const int RANGE_SHOOT;
	static const int DMG;



};

#endif //_SOLDIER_H
