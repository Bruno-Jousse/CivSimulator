#ifndef HEALTHBAR_H
#define HEALTHBAR_H

namespace model{

class Healthbar
{
private:
    int hpMax;
    int hp;

public:
    Healthbar(int hpMax, bool isActive=true);
    int getHp();
    void setHp(int hp);

};

#endif // HEALTHBAR_H
}
