/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

Headquarter::Headquarter(int metalAmount, int aggressivity, int hp, QColor color, int x, int y, int w, int h) : Building(hp, color, x, y, w, h), metalAmount(metalAmount), aggressivity(aggressivity){
}

void Headquarter::action(){
    if(frame%60==0){
        spawnMachine();
    }
    while(metalAmount>=10){
        createASoldier();
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
            pair<int, int> pos;
            switch(it->second){
                case 0:{
                    Worker w(5, false, 5, 1, 10, color, 1, 1, 1, 1);
                    pos=searchAvailablePlaceAround(w);
                    if(pos.first==-1 || pos.second == -1){
                        it->first++;
                    }
                    else{
                        childItems().push_back(&w);
                        workers.push_back(&w);
                    }
                    break;
                }
                case 1:{
                    Soldier s(1, false, 10, 1, 10, color, 1, 1, 1, 1);
                    pos=searchAvailablePlaceAround(s);
                    if(pos.first==-1 || pos.second == -1){
                        it->first++;
                    }
                    else{
                        childItems().push_back(&s);
                        soldiers.push_back(&s);
                    }
                    break;
                }
            }
        }
    }
}

void Headquarter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Figure::paint(painter, option, widget);
    painter->setBrush(Qt::black);
    painter->drawText(body, Qt::AlignCenter, "HQ");
}

