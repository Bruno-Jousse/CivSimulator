#include "World.h"

#include <algorithm>

using namespace std;
namespace model{

const int World::NB_ROW = 20;
const int World::NB_COL = 20;

World::World(): entities()
{
    // TODO : (Bruno) paste your code of random initialisation here
}

World::~World()
{}

void World::simulateOneTurn(unsigned date)
{
    // TODO : construct a grid (2D array) of the unit to have acces to them quicker
    random_shuffle(entities.begin(), entities.end()); // TODO : if we still use the PRNG from std use it as third argument
    for(auto & entity: entities)
    {
        entity->simulate(date);
    }
    // TODO : if there is new entities add them here and remove the dead ones
}


void World::init(){
    cout << "World initialisation.";
    int r=0, g =0, b=0;
    Headquarter* hq;
    Metal* ress;

    for(int i=0; i<nbCivs; i++){
        hq = new Headquarter();
        do{
            hq->setX(model::RandomManager::getInstance().getRandomInt(getW()-hq->getW()));
            hq->setY(model::RandomManager::getInstance().getRandomInt(getH()-hq->getH()));
        }while(!scene()->collidingItems(hq).isEmpty());
        if(i%3==0){
            hq->setColor(QColor(255, g, b, 255));
        }
        else if(i%3==1){
            hq->setColor(QColor(r, 255, b, 255));
        }
        else{
            hq->setColor(QColor(r, g, 255, 255));
            r=(r+50)%256; g=(g+50)%256; b=(b+50)%256;
        }

        hq->setParentItem(this);
        //scene()->addItem(hq);
        factions.push_back(hq);
    }

    cout << ".";

    for(int i=0; i <nbCivs*3; i++){
        ress = new Metal();
        do{
            ress->setX(model::RandomManager::getInstance().getRandomInt(getW()-ress->getW()));
            ress->setY(model::RandomManager::getInstance().getRandomInt(getH()-ress->getH()));
        }while(!scene()->collidingItems(ress).isEmpty());

        ress->setParentItem(this);
        //scene()->addItem(ress);
        ressources.push_back(ress);
    }
    cout << "." << endl;
}

void World::advance(int phase){
    if(phase != 1){
        if(frame%60 == 0){
            cout << "One more month pasted. This is the " << getMonth() << "th month.";
        }
        cout << "Suppression of all dead units.";
        auto it = factions.begin();
        while(it!=factions.end()){
            if((*it)->getHp() <= 0){
                (*it)->suppression();
                it=factions.erase(it);
            }
            else{
                auto it2 = (*it)->getWorkers().begin();
                while(it2!=(*it)->getWorkers().end()){
                    if((*it2)->getHp() <=0){
                        (*it2)->suppression();
                        it2=(*it)->getWorkers().erase(it2);
                    }
                    else{
                        it2++;
                    }
                }
                auto it3 = (*it)->getSoldiers().begin();
                while(it3!=(*it)->getSoldiers().end()){
                    if((*it3)->getHp() <=0){
                        (*it3)->suppression();
                        it3=(*it)->getSoldiers().erase(it3);
                    }
                    else{
                        it3++;
                    }
                }
                it++;
            }
        }
        cout << ".";
        auto it3 = ressources.begin();
        while(it3!=ressources.end()){
            if((*it3)->getAmount() <= 0){
                (*it3)->suppression();
                it3=ressources.erase(it3);
            }
            else{
                it3++;
            }
        }
        cout << "." << endl;
        frame+=1;
    }
}
}
