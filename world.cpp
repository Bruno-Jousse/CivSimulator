#include "world.hpp"


World::World()
{
    width=20;
    length=20;
    init(3);
}

World::World(int nbCiv, int width, int length){

}

void World::init(int nbCivs){
    civilisations.resize(nbCivs);
    int r=0, g =0, b=0;
    Headquarter hq();

    for(int i=0; i<=nbCivs && r<=255; i++){
        hq.setX(distribInt(generator)%width);
        hq.setY(distribInt(generator)%length);
        if(i!=0 && i%3==0){
            hq.setColor(QColor(255, g, b, 255));
            civilisations.push_back(hq);
        }
        else if(i%3==1){
            hq.setColor(QColor(r, 255, b, 255));
            civilisations.push_back(hq);
        }
        else{
            hq.setColor(QColor(r, g, 255, 255));
            r+=50, g+=50, b+=50;
        }
    }
}
