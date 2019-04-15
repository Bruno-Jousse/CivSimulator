#include "RandomManager.h"

#include <cmath>

RandomManager::RandomManager()
{
    seed = static_cast<unsigned int>(time(nullptr));
    distribReal = std::bind(uniform_real_distribution<double> (0.0, 1.0), mt19937(seed));
    distribInt = std::bind(uniform_int_distribution<int> (0, VAL_MAX), mt19937(seed));
}

RandomManager::~RandomManager()
{}

RandomManager& RandomManager::getInstance()
{
    static RandomManager instance;
    return instance;
}

int RandomManager::getRandomInt(int max){
    return distribInt()%max;
}

double RandomManager::getRandomDouble(){
    return distribReal();
}

double RandomManager::getUniform01() const
{
    // TODO : use the PRNG
    return 0.5;
}

double RandomManager::getGaussian(double mu, double sigma) const
{
    static bool needToGenerate = true;
    static double x1 = 0.0;
    static double x2 = 0.0;

    if(needToGenerate)
    {
        x1 = getUniform01();
        x2 = getUniform01();
    }
    double n1 = cos(2*M_PI*x2)*sqrt(-2*log(x1));
    double n2 = sin(2*M_PI*x2)*sqrt(-2*log(x1));
    double nb1 = sigma*n1 + mu;
    double nb2 = sigma*n2 + mu;
    if(needToGenerate)
    {
        needToGenerate = false;
        return nb1;
    }
    needToGenerate = true;
    return nb2;
}