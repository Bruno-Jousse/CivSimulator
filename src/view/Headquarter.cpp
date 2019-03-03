/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

namespace view{


Headquarter::Headquarter(QColor color, int x, int y, int w, int h) : Building(color){
    data = new model::Headquarter(x, y, w, h);

    healthbar.getData()->setHp(data->STARTING_HP);
    healthbar.getData()->setW(w);
    data->setHealthbar(healthbar.getData());
    healthbar.setParentItem(this);

    metalStockBar = Healthbar(Qt::gray, data->MAX_STOCK_METAL, 0, h-10, w);
    data->setMetalStockBar(metalStockBar.getData());
    metalStockBar.setParentItem(this);

}

void Headquarter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Entity::paint(painter, option, widget);
    painter->setBrush(Qt::black);
    painter->drawText(getQRectF(), Qt::AlignCenter, "HQ");
}
}
