#include "sk_Heal.h"

Heal::Heal(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
{
    // 重写父类的构造函数
    this->name = name;
    this->type = type;
    this->damage = damage;
    this->description = description;
}

Heal::~Heal()
{
}

void Heal::setName(string name)
{
    this->name = name;
}

void Heal::setType(string type)
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

void Heal::setDamage(int damage)
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

void Heal::setDescription(string description)
{
    this->description = description;
}

void Heal::SetPriority(int priority)
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

string Heal::getName()
{
    return this->name;
}

string Heal::getType()
{
    return this->type;
}

int Heal::getDamage()
{
    return this->damage;
}

string Heal::getDescription()
{
    return this->description;
}

int Heal::getPriority()
{
        return this->priority;
}




