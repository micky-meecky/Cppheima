#include "sk_Fireball.h"

Fireball::Fireball(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
{
    // 重写父类的构造函数
    this->name = name;
    this->type = type;
    this->damage = damage;
    this->description = description;
}

Fireball::~Fireball()
{
}

void Fireball::setName(string name)
{
    this->name = name;
}

void Fireball::setType(string type)
{
    //  type： attack，defense，support
    // 判断type是不是三种类型中的一种
    if (type != "attack" && type != "defense" && type != "support")
    {
        // 如果不是三种类型中的一种，就抛出异常
        throw "技能类型不是attack，defense，support中的一种";
        return;
    }
    else
    {
        this->type = type;
    }
}

void Fireball::setDamage(int damage)
{
    //检测伤害值是否在-100 - 100之间
    if (damage < -100 || damage > 100)
    {
        //如果不在-100 - 100之间，就抛出异常
        throw "伤害值不在-100 - 100之间";
        return;
    }
    else
    {
        this->damage = damage;
    }
}

void Fireball::setDescription(string description)
{
    this->description = description;
}

void Fireball::SetPriority(int priority)
{
    //检测优先级是否在1-10之间
    if (priority < 1 || priority > 10)
    {
        //如果不在1-10之间，就抛出异常
        throw "优先级不在1-10之间";
        return;
    }
    else
    {
        this->priority = priority;
    }
}

string Fireball::getName()
{
    return this->name;
}

string Fireball::getType()
{
    return this->type;
}

int Fireball::getDamage()
{
    return this->damage;
}

string Fireball::getDescription()
{
    return this->description;
}

int Fireball::getPriority()
{
        return this->priority;
}

void Fireball::printSkill()
{
    cout << "技能名字：" << this->name << endl;
    cout << "技能类型：" << this->type << endl;
    cout << "技能伤害：" << this->damage << endl;
    cout << "技能描述：" << this->description << endl;
}

// Path: Cppheima\类和对象\014assignmentGPTPetBattleGame\PetBattleGame\Game.cpp


