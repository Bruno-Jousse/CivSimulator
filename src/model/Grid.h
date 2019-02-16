#ifndef Grid_HPP
#define Grid_HPP

#include "World.h"

namespace model{

class Grid final
{
public:
    Grid();
    Grid(const Grid& g);
    Grid(int seed, int x, int y);

    double& operator()(int x, int y);

private:
    double grid[World::NB_ROW][World::NB_COL];

    // private methods
    void propagate(int x, int y, double coef);
    bool isInGrid(int x, int y);
    void tryDiffuse(int x, int y, int xt, int yt, double coef);

    // friendship
    friend Grid operator+(const Grid& a, const Grid& b);
    friend Grid operator*(const double& scalar, const Grid& g);
};

Grid operator+(const Grid& a, const Grid& b);
Grid operator*(const double& scalar, const Grid& g);

}

#endif // Grid_HPP