#include "World.h"

World::World(int nbCivs, int width, int length) :  nbCivs(nbCivs), width(width), length(length){

}


void World::init(){
    cout << "World initialisation.";
    int r=0, g =0, b=0;
    Headquarter* hq;
    Metal* ress;

    for(int i=0; i<nbCivs; i++){
        hq = new Headquarter();
        do{
            hq->setX(distribInt(generator)%(width-hq->getW()));
            hq->setY(distribInt(generator)%(length-hq->getH()));
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

        scene()->addItem(hq);
        factions.push_back(hq);
    }

    cout << ".";

    for(int i=0; i <nbCivs*3; i++){
        ress = new Metal();
        do{
            ress->setX(distribInt(generator)%(width-ress->getW()));
            ress->setY(distribInt(generator)%(length-ress->getH()));
        }while(!scene()->collidingItems(ress).isEmpty());

        scene()->addItem(ress);
        ressources.push_back(ress);
    }
    cout << "." << endl;
}

/* init2
 * void World::init(int nbFactions){
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

            ...

    //Generate ressources
    Metal metal();

    for(int i=0; i<5*(nbFactions); i++){
        do{
            metal.setX(distribInt(generator)%width);
            metal.setY(distribInt(generator)%length);

        }while(Pas de conflit avec un autre objet);
    }
*/


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

QRectF World::boundingRect() const{
    return QRectF();
}
QPainterPath World::shape() const{
    return QPainterPath();
}

void World::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){
}
