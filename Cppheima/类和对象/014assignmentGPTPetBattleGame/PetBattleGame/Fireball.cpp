#include "Fireball.h"

Fireball::Fireball(string name, string type, int damage, string description) : Skill(name, type, damage, description)
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
    this->type = type;
}

void Fireball::setDamage(int damage)
{
    this->damage = damage;
}

void Fireball::setDescription(string description)
{
    this->description = description;
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

void Fireball::printSkill()
{
    cout << "技能名字：" << this->name << endl;
    cout << "技能类型：" << this->type << endl;
    cout << "技能伤害：" << this->damage << endl;
    cout << "技能描述：" << this->description << endl;
}

// Path: Cppheima\类和对象\014assignmentGPTPetBattleGame\PetBattleGame\Game.cpp


