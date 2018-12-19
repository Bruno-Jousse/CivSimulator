#include "World.h"

World::World(int nbCiv, int width, int length) : width(width), length(length){
    init(nbCiv);
    months=0;
}

void World::init(int nbFactions){
    factions.resize(size_t(nbFactions));
    int r=0, g =0, b=0, x, y, cpt=0;
    Headquarter hq;
    int nbFactBySide = (int)(ceil(nbFactions/4.0));
    int distX = (int)(width/nbFactBySide+1);
    int distY = (int)(length/nbFactBySide+1);
    vector< vector<int> > positions(nbFactions);

    //Set position North side
    x=distX;
    y=0;
    for(int i=0; i<nbFactBySide; i++, cpt++){
        positions[cpt].push_back(x);
        positions[cpt].push_back(y);
        x += distX;
    }

    //Set position South Side
    x=distX;
    y=length-1;
    for(int i=0; i<nbFactBySide && cpt<nbFactions; cpt++, i++){
        positions[cpt].push_back(x);
        positions[cpt].push_back(y);
        x += distX;
    }

    //Set position East Side
    x=0;
    y=distY;
    for(int i=0; i<nbFactBySide && cpt<nbFactions; cpt++, i++){
        positions[cpt].push_back(x);
        positions[cpt].push_back(y);
        y += distY;
    }

    //Set position West Side
    x=width-1;
    y=distY;
    for(int i=0; i<nbFactBySide && cpt<nbFactions; cpt++, i++){
        positions[cpt].push_back(x);
        positions[cpt].push_back(y);
        y += distY;
    }

    for(int i=0; i<=nbFactions && r<=255; i++){
        hq.setX(positions[i][0]);
        hq.setY(positions[i][1]);
        //Set color
        if(i%3==0){
            hq.setColor(QColor(255, g, b, 255));
        }
        else if(i%3==1){
            hq.setColor(QColor(r, 255, b, 255));
        }
        else{
            hq.setColor(QColor(r, g, 255, 255));
            r+=50, g+=50, b+=50;
        }

        factions.push_back(hp);
    }

    //Generate ressources
    Metal metal();

    for(int i=0; i<5*(nbFactions); i++){
        do{
            metal.setX(distribInt(generator)%width);
            metal.setY(distribInt(generator)%length);

        }while(/*Pas de conflit avec un autre objet*/);
    }
}

void World::simulate(){
    while(months <= 100){

    }
}

bool World::estOccupe(int x, int y, int w, int h){
    bool estOccupe=false;
    int i=0;

    while(!estOccupe && i<factions.size()){
        if( ( (x<factions[i].getX() && x+w > factions[i].getX() || x>factions[i].getX() && x < factions[i].getX() + factions[i].getW()) && (y<factions[i].getY() && y+h > factions[i].getY() || y>factions[i].getY() && y < factions[i].getY() + factions[i].getH()) )
                || ( (x<ressources[i].getX() && x+w > ressources[i].getX() || x>ressources[i].getX() && x < ressources[i].getX() + ressources[i].getW() ) && ( y<ressources[i].getY() && y+h > ressources[i].getY() || y>ressources[i].getY() && y < ressources[i].getY() + ressources[i].getH()) ) ){
           estOccupe = true;
        }
        else if( ( ){

        }
    }
}
