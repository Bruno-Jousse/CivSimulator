#ifndef RandomManager_HPP
#define RandomManager_HPP

/**
 * \class RandomManager
 * \brief It is a singleton.
 * It is the only way to have access to random
 * numbers in the program.
 */
class RandomManager
{
public:
    virtual ~RandomManager();
    static RandomManager& getInstance();

    double getUniform01() const;
    double getGaussian(double mu, double sigma) const;

    // do not use default constructors
    RandomManager(RandomManager const& r) = delete;
protected:

private:
    RandomManager(); // private constructor
};

#endif // RandomManager_HPP