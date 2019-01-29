/**
 * Project Untitled
 */


#include "Ressource.h"

/**
 * Ressource implementation
 */

Ressource::Ressource(QColor color, int x, int y, int w, int h, int amount) : Entity(color, x, y, w, h), amount(amount){

}

Ressource::Ressource(int amount) : Entity(), amount(amount){

}

int Ressource::takeRessources(int amount){
    if(amount > this->amount){
        amount = this->amount;
    }

    this->amount -= amount;
    return amount;
}

int Ressource::getAmount(){
    return amount;
}

Ressource::~Ressource(){

}
