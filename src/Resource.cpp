/**
 * Project Untitled
 */


#include "Resource.h"

/**
 * Ressource implementation
 */

Resource::Resource(QColor color, int x, int y, int amount) : Entity(color, x, y), amount(amount){

}

int Resource::takeResources(int amount){
    if(amount > this->amount){
        amount = this->amount;
    }

    this->amount -= amount;
    return amount;
}

int Resource::getAmount(){
    return amount;
}

Resource::~Resource(){

}
