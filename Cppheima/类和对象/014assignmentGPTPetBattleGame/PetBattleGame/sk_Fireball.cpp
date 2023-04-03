#include "sk_Fireball.h"

Fireball::Fireball(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
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
    //  type�� attack��defense��support
    // �ж�type�ǲ������������е�һ��
    if (type != "attack" && type != "defense" && type != "support")
    {
        // ����������������е�һ�֣����׳��쳣
        throw "�������Ͳ���attack��defense��support�е�һ��";
        return;
    }
    else
    {
        this->type = type;
    }
}

void Fireball::setDamage(int damage)
{
    //����˺�ֵ�Ƿ���-100 - 100֮��
    if (damage < -100 || damage > 100)
    {
        //�������-100 - 100֮�䣬���׳��쳣
        throw "�˺�ֵ����-100 - 100֮��";
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
    //������ȼ��Ƿ���1-10֮��
    if (priority < 1 || priority > 10)
    {
        //�������1-10֮�䣬���׳��쳣
        throw "���ȼ�����1-10֮��";
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
    cout << "�������֣�" << this->name << endl;
    cout << "�������ͣ�" << this->type << endl;
    cout << "�����˺���" << this->damage << endl;
    cout << "����������" << this->description << endl;
}

// Path: Cppheima\��Ͷ���\014assignmentGPTPetBattleGame\PetBattleGame\Game.cpp


