#pragma once
#include "BaseClass.h"
class pt_Dragon :
    public Pet
{
public:
    pt_Dragon(string name, string type, int HP, int MP, int ATK, int DEF, int SPD);
    ~pt_Dragon();

    // 重写父类的虚函数printPet，打印宠物的信息
    void printPet();

    // 重写父类的虚函数setName，设置宠物的名字
    void setName(string name);

    // 重写父类的虚函数setType，设置宠物的类型
    void setType(string type);

    // 重写父类的虚函数setHP，设置宠物的生命值
    void setHP(int HP);

    // 重写父类的虚函数setMP，设置宠物的魔法值
    void setMP(int MP);

    // 重写父类的虚函数setATK，设置宠物的攻击力
    void setATK(int ATK);

    // 重写父类的虚函数setDEF，设置宠物的防御力
    void setDEF(int DEF);

    // 重写父类的虚函数setSPD，设置宠物的速度
    void setSPD(int SPD);

    // // 重写父类的虚函数setCRI，设置宠物的暴击率
    // void setCRI(int CRI);

    // // 重写父类的虚函数setLV，设置宠物的等级
    // void setLV(int LV);

    // // 重写父类的虚函数setEXP，设置宠物的经验值
    // void setEXP(int EXP);

    // // 重写父类的虚函数setEXP_Need，设置宠物的升级所需经验值
    // void setEXP_Need(int EXP_Need);

    // 重写父类的虚函数getName，获取宠物的名字
    string getName();

    // 重写父类的虚函数getType，获取宠物的类型
    string getType();

    // 重写父类的虚函数getHP，获取宠物的生命值
    int getHP();

    // 重写父类的虚函数getMP，获取宠物的魔法值
    int getMP();

    // 重写父类的虚函数getATK，获取宠物的攻击力
    int getATK();

    // 重写父类的虚函数getDEF，获取宠物的防御力
    int getDEF();

    // 重写父类的虚函数getSPD，获取宠物的速度
    int getSPD();

    // // 重写父类的虚函数getCRI，获取宠物的暴击率
    // int getCRI();

    // // 重写父类的虚函数getLV，获取宠物的等级
    // int getLV();


    // // 重写父类的虚函数getEXP，获取宠物的经验值
    // int getEXP();

    // // 重写父类的虚函数getEXP_Need，获取宠物的升级所需经验值
    // int getEXP_Need();
    


};

