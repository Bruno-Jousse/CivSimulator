#include "Figure.h"

/**
 * Figure implementation
 */

QColor Figure::getColor() const
{
    return color;
}

void Figure::setColor(const QColor &value)
{
    color = value;
}

int Figure::getX() const
{
    return x;
}

void Figure::setX(int value)
{
    x = value;
}

int Figure::getY() const
{
    return y;
}

void Figure::setY(int value)
{
    y = value;
}

int Figure::getW() const
{
    return w;
}

void Figure::setW(int value)
{
    w = value;
}

int Figure::getH() const
{
    return h;
}

void Figure::setH(int value)
{
    h = value;
}

Figure::Figure(QColor color, int x, int y, int w, int h) : color(color), x(x), y(y), w(w), h(h) {

}

Figure::~Figure(){

}
