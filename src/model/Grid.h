#ifndef Grid_HPP
#define Grid_HPP

#include <valarray>
#include <queue>

#include "World.h"

namespace model{

class Grid final
{
public:
    Grid();
    Grid(const Grid& g);
    Grid(double seed, int x, int y, double coef = 0.8);

    double& operator()(int x, int y);

private:
    std::valarray<std::valarray<double>> grid;
    std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> fifo;

    // private methods
    void propagate(int x, int y, double coef);
    bool isInGrid(int x, int y);
    void tryDiffuse(int xt, int yt, double coef);
    double maxNeighbor(int x, int y);

    // friendship
    friend Grid operator+(const Grid& a, const Grid& b);
    friend Grid operator*(const double& scalar, const Grid& g);
};

Grid operator+(const Grid& a, const Grid& b);
Grid operator*(const double& scalar, const Grid& g);

}

#endif // Grid_HPP