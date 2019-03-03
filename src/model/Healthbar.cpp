#include "Healthbar.h"

namespace model{

Healthbar::Healthbar(int hpMax, bool isActive) : hpMax(hpMax), hp(hpMax)
{

}

int Healthbar::getHp(){
    return hp;
}

void Healthbar::setHp(int hp){
    this->hp = hp;
}

}
