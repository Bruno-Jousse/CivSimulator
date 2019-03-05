#include "World.h"

const int World::VISIBILITY_RANGE = 3;


World::World(int nbCivs, int w, int h) :  Entity(Qt::transparent, 0, 0, w, h), nbCivs(nbCivs){

}


void World::init(){
    cout << "World initialisation.";
    int r=0, g =0, b=0;
    Headquarter* hq;
    Metal* ress;

    for(int i=0; i<nbCivs; i++){
        hq = new Headquarter();
        do{
            hq->setX(distribInt()%(getW()-hq->getW()));
            hq->setY(distribInt()%(getH()-hq->getH()));
            cout << distribInt() << " " << hq->getX() << " " << hq->getY() << endl;
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
            ress->setX(distribInt()%(getW()-ress->getW()));
            ress->setY(distribInt()%(getH()-ress->getH()));
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

void World::simulateOneTurn(unsigned date)
{
	random_shuffle(headquarters.begin(), headquarters.end());
	for (auto& hq : headquarters)
		hq->simulate(date, *this);

	random_shuffle(agents.begin(), agents.end()); // TODO : if we still use the PRNG from std use it as third argument
	for (auto & a : agents)
		a->simulate(date, *this);

	// TODO : if there is new entities add them here and remove the dead ones
}


int World::distanceBetween(const Entity& a, const Entity& b)
{
	return abs(a.getX() - b.getX()) + abs(a.getY() - b.getY());
}

bool World::isNextToResource(const Entity& e)
{
	for (const Resource& r : resources)
	{
		if (distanceBetween(r, e) == 1)
			return true;
	}
	return false;
}

vector<Agent*> World::getEntitiesOf(Headquarter* hq)
{
	vector<Agent*> ret;
	for (Agent* e : agents)
	{
		if (e.doesBelongTo(hq))
			ret.push_back(e);
	}
	return ret;
}

int World::distanceMin(Entity* e, vector<Agent*>& vect)
{
	int minDist = 100000;
	for (Agent* a : vect)
	{
		int dist = distanceBetween(*a, *e);
		if (dist < minDist)
			minDist = dist;
	}
	return minDist;
}

vector<Agent*> World::getEnemiesVisibleBy(Headquarter* hq)
{
	vector<Agent*> enemies;
	vector<Agent*> ally = getEntitiesOf(hq);
	for (Agent* a : agents)
	{
		if (!a.doesBelongTo(hq) && distanceMin(a, ally) <= VISIBILITY_RANGE)
			enemies.push_back(a);
	}
	return enemies;
}

std::vector<Headquarter*> World::getHeadquartersVisibleBy(Headquarter* hq)
{
	vector<Headquarter*> enemyHq;
	vector<Agent*> ally = getEntitiesOf(hq);
	for (Headquarter* h : headquarters)
	{
		if (distanceMin(h, ally) <= VISIBILITY_RANGE)
			enemyHq.push_back(h);
	}
	return enemyHq;
}

std::vector<Resource*> World::getResourcesVisibleBy(Headquarter* hq)
{
	vector<Resource*> res;
	vector<Agent*> ally = getEntitiesOf(hq);
	for (Resource* r : resources)
	{
		if (distanceMin(r, ally) <= VISIBILITY_RANGE)
			res.push_back(r);
	}
	return res;
}

vector<Agent*> World::getAgentsTargetableBy(const Soldier& soldier)
{
	vector<Agent*> possibleTargets;
	for (Agent* a : agents)
	{
		int dist = distanceBetween(*a, soldier);
		if (dist != 0 && dist <= Soldier::RANGE_SHOOT && !a->doesBelongTo(Soldier.getHeadquarter()))
			possibleTargets.push_back(a);
	}
	return possibleTargets;
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
