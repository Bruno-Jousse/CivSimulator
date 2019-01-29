#include "Headquarter.h"

// global constants
const int Headquarter::STARTING_HP = 50;

Headquarter::Headquarter(int x, int y): Entity(x, y), hp(Headquarter::STARTING_HP)
{}

Headquarter::~Headquarter()
{}
