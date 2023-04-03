#include "sk_WaterShield.h"

WaterShield::WaterShield(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
{
    // 重写父类的构造函数
    this->name = name;
    this->type = type;
    this->damage = damage;
    this->description = description;
}

WaterShield::~WaterShield()
{
}

void WaterShield::setName(string name)
{
    this->name = name;
}

void WaterShield::setType(string type)
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

void WaterShield::setDamage(int damage)
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

void WaterShield::setDescription(string description)
{
    this->description = description;
}

void WaterShield::SetPriority(int priority)
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

string WaterShield::getName()
{
    return this->name;
}

string WaterShield::getType()
{
    return this->type;
}

int WaterShield::getDamage()
{
    return this->damage;
}

string WaterShield::getDescription()
{
    return this->description;
}

int WaterShield::getPriority()
{
    return this->priority;
}


void WaterShield::printSkill()
{
    cout << "技能名字：" << this->name << endl;
    cout << "技能类型：" << this->type << endl;
    cout << "技能伤害：" << this->damage << endl;
    cout << "技能描述：" << this->description << endl;
    cout << "技能优先级：" << this->priority << endl;
}

