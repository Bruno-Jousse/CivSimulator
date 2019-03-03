#ifndef Entity_HPP
#define Entity_HPP
#include "QPoint"

namespace model{

class Entity
{
public:
    Entity() = delete;
    Entity(Entity const&) = delete;
    
    Entity(int x, int y, int w=1, int h=1);
    virtual ~Entity();

    /**
     * This methode must be called every turn
     * Depending on the Entity
     * - It uploads nextX and nextY if present (agent)
     * - It fires at enemies (soldier)
     * - It creates new entities (hq)
     * - It dies (entity)
     */
    virtual void simulate(unsigned date) = 0;

    QPoint searchAvailablePlaceAround(Entity &r);
    QPoint searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r);
    // inline getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getW() const { return w; }
    int getH() const { return h; }
    void setX(int a){ x = a;}
    void setY(int a){ y = a;}
    void setW(int a){ w = a;}
    void setH(int a){ h = a;}

    //View conversion
    int getPosX() const { return x*30; }
    int getPosY() const { return y*30; }
    int getWidth() const { return w*30; }
    int getHeight() const { return h*30; }

protected:
    int x;
    int y;
    int w;
    int h;

private:

};

}

#endif // Entity_HPP
