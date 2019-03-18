#include "Grid.h"

Grid::Grid(): grid(valarray<double>(0.0, World::NB_COL), World::NB_ROW)
{}

Grid::Grid(const Grid& g): grid(g.grid)
{}

Grid::Grid(double seed, int x, int y, double coef): grid(valarray<double>(0.0, World::NB_COL), World::NB_ROW)
{
    // fill the grid
    grid[x][y] = seed;
    if(coef != 0)
    {
        propagate(x, y, coef);
    }
}

Grid& Grid::operator=(const Grid& other)
{
    grid = other.grid;
}

double& Grid::operator()(int x, int y)
{
    return grid[x][y];
}

Grid& Grid::operator+=(const Grid& other)
{
    grid += other.grid;
    return this;
}
Grid& Grid::operator-=(const Grid& other)
{
    grid -= other.grid;
    return this;
}

void Grid::propagate(int x, int y, double coef)
{
    int xt=x-1, yt=y;
    // left cell
    tryDiffuse(xt, yt, coef);
    // right cell
    xt=x+1;
    tryDiffuse(xt, yt, coef);
    // upper cell
    xt=x;
    yt=y-1;
    tryDiffuse(xt, yt, coef);
    // under cell
    yt=y+1;
    tryDiffuse(xt, yt, coef);
}

bool Grid::isInGrid(int x, int y)
{
    return !(x<0 || x>=World::NB_ROW || y<0 || y>=World::NB_COL);
}

void Grid::tryDiffuse(int xt, int yt, double coef)
{
    if(isInGrid(xt, yt))
    {
        double nvVal = coef * maxNeighbor(xt, yt);
        if(nvVal > grid[xt][yt])
        {
            grid[xt][yt] = nvVal;
            propagate(xt, yt, coef);
        }
    }
}

double Grid::maxNeighbor(int x, int y)
{
    double m = 0;
    if(isInGrid(x-1, y) && grid[x-1][y] > m)
        m = grid[x-1][y];
    if(isInGrid(x+1, y) && grid[x+1][y] > m)
        m = grid[x+1][y];
    if(isInGrid(x, y-1) && grid[x][y-1] > m)
        m = grid[x][y-1];
    if(isInGrid(x, y+1) && grid[x][y+1] > m)
        m = grid[x][y+1];
    return m;
}

Grid operator+(const Grid& a, const Grid& b)
{
    Grid res(a);
    res += b;
    return res;
}

Grid operator-(const Grid& a, const Grid& b)
{
    Grid res(a);
    res -= b;
    return res;
}

Grid operator*(const double& scalar, const Grid& g)
{
    Grid copy;
    valarray<double> multiplier = valarray<double>(scalar, World::NB_COL);
    copy.grid = multiplier * g.grid;
    return copy;
}
