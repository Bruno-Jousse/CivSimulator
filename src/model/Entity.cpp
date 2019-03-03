#include "Entity.h"

namespace model{

Entity::Entity(int x, int y, int w, int h): x(x), y(y), w(w), h(h)
{}

Entity::~Entity()
{}


QPoint Entity::searchAvailablePlaceAround(Entity &r){
    QPoint pos, cmp(-1,-1);
    int tmp;
    if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()-r.getH()-1, getX()+getW()+r.getW(), r)) == cmp){
        if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()+getH()+1, getX()+getW()+r.getW(), r)) == cmp){
            if( (pos=searchAvailableOnLine(getY()-r.getH(), getX()-r.getW()-1, getY()+getH()+r.getH(), r)) == cmp){
                pos=searchAvailableOnLine(getY()-r.getH(), getX()+getW()+1, getY()+getH()+r.getH(), r);
                tmp = pos.x();
                pos.setX(pos.y());
                pos.setY(tmp);
            }
            else{
                tmp = pos.x();
                pos.setX(pos.y());
                pos.setY(tmp);
            }
        }
    }

    return pos;
}

QPoint Entity::searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r){
    QPoint pos(-1, -1);
    bool isPlaced=false;
    r.setY(y);
    while(!isPlaced && xSource<=xDestination){
        r.setX(xSource);
        if(scene()->collidingItems(&r).isEmpty()){
            pos.setX(xSource);
            pos.setY(y);
            isPlaced=true;
        }
        xSource+=1;
    }

    return pos;
}
}
