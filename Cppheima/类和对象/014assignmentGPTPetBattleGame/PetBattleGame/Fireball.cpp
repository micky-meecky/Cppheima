#include "Fireball.h"

Fireball::Fireball(string name, string type, int damage, string description) : Skill(name, type, damage, description)
{
    // ��д����Ĺ��캯��
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
    cout << "�������֣�" << this->name << endl;
    cout << "�������ͣ�" << this->type << endl;
    cout << "�����˺���" << this->damage << endl;
    cout << "����������" << this->description << endl;
}

// Path: Cppheima\��Ͷ���\014assignmentGPTPetBattleGame\PetBattleGame\Game.cpp


