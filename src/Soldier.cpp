#include "Soldier.h"
#include "World.h"
#include "Headquarter.h"

 // init constants
const int Soldier::STARTING_HP = 10;
const int Soldier::AVG_LIVING = 150;
const int Soldier::STDDEV_LIVING = 20;
const int Soldier::RANGE_SHOOT = 3;
const int Soldier::DMG = 1;


Soldier::Soldier(World* w, Headquarter* creator, QColor color, int x, int y) : Machine(w, creator, color, x, y, STARTING_HP){
    deathDate = TimeManager::getInstance().getFrame() +  static_cast<int>(round(RandomManager::getInstance().getGaussian(Soldier::AVG_LIVING, Soldier::STDDEV_LIVING)));
    strategy = new StrategyProtection(world, this);
}


void Soldier::suppression() {
	Entity::suppression();
	delete strategy;
}

void Soldier::action(){
    if (isDead()) // simulate only for living agents
        return;

    attackTarget = nullptr;
    QVector<Machine*> enemies = world->getAgentsTargetableBy(*this);
    if (enemies.isEmpty()) // move
        strategy->simulate();
    else // shoot
    {
        Machine* weakest = enemies[0];
        for (Machine* a : enemies)
        {
            if (a->getHp() < weakest->getHp())
                weakest = a;
        }
        attackTarget = weakest;
    }
}


void Soldier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter, "S");
}


void Soldier::defineStrategy(StrategyEnum type)
{
	delete strategy;
	switch (type)
	{
	case PROTECTION:
        strategy = new StrategyProtection(world, this);
		break;

	case ATTACK:
        strategy = new StrategyAttack(world, this);
		break;

	default:
        strategy = new StrategyKamikaze(world, this);
	}
}

// Nested classes strategies
Soldier::StrategySoldier::~StrategySoldier() {}
Soldier::StrategyProtection::~StrategyProtection() {}
Soldier::StrategyAttack::~StrategyAttack() {}
Soldier::StrategyKamikaze::~StrategyKamikaze() {}

void Soldier::StrategyProtection::simulate()
{
    Grid decisionGrid = 0.6*owner->getHeadquarter()->getGridAllyAgents() + 0.4*owner->getHeadquarter()->getGridAllyHeadquarter();
    chooseBestNeighbor(decisionGrid, owner->getX(), owner->getY(), owner->nextX, owner->nextY);
}
void Soldier::StrategyAttack::simulate(){
    chooseBestNeighbor(owner->getHeadquarter()->getGridEnemies(), owner->getX(),owner->getY(), owner->nextX, owner->nextY);
}
void Soldier::StrategyKamikaze::simulate()
{
    chooseBestNeighbor(owner->getHeadquarter()->getGridEnemies(), owner->getX(),owner->getY(), owner->nextX, owner->nextY);
}
