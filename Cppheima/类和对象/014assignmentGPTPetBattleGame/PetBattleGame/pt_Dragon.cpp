#include "pt_Dragon.h"

pt_Dragon::pt_Dragon(string name, string type, int HP, int MP, int ATK, int DEF, int SPD) : Pet(name, type, HP, MP, ATK, DEF, SPD)
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

pt_Dragon::~pt_Dragon()
{
    // ��д�������������
}

// ��д������麯��printPet����ӡ�������Ϣ
void pt_Dragon::printPet()
{
    cout << "�������֣�" << this->name << endl;
    cout << "�������ͣ�" << this->type << endl;
    cout << "��������ֵ��" << this->HP << endl;
    cout << "����ħ��ֵ��" << this->MP << endl;
    cout << "���﹥������" << this->ATK << endl;
    cout << "�����������" << this->DEF << endl;
    cout << "�����ٶȣ�" << this->SPD << endl;
}

// ��д������麯��setName�����ó��������
void pt_Dragon::setName(string name)
{
    this->name = name;
}

// ��д������麯��setType�����ó��������
// ����Ŀǰֻ�����֣���ˮ���硢������
void pt_Dragon::setType(string type)
{
    // ��������Ƿ�Ϸ���д��ˮ���硢�������Ӣ��ʻ�
    if (type == "fire" || type == "water" || type == "wind" || type == "earth" || type == "gold")
    {
        this->type = type;
    }
    else
    {
        cout << "���Ͳ��Ϸ���" << endl;
    }
}

// ��д������麯��setHP�����ó��������ֵ����Ϊ�ǻ����ԣ���������ֵ���Ϊ100
void pt_Dragon::setHP(int HP)
{
    //�������ֵ�Ƿ�Ϸ���0-100
    if (HP >= 0 && HP <= 100)
    {
        this->HP = HP;
    }
    else
    {
        cout << "����ֵ���Ϸ���" << endl;
    }
}

// ��д������麯��setMP�����ó����ħ��ֵ����Ϊ�ǻ����ԣ�����ħ��ֵ���Ϊ100
void pt_Dragon::setMP(int MP)
{
    //���ħ��ֵ�Ƿ�Ϸ���0-100
    if (MP >= 0 && MP <= 100)
    {
        this->MP = MP;
    }
    else
    {
        cout << "ħ��ֵ���Ϸ���" << endl;
    }
}

// ��д������麯��setATK�����ó���Ĺ���������Ϊ�ǻ����ԣ����Թ��������Ϊ100
void pt_Dragon::setATK(int ATK)
{
    //��⹥�����Ƿ�Ϸ���0-100
    if (ATK >= 0 && ATK <= 100)
    {
        this->ATK = ATK;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

// ��д������麯��setDEF�����ó���ķ���������Ϊ�ǻ����ԣ����Է��������Ϊ100
void pt_Dragon::setDEF(int DEF)
{
    //���������Ƿ�Ϸ���0-100
    if (DEF >= 0 && DEF <= 100)
    {
        this->DEF = DEF;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

// ��д������麯��setSPD�����ó�����ٶȣ���Ϊ�ǻ����ԣ������ٶ����Ϊ100
void pt_Dragon::setSPD(int SPD)
{
    //����ٶ��Ƿ�Ϸ���0-100
    if (SPD >= 0 && SPD <= 100)
    {
        this->SPD = SPD;
    }
    else
    {
        cout << "�ٶȲ��Ϸ���" << endl;
    }
}

// ��д������麯��getName����ȡ���������
string pt_Dragon::getName()
{
    return this->name;
}

// ��д������麯��getType����ȡ���������
string pt_Dragon::getType()
{
    return this->type;
}

// ��д������麯��getHP����ȡ���������ֵ
int pt_Dragon::getHP()
{
    return this->HP;
}

// ��д������麯��getMP����ȡ�����ħ��ֵ
int pt_Dragon::getMP()
{
    return this->MP;
}

// ��д������麯��getATK����ȡ����Ĺ�����
int pt_Dragon::getATK()
{
    return this->ATK;
}

// ��д������麯��getDEF����ȡ����ķ�����
int pt_Dragon::getDEF()
{
    return this->DEF;
}

// ��д������麯��getSPD����ȡ������ٶ�
int pt_Dragon::getSPD()
{
    return this->SPD;
}





