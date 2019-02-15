#include "Grid.h"

namespace model{

Grid::Grid()
{}

Grid::Grid(const Grid& g)
{
    // copy the grid
    for(int i=0; i<World::NB_ROW; i++)
    {
        for(int j=0; j<World::NB_COL; j++)
        {
            grid[i][j] = g.grid[i][j];
        }
    }
}

Grid::Grid(double seed, int x, int y, double coef)
{
    for(int i=0; i<World::NB_ROW; i++)
    {
        for(int j=0; j<World::NB_COL; j++)
        {
            grid[i][j] = 0; // initialize the grid with zeros
        }
    }

    // fill the grid
    grid[x][y] = seed;
    propagate(x, y, coef);
}

double Grid::operator()(int x, int y) const
{
    return grid[x][y];
}

void Grid::propagate(int x, int y, double coef)
{
    if(!isInGrid(x, y) || grid[x][y] != 0)
        return; // stop recursion if outside of the world or if already visited
    
    int xt=x-1, yt=y;
    // left cell
    tryDiffuse(x, y, xt, yt, coef);
    // right cell
    xt=x+1;
    tryDiffuse(x, y, xt, yt, coef);
    // upper cell
    xt=x;
    yt=y-1;
    tryDiffuse(x, y, xt, yt, coef);
    // under cell
    yt=y+1;
    tryDiffuse(x, y, xt, yt, coef);
}

bool Grid::isInGrid(int x, int y)
{
    return !(x<0 || x>=World::NB_ROW || y<0 || y>=World::NB_COL);
}

void Grid::tryDiffuse(int x, int y, int xt, int yt, double coef)
{
    if(isInGrid(xt, yt) && grid[xt][yt] == 0)
    {
        grid[xt][yt] = coef*grid[x][y];
        propagate(xt, yt, coef);
    }
}

Grid operator*(const double& scalar, const Grid& g)
{
    Grid copy;
    for(int i=0; i<World::NB_ROW; i++)
    {
        for(int j=0; j<World::NB_COL; j++)
        {
            copy.grid[i][j] = scalar*g.grid[i][j]; 
        }
    }
    return copy;
}

} // namespace model