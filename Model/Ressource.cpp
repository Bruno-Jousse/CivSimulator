/**
 * Project Untitled
 */


#include "Ressource.h"

/**
 * Ressource implementation
 */

Ressource::Ressource(int amount, QColor color, int x, int y, int w, int h) : Figure(color, x, y, w, h), amount(amount){

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
