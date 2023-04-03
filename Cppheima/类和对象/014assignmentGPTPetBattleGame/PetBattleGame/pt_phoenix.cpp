#include "pt_phoenix.h"

phoenix::phoenix(string name, string type, int HP, int MP, int ATK, int DEF, int SPD) : Pet(name, type, HP, MP, ATK, DEF, SPD)
{
    // 重写父类的构造函数
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
    // 重写父类的析构函数
}

// 重写父类的虚函数printPet，打印宠物的信息
void phoenix::printPet()
{
    cout << "宠物名字：" << this->name << endl;
    cout << "宠物类型：" << this->type << endl;
    cout << "宠物生命值：" << this->HP << endl;
    cout << "宠物魔法值：" << this->MP << endl;
    cout << "宠物攻击力：" << this->ATK << endl;
    cout << "宠物防御力：" << this->DEF << endl;
    cout << "宠物速度：" << this->SPD << endl;
}

// 重写父类的虚函数setName，设置宠物的名字
void phoenix::setName(string name)
{
    this->name = name;
}

// 重写父类的虚函数setType，设置宠物的类型
// 类型目前只有五种：火、水、风、土、金
void phoenix::setType(string type)
{
    // 检查类型是否合法，写火、水、风、土、金的英语词汇
    if (type == "fire" || type == "water" || type == "wind" || type == "earth" || type == "gold")
    {
        this->type = type;
    }
    else
    {
        cout << "类型不合法！" << endl;
    }
}

// 重写父类的虚函数setHP，设置宠物的生命值，因为是火属性，所以生命值最大为100
void phoenix::setHP(int HP)
{
    //检测生命值是否合法，0-100
    if (HP >= 0 && HP <= 100)
    {
        this->HP = HP;
    }
    else
    {
        cout << "生命值不合法！" << endl;
    }
}

// 重写父类的虚函数setMP，设置宠物的魔法值，因为是火属性，所以魔法值最大为100
void phoenix::setMP(int MP)
{
    //检测魔法值是否合法，0-100
    if (MP >= 0 && MP <= 100)
    {
        this->MP = MP;
    }
    else
    {
        cout << "魔法值不合法！" << endl;
    }
}

// 重写父类的虚函数setATK，设置宠物的攻击力，因为是火属性，所以攻击力最大为200
void phoenix::setATK(int ATK)
{
    //检测攻击力是否合法，0-200
    if (ATK >= 0 && ATK <= 200)
    {
        this->ATK = ATK;
    }
    else
    {
        cout << "攻击力不合法！" << endl;
    }
}

// 重写父类的虚函数setDEF，设置宠物的防御力，因为是火属性，所以防御力最大为80
void phoenix::setDEF(int DEF)
{
    //检测防御力是否合法，0-80
    if (DEF >= 0 && DEF <= 80)
    {
        this->DEF = DEF;
    }
    else
    {
        cout << "防御力不合法！" << endl;
    }
}

// 重写父类的虚函数setSPD，设置宠物的速度，因为是火属性，所以速度最大为150
void phoenix::setSPD(int SPD)
{
    //检测速度是否合法，0-150
    if (SPD >= 0 && SPD <= 150)
    {
        this->SPD = SPD;
    }
    else
    {
        cout << "速度不合法！" << endl;
    }
}

// 重写父类的虚函数getName，获取宠物的名字
string phoenix::getName()
{
    return this->name;
}

// 重写父类的虚函数getType，获取宠物的类型
string phoenix::getType()
{
    return this->type;
}

// 重写父类的虚函数getHP，获取宠物的生命值
int phoenix::getHP()
{
    return this->HP;
}

// 重写父类的虚函数getMP，获取宠物的魔法值
int phoenix::getMP()
{
    return this->MP;
}

// 重写父类的虚函数getATK，获取宠物的攻击力
int phoenix::getATK()
{
    return this->ATK;
}

// 重写父类的虚函数getDEF，获取宠物的防御力
int phoenix::getDEF()
{
    return this->DEF;
}

// 重写父类的虚函数getSPD，获取宠物的速度
int phoenix::getSPD()
{
    return this->SPD;
}








