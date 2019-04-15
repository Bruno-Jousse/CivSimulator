#include "Headquarter.h"
#include "World.h"


int const Headquarter::STARTING_HP = 100;
int const Headquarter::METAL_STOCK_MAX = 150;

Headquarter::Headquarter(World* w, QColor color, int x, int y) : Building(w, STARTING_HP, color, x, y), metalStockBar(Qt::gray, 0, getH()-10, getW(), 10, METAL_STOCK_MAX), gridAllyHeadquarter(world->getW(), world->getH()), gridAllyAgents(world->getW(), world->getH()), gridEnemies(world->getW(), world->getH()), gridResources(world->getW(), world->getH()), strategy(new HQNeutralStrategy(this)){
    metalStockBar.setParentItem(this);
	initStrategy();
}

void Headquarter::action(){
    cout << "A headquarter is doing its action" << endl;
    if(TimeManager::getInstance().isNewMonth()){
        spawnMachine();
    }
    strategy->createUnit(metalStockBar.getHpRef());
}

int Headquarter::getMetalAmount() const
{
    return metalStockBar.getHp();
}

void Headquarter::setMetalAmount(int value)
{
    metalStockBar.setHp(value);
}

QVector<Soldier*> Headquarter::getSoldiers() const
{
    return soldiers;
}

QVector<Worker*> Headquarter::getWorkers() const
{
    return workers;
}

QVector<pair<int, int> > Headquarter::getProductionLine() const
{
    return productionLine;
}


void Headquarter::createAWorker(){
    if(getMetalAmount()>=10){
        setMetalAmount(getMetalAmount()-10);
        productionLine.push_back(make_pair(3,0));
    }
}

void Headquarter::createASoldier(){
    if(getMetalAmount()>=25){
        setMetalAmount(getMetalAmount()-25);
        productionLine.push_back(make_pair(5,1));
    }
}

void Headquarter::spawnMachine(){
    for(auto it=productionLine.begin(); it!=productionLine.end(); it++){
        it->first--;

        if(it->first == 0){
            switch(it->second){
                case 0:{
                    Worker *w = new Worker(world, this, color);
                    if(!searchAvailablePlaceAround(*w)){
                        it->first++;
                    }
                    else{
                        w->setParentItem(parentItem());
                        workers.push_back(w);
                    }
                    break;
                }
                case 1:{
                    Soldier* s = new Soldier(world, this, color);
                    if(!searchAvailablePlaceAround(*s)){
                        it->first++;
                    }
                    else{
                        s->setParentItem(parentItem());
                        //scene()->addItem(&s);
                        soldiers.push_back(s);
                    }
                    break;
                }
            }
        }
    }
}

void Headquarter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Entity::paint(painter, option, widget);
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignCenter, "HQ");
}



void Headquarter::updateGrids()
{
    gridAllyHeadquarter = Grid(world->getW(), world->getH(), 100, getX(), getY());

    Grid tmpGridEnemies(world->getW(), world->getH());
    for (Agent* a : world->getEnemiesVisibleBy(this))
	{
        tmpGridEnemies += Grid(world->getW(), world->getH(),100, a->getX(), a->getY());
	}
	gridEnemies = tmpGridEnemies;

    Grid tmpGridResources(world->getW(), world->getH());
    for (Resource* r : world->getResourcesVisibleBy(this))
	{
        tmpGridResources += Grid(world->getW(), world->getH(),100, r->getX(), r->getY());
	}
	gridResources = tmpGridResources;

    Grid tmpGridAllyAgents(world->getW(), world->getH());
    for (Machine* a : world->getEntitiesOf(this))
	{
        tmpGridAllyAgents += Grid(world->getW(), world->getH(),100, a->getX(), a->getY());
	}
	gridAllyAgents = tmpGridAllyAgents;
}

Headquarter::HQAggroStrategy::~HQAggroStrategy() {
}

Headquarter::HQNeutralStrategy::~HQNeutralStrategy() {
}

Headquarter::HQDevelopmentStrategy::~HQDevelopmentStrategy() {
}

Headquarter::IHQStrategy::~IHQStrategy() {
}


