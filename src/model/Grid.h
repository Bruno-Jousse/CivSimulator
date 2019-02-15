#ifndef Grid_HPP
#define Grid_HPP

#include "World.h"

class Grid final
{
public:
    Grid(int seed, int x, int y);

private:
    double grid[World::NB_ROW][World::NB_COL];
};

#endif // Grid_HPP