#ifndef Entity_HPP
#define Entity_HPP

class Entity
{
public:
    Entity(int x, int y);
    virtual ~Entity();

    virtual void simulate(unsigned date) = 0;

    // inline getters
    int getX() const { return x; };
    int getY() const { return y; };

protected:
    int x;
    int y;

private:

};

#endif // Entity_HPP