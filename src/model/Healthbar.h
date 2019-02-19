#ifndef HEALTHBAR_H
#define HEALTHBAR_H

namespace model{

class Healthbar
{
private:
    int hpMax;
    int hp;
    bool isActive;

public:
    Healthbar(int hpMax, bool isActive=true);
    int getHp();
    void setHp(int hp);
    bool getIsActive();
    void setIsActive(bool a);
};

#endif // HEALTHBAR_H
}
