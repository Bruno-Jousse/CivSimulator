/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

Headquarter::Headquarter(QColor color, int x, int y, int w, int h, int metalAmount, int aggressivity, int hp) : Building(color, x, y, w, h, hp), metalAmount(metalAmount), aggressivity(aggressivity){
}

Headquarter::Headquarter(int metalAmount, int aggressivity, int hp) : Building(hp), metalAmount(metalAmount), aggressivity(aggressivity){
}


void Headquarter::action(){
    if(frame%60==0){
        spawnMachine();
    }
    while(metalAmount>=10){
        createAWorker();
    }
}

int Headquarter::getMetalAmount() const
{
    return metalAmount;
}

void Headquarter::setMetalAmount(int value)
{
    metalAmount = value;
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
    if(metalAmount>=10){
        metalAmount-=10;
        productionLine.push_back(make_pair(3,0));
    }
}

void Headquarter::createASoldier(){
    if(metalAmount>=25){
        metalAmount-=25;
        productionLine.push_back(make_pair(5,1));
    }
}

void Headquarter::spawnMachine(){
    for(auto it=productionLine.begin(); it!=productionLine.end(); it++){
        it->first--;

        if(it->first == 0){
            QPoint pos;
            switch(it->second){
                case 0:{
                    Worker *w = new Worker(color, 1, 1, 30, 30, 5, false, 5, 1, 10);
                    pos=searchAvailablePlaceAround(*w);
                    if(pos.x()==-1 || pos.y()== -1){
                        it->first++;
                    }
                    else{
                        w->setPos(pos);
                        w->setParentItem(parentItem());
                        workers.push_back(w);
                    }
                    break;
                }
                case 1:{
                    Soldier* s = new Soldier(color, 1, 1, 30, 30, 1, false, 10, 1, 10);
                    pos=searchAvailablePlaceAround(*s);
                    if(pos.x()==-1 || pos.y()== -1){
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



void Headquarter::updateGrids(World& world)
{
	gridAllyHeadquarter = Grid(100, x, y);

	Grid tmpGridEnemies;
	for (Agent* a : world.getEnemiesVisibleBy(this))
	{
		tmpGridEnemies += Grid(100, a->getX(), a->getY());
	}
	gridEnemies = tmpGridEnemies;

	Grid tmpGridResources;
	for (Resource* r : world.getResourcesVisibleBy(this))
	{
		tmpGridResources += Grid(100, r->getX(), r->getY());
	}
	gridResources = tmpGridResources;

	Grid tmpGridAllyAgents;
	for (Agent* a : world.getAgentOf(this))
	{
		tmpGridAllyAgents += Grid(100, a->getX(), a->getY());
	}
	gridAllyAgents = tmpGridAllyAgents;
}
