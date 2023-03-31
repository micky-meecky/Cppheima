#pragma once
#include "BaseClass.h"
#include <iostream>
#include <string>


using namespace std;

class Fireball :
    public Skill
{
public:
    // 重写父类的构造函数
    Fireball(string name, string type, int damage, string description);
    ~Fireball();

    // 重写父类的虚函数printSkill，打印技能的信息
    void printSkill();

    // 重写父类的虚函数setName，设置技能的名字
    void setName(string name);

    // 重写父类的虚函数setType，设置技能的类型
    void setType(string type);


    // 重写父类的虚函数setDamage，设置技能的伤害值
    void setDamage(int damage);

    // 重写父类的虚函数setDescription，设置技能的描述
    void setDescription(string description);


    // 重写父类的虚函数getName，获取技能的名字
    string getName();


    // 重写父类的虚函数getType，获取技能的类型
    string getType();


    // 重写父类的虚函数getDamage，获取技能的伤害值
    int getDamage();


    // 重写父类的虚函数getDescription，获取技能的描述
    string getDescription();


    // 重写父类的虚函数printSkill，打印技能的信息
    void printSkill();

private:

};

