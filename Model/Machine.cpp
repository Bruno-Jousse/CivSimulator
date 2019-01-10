/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */

Machine::Machine(int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : hp(hp), ms(ms), wearMax(wearMax), Agent(color, x, y, w, h){
    wear=0;
}


/**
 * @param int
 * @param int
 * @return void
 */
void Machine::moveTo(int x, int y) {
    return;
}

int Machine::getHp(){
    return hp;
}
