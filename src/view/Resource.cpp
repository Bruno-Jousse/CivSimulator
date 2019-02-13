/**
 * Project Untitled
 */


#include "Resource.h"

/**
 * Ressource implementation
 */
namespace view{

Resource::Resource(QColor color, int x, int y, int w, int h, int amount) : Entity(color, x, y, w, h), amount(amount){

}

Resource::Resource(int amount) : Entity(), amount(amount){

}

int Resource::getAmount(){
    return amount;
}

Resource::~Resource(){

}
}
