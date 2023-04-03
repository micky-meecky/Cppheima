#include "sk_WaterShield.h"

WaterShield::WaterShield(string name, string type, int damage, string description, int priority) : Skill(name, type, damage, description, priority)
{
    // ��д����Ĺ��캯��
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

void WaterShield::setDamage(int damage)
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

void WaterShield::setDescription(string description)
{
    this->description = description;
}

void WaterShield::SetPriority(int priority)
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
    cout << "�������֣�" << this->name << endl;
    cout << "�������ͣ�" << this->type << endl;
    cout << "�����˺���" << this->damage << endl;
    cout << "����������" << this->description << endl;
    cout << "�������ȼ���" << this->priority << endl;
}

