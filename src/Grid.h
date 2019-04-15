#ifndef Grid_HPP
#define Grid_HPP

#include <valarray>
//#include "World.h"

using namespace std;

class Grid final
{
public:
    Grid(int nbCol, int nbRow);
    Grid(int nbCol, int nbRow, const Grid& g);
    Grid(int nbCol, int nbRow, double seed, int x, int y, double coef = 0.8);

    Grid& operator=(const Grid& other);

    double& operator()(int x, int y);
    Grid* operator+=(const Grid& other);
    Grid* operator-=(const Grid& other);

    bool isInGrid(int x, int y);

private:
    int nbCol;
    int nbRow;
    std::valarray<std::valarray<double>> grid;

    // private methods
    void propagate(int x, int y, double coef);
    void tryDiffuse(int xt, int yt, double coef);
    double maxNeighbor(int x, int y);

    // friendship
    friend Grid operator*(const double& scalar, const Grid& g);
};

Grid operator+(const Grid& a, const Grid& b);
Grid operator-(const Grid& a, const Grid& b);
Grid operator*(const double& scalar, const Grid& g);

#endif // Grid_HPP