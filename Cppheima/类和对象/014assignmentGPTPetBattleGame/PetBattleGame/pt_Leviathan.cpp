#include "pt_Leviathan.h"

pt_Leviathan::pt_Leviathan(string name, string type, int HP, int MP, int ATK, int DEF, int SPD) : Pet(name, type, HP, MP, ATK, DEF, SPD)
{
    // 重写父类的构造函数
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->MP = MP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->SPD = SPD;
}

pt_Leviathan::~pt_Leviathan()
{
}

void pt_Leviathan::printPet()
{
    cout << "宠物的名字：" << this->getName() << endl;
    cout << "宠物的类型：" << this->getType() << endl;
    cout << "宠物的生命值：" << this->getHP() << endl;
    cout << "宠物的魔法值：" << this->getMP() << endl;
    cout << "宠物的攻击力：" << this->getATK() << endl;
    cout << "宠物的防御力：" << this->getDEF() << endl;
    cout << "宠物的速度：" << this->getSPD() << endl;
}

void pt_Leviathan::setName(string name)
{
    this->name = name;
}

void pt_Leviathan::setType(string type)
{
    this->type = type;
}

void pt_Leviathan::setHP(int HP)
{
    //检测生命值是否合法，0-1000
    if (HP >= 0 && HP <= 1000)
    {
        this->HP = HP;
    }
    else
    {
        cout << "生命值不合法！" << endl;
    }
}

void pt_Leviathan::setMP(int MP)
{
    //检测魔法值是否合法，0-1000
    if (MP >= 0 && MP <= 1000)
    {
        this->MP = MP;
    }
    else
    {
        cout << "魔法值不合法！" << endl;
    }
}

void pt_Leviathan::setATK(int ATK)
{
    //检测攻击力是否合法，0-1000
    if (ATK >= 0 && ATK <= 1000)
    {
        this->ATK = ATK;
    }
    else
    {
        cout << "攻击力不合法！" << endl;
    }
}

void pt_Leviathan::setDEF(int DEF)
{
    //检测防御力是否合法，0-1000
    if (DEF >= 0 && DEF <= 1000)
    {
        this->DEF = DEF;
    }
    else
    {
        cout << "防御力不合法！" << endl;
    }
}

void pt_Leviathan::setSPD(int SPD)
{
    //检测速度是否合法，0-1000
    if (SPD >= 0 && SPD <= 1000)
    {
        this->SPD = SPD;
    }
    else
    {
        cout << "速度不合法！" << endl;
    }
}

string pt_Leviathan::getName()
{
    return this->name;
}

string pt_Leviathan::getType()
{
    return this->type;
}

int pt_Leviathan::getHP()
{
    return this->HP;
}

int pt_Leviathan::getMP()
{
    return this->MP;
}

int pt_Leviathan::getATK()
{
    return this->ATK;
}

int pt_Leviathan::getDEF()
{
    return this->DEF;
}

int pt_Leviathan::getSPD()
{
    return this->SPD;
}

 
