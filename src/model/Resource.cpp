#include "Resource.h"

namespace model{

Resource::Resource(int x, int y, int quantity): Entity(x,y), quantity(quantity)
{}

Resource::~Resource()
{}


int Resource::takeRessources(int amount){
    if(amount > this->amount){
        amount = this->amount;
    }

    this->amount -= amount;
    return amount;
}
}
