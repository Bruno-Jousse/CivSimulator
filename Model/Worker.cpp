/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */

Worker::Worker(int metalStockMax, bool mustMine, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : metalStockMax(metalStockMax), mustMine(mustMine), Machine(hp, ms, wearMax, color, x, y, w, h) {

}

/**
 * @param Metal
 * @return void
 */
void Worker::mine(Ressource& rs) {
    return;
}
