#include "World.h"

World::World(int nbCiv, int width, int length) :  width(width), length(length){
    init(nbCiv);
}

void World::init(int nbCivs){
    factions.resize(nbCivs);
    int r=0, g =0, b=0;
    Headquarter* hq;
    Metal* ress;

    for(int i=0; i<=nbCivs && r<=255; i++){
        hq = new Headquarter();
        do{
            hq->setX(distribInt(generator)%(width-hq->getW()));
            hq->setY(distribInt(generator)%(length-hq->getH()));
        }while(!scene()->collidingItems(hq).isEmpty());
        if(i!=0 && i%3==0){
            hq->setColor(QColor(255, g, b, 255));
        }
        else if(i%3==1){
            hq->setColor(QColor(r, 255, b, 255));
        }
        else{
            hq->setColor(QColor(r, g, 255, 255));
            r+=50; g+=50; b+=50;
        }
        scene()->addItem(hq);
        factions.push_back(hq);
    }

    for(int i=0; i <nbCivs*3; i++){
        ress = new Metal();
        ress->setColor(Qt::gray);
        do{
            ress->setX(distribInt(generator)%(width-ress->getW()));
            ress->setY(distribInt(generator)%(length-ress->getH()));
        }while(!scene()->collidingItems(ress).isEmpty());

        scene()->addItem(ress);
        ressources.push_back(ress);
    }
}

void World::advance(int phase){
    //Suppresion of all dead units
    if(phase != 1){
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
                it++;
            }
        }
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
    }
}

//Use scene()->collidingItems(&QGraphicsItem).isEmpty() instead
bool World::isOccupied(QRect obj){
    int i=0, j;
    bool isOccupied=false;
    while(i<factions.size() && !isOccupied){
        isOccupied=collider(obj, factions.at(i)->getBody());
        j=0;
        while(j<factions.at(i)->getWorkers().size() && !isOccupied){
            isOccupied=collider(obj, factions.at(i)->getWorkers().at(i)->getBody());
            j++;
        }
        j=0;
        while(j<factions.at(i)->getSoldiers().size() && !isOccupied){
            isOccupied=collider(obj, factions.at(i)->getSoldiers().at(i)->getBody());
            j++;
        }

        i++;
    }

    i=0;
     while(i<ressources.size() && !(isOccupied=collider(obj, ressources.at(i)->getBody())) ){
         i++;
     }

     return isOccupied;
}

//Use scene->collidingItems(&ress).isEmpty() instead
bool World::isOccupiedByHQ(QRect obj){
    int i=0;
    while(i<factions.size() && !collider(obj, factions.at(i)->getBody())){
        i++;
    }

    return i==factions.size();
}

//Use scene->collidingItems(&ress).isEmpty() instead
bool World::collider(QRect r1, QRect r2){

    return !( r1.x() + r1.width() < r2.x()
              || r1.y() + r1.height() < r2.y()
              || r2.x() + r2.width() < r1.x()
              || r2.y() + r2.height() < r1.y()
      );
}

QRectF boundingRect(){
    return QRectF();
}
QPainterPath shape() {
    return QPainterPath();
}

void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}
