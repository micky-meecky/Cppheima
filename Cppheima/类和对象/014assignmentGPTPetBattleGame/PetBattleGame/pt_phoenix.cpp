#include "pt_phoenix.h"

phoenix::phoenix(string name, string type, int HP, int MP, int ATK, int DEF, int SPD) : Pet(name, type, HP, MP, ATK, DEF, SPD)
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

phoenix::~phoenix()
{
    // ��д�������������
}

// ��д������麯��printPet����ӡ�������Ϣ
void phoenix::printPet()
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
void phoenix::setName(string name)
{
    this->name = name;
}

// ��д������麯��setType�����ó��������
// ����Ŀǰֻ�����֣���ˮ���硢������
void phoenix::setType(string type)
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
void phoenix::setHP(int HP)
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
void phoenix::setMP(int MP)
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

// ��д������麯��setATK�����ó���Ĺ���������Ϊ�ǻ����ԣ����Թ��������Ϊ200
void phoenix::setATK(int ATK)
{
    //��⹥�����Ƿ�Ϸ���0-200
    if (ATK >= 0 && ATK <= 200)
    {
        this->ATK = ATK;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

// ��д������麯��setDEF�����ó���ķ���������Ϊ�ǻ����ԣ����Է��������Ϊ80
void phoenix::setDEF(int DEF)
{
    //���������Ƿ�Ϸ���0-80
    if (DEF >= 0 && DEF <= 80)
    {
        this->DEF = DEF;
    }
    else
    {
        cout << "���������Ϸ���" << endl;
    }
}

// ��д������麯��setSPD�����ó�����ٶȣ���Ϊ�ǻ����ԣ������ٶ����Ϊ150
void phoenix::setSPD(int SPD)
{
    //����ٶ��Ƿ�Ϸ���0-150
    if (SPD >= 0 && SPD <= 150)
    {
        this->SPD = SPD;
    }
    else
    {
        cout << "�ٶȲ��Ϸ���" << endl;
    }
}

// ��д������麯��getName����ȡ���������
string phoenix::getName()
{
    return this->name;
}

// ��д������麯��getType����ȡ���������
string phoenix::getType()
{
    return this->type;
}

// ��д������麯��getHP����ȡ���������ֵ
int phoenix::getHP()
{
    return this->HP;
}

// ��д������麯��getMP����ȡ�����ħ��ֵ
int phoenix::getMP()
{
    return this->MP;
}

// ��д������麯��getATK����ȡ����Ĺ�����
int phoenix::getATK()
{
    return this->ATK;
}

// ��д������麯��getDEF����ȡ����ķ�����
int phoenix::getDEF()
{
    return this->DEF;
}

// ��д������麯��getSPD����ȡ������ٶ�
int phoenix::getSPD()
{
    return this->SPD;
}








