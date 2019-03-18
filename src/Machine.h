/**
 * Project Untitled
 */


#ifndef _MACHINE_H
#define _MACHINE_H

#include "Agent.h"
#include "Healthbar.h"
//#include "Headquarter.h"

class Machine: public Agent {
protected:
    Healthbar healthbar;
    Headquarter* hq;
    float deathDate;
    //Movement Speed
    //int ms;

    void moveTo(int, int);

public:
    Machine(Headquarter* creator, QColor color, int x, int y, int hp);
    //virtual ~Machine() = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    int getHp();
    void setHp(int hp);


    virtual bool isDead(unsigned date);
    bool doesBelongTo(Headquarter* headquarter);

    // inline getters
    Headquarter* getHeadquarter() const { return hq; }

    static void chooseBestNeighbor(const Grid& decisionGrid, int x, int y, int& nextX, int& nextY);

};

#endif //_MACHINE_H
