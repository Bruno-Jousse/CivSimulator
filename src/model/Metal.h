#ifndef Metal_HPP
#define Metal_HPP

#include "Resource.h"

class Metal: public Resource
{
public:
    Metal(int x, int y, int quantity);
    virtual ~Metal();

    void simulate(unsigned date) override;

protected:

private:

};

#endif // Metal_HPP