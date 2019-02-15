#ifndef RandomManager_HPP
#define RandomManager_HPP
#include <random>
#include <cmath>
#include <iostream>
#include <time.h>
#include<functional>

#define VAL_MAX 100000
using namespace std;

namespace model{

/**
 * \class RandomManager
 * \brief It is a singleton.
 * It is the only way to have access to random
 * numbers in the program.
 */


class RandomManager
{
public:
    function<double()> distribReal;
    function<int()> distribInt;
    virtual ~RandomManager();

    int getRandomInt(int max=VAL_MAX);
    double getRandomDouble();
    double getUniform01() const;
    double getGaussian(double mu, double sigma) const;

    static RandomManager& getInstance();
    // do not use default constructors
    RandomManager(RandomManager const& r) = delete;
protected:

private:
    mt19937::result_type seed;

    RandomManager(); // private constructor
};

}
#endif // RandomManager_HPP
