#include "sk_Heal.h"

Heal::Heal(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
{
    // ��д����Ĺ��캯��
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

void Heal::setDamage(int damage)
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

void Heal::setDescription(string description)
{
    this->description = description;
}

void Heal::SetPriority(int priority)
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




