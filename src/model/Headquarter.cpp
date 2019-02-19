#include "Headquarter.h"
namespace model{

// global constants
const int Headquarter::STARTING_HP = 50;

Headquarter::Headquarter(int x, int y): Entity(x, y), hp(Headquarter::STARTING_HP)
{}

Headquarter::~Headquarter()
{
}

void Headquarter::simulate(unsigned date, World& world)
{
    // TODO
}

void updateGrids(World world)
{
    gridAllyHeadquarter = Grid(100, x, y);
    
    Grid tmpGridEnemies = Grid();
    // TODO : ask all units which enemies they see

    // TODO update resources 

}
void deleteGrids()
{
    delete gridAllyHeadquarter;
    delete gridEnnemies;
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

}
