#ifndef Entity_HPP
#define Entity_HPP
#include "QPoint"

namespace model{

class Entity
{
public:
    Entity() = delete;
    Entity(Entity const&) = delete;
    
    Entity(int x, int y);
    virtual ~Entity();

    virtual void simulate(unsigned date) = 0;
    QPoint searchAvailablePlaceAround(Entity &r);
    QPoint searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r);
    // inline getters
    int getX() const { return x; };
    int getY() const { return y; };

protected:
    int x;
    int y;
    int w;
    int h;

private:

};

}

#endif // Entity_HPP
