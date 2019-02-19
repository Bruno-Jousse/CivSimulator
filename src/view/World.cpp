#include "World.h"

namespace view{

World::World(int nbCivs, int w, int h) :  Entity(Qt::transparent){
    data = new model::World(nbCivs, w, h);
    /*
    for(Headquarter* h : factions){
        h->setParentItem(this);
    }
    for(Resource* r : ressources){
        r->setParentItem(this);
    }
    */
}

//Use scene()->collidingItems(&QGraphicsItem).isEmpty() instead
/*
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
*/

QRectF World::boundingRect() const{
    return QRectF();
}
QPainterPath World::shape() const{
    return QPainterPath();
}

void World::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){
}
}
