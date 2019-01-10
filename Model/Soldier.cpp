/**
 * Project Untitled
 */


#include "Soldier.h"

/**
 * Soldier implementation
 */

Soldier::Soldier(int dmg, bool mustAttack, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : dmg(dmg), mustAttack(mustAttack), Machine(hp, ms, wearMax, color, x, y, w, h){

}
/**
 * @param Agent
 * @return void
 */
void Soldier::attack(Machine&){
    return;
}

void Soldier::attack(Building&){
    return;
}
