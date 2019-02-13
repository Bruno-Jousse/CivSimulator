#ifndef Metal_HPP
#define Metal_HPP

#include "Resource.h"

namespace model{

class Metal: public Resource
{
public:
    Metal(int x, int y, int quantity);
    virtual ~Metal();

    void simulate(unsigned date) override;

protected:

private:

};

}
#endif // Metal_HPP
