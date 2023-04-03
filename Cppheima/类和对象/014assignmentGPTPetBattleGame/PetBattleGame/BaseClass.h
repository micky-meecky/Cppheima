#pragma once
#include <iostream>
#include <string>

using namespace std;


// 设计一个Skill类，具有以下属性和方法：
// 	属性：名字、类型、伤害值、技能描述、类型包括：攻击、防御、辅助
//  type： attack，defense，support
// 	方法：构造函数、析构函数、获取和设置属性方法、打印技能属性方法

class Skill	//技能类
{
	friend class Fireball;	//Fireball类是Skill类的友元类, 因为Fireball类中有printSkill()方法需要访问Skill类的私有属性
	friend class WaterShield;	//WaterShield类是Skill类的友元类, 因为WaterShield类中有printSkill()方法需要访问Skill类的私有属性
	friend class Heal;	//Heal类是Skill类的友元类, 因为Heal类中有printSkill()方法需要访问Skill类的私有属性

public:
	//构造函数的声明
	//构造函数的参数中 name type damage description分别表示技能的名字、类型、伤害值、技能描述
	Skill(string name, string type, int damage, string description, int priority);
	//析构函数的声明
	~Skill();

	//获取和设置属性方法的声明
	virtual	void setName(string name) = 0;
	virtual void setType(string type) = 0;
	virtual void setDamage(int damage) = 0;
	virtual void setDescription(string description) = 0;
	virtual void setPriority(int priority) = 0;

	//获取属性方法的声明
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int getDamage() = 0;
	virtual string getDescription() = 0;
	virtual int getPriority() = 0;
	virtual void printSkill() = 0;
private:
	//属性的声明
	string name;
	string type;
	int damage;
	string description;
	int priority;

};

// Pet 类
// 设计一个Pet类，具有以下属性和方法：
// 属性：名字、种类、生命值、攻击力、防御力、速度
// 方法：构造函数、析构函数、获取和设置属性方法、打印宠物属性方法
class Pet
{
	friend class Battle; // Battle类是Pet类的友元类, 因为Battle类中有startBattle()方法需要访问Pet类的私有属性

public:
	//构造函数的声明
	//构造函数的参数中 name type hp attack defense speed分别表示宠物的名字、种类、生命值、攻击力、防御力、速度
	Pet(string name, string type, int hp, int attack, int defense, int speed);
	//析构函数的声明
	~Pet();

	//获取和设置属性方法的声明
	virtual void setName(string name) = 0;
	virtual void setType(string type) = 0;
	virtual void setHp(int hp) = 0;
	virtual void setAttack(int attack) = 0;
	virtual void setDefense(int defense) = 0;
	virtual void setSpeed(int speed) = 0;

	//获取属性方法的声明
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int getHp() = 0;
	virtual int getAttack() = 0;
	virtual int getDefense() = 0;
	virtual int getSpeed() = 0;
	virtual void printPet() = 0;
private:
	//属性的声明
	string name;
	string type;
	int hp;
	int attack;
	int defense;
	int speed;
};

// 设计一个Battle类，实现宠物的战斗功能，具有以下属性和方法：
// 	属性：玩家拥有的宠物数组、当前宠物编号、战斗回合数
// 	方法：构造函数、析构函数、添加宠物方法、删除宠物方法、选择当前宠物方法、获取当前宠物方法、宠物战斗方法
class Battle
{
public:
	//构造函数的声明
	Battle();
	//析构函数的声明
	~Battle();

	//添加宠物方法的声明
	void addPet(Pet* pet);
	//删除宠物方法的声明
	void deletePet(int index);
	//选择当前宠物方法的声明
	void selectPet(int index);
	//获取当前宠物方法的声明
	Pet* getCurrentPet();
	//宠物战斗方法的声明
	void startBattle();
private:
	//属性的声明
	Pet* pets[10];	//玩家拥有的宠物数组
	int currentPetIndex;	//当前宠物编号
	int round;	//战斗回合数
};

