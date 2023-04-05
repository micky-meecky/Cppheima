#include "pt_Leviathan.h"

pt_Leviathan::pt_Leviathan(string name, string type, int HP, int MP, int ATK, int DEF, int SPD) : Pet(name, type, HP, MP, ATK, DEF, SPD)
{
    // ��д����Ĺ��캯��
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
    cout << "��������֣�" << this->getName() << endl;
    cout << "��������ͣ�" << this->getType() << endl;
    cout << "���������ֵ��" << this->getHP() << endl;
    cout << "�����ħ��ֵ��" << this->getMP() << endl;
    cout << "����Ĺ�������" << this->getATK() << endl;
    cout << "����ķ�������" << this->getDEF() << endl;
    cout << "������ٶȣ�" << this->getSPD() << endl;
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
    //�������ֵ�Ƿ�Ϸ���0-1000
    if (HP >= 0 && HP <= 1000)
    {
        this->HP = HP;
    }
    else
    {
        cout << "����ֵ���Ϸ���" << endl;
    }
}

void pt_Leviathan::setMP(int MP)
{
    //���ħ��ֵ�Ƿ�Ϸ���0-1000
    if (MP >= 0 && MP <= 1000)
    {
        this->MP = MP;
    }
    else
    {
        cout << "ħ��ֵ���Ϸ���" << endl;
    }
}

void pt_Leviathan::setATK(int ATK)
{
    //��⹥�����Ƿ�Ϸ���0-1000
    if (ATK >= 0 && ATK <= 1000)
    {
        this->ATK = ATK;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

void pt_Leviathan::setDEF(int DEF)
{
    //���������Ƿ�Ϸ���0-1000
    if (DEF >= 0 && DEF <= 1000)
    {
        this->DEF = DEF;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

void pt_Leviathan::setSPD(int SPD)
{
    //����ٶ��Ƿ�Ϸ���0-1000
    if (SPD >= 0 && SPD <= 1000)
    {
        this->SPD = SPD;
    }
    else
    {
        cout << "�ٶȲ��Ϸ���" << endl;
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

 
