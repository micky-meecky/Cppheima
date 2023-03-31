/*这是一份来自ChatGPT布置的一个关于类与对象中多态部分的作业*/

/*

背景：在一个游戏中，玩家需要通过不同的宠物进行战斗，每个宠物都有不同的属性和技能，玩家需要根据宠物的特点选择最佳的宠物进行战斗。请使用类和对象的多态特性，设计一个宠物系统。

要求：

设计一个Pet类，具有以下属性和方法：
	属性：名字、种类、生命值、攻击力、防御力、速度
	方法：构造函数、析构函数、获取和设置属性方法、打印宠物属性方法
设计一个Skill类，具有以下属性和方法：
	属性：名字、类型、伤害值、技能描述
	方法：构造函数、析构函数、获取和设置属性方法、打印技能属性方法
设计一个Battle类，实现宠物的战斗功能，具有以下属性和方法：
	属性：玩家拥有的宠物数组、当前宠物编号、战斗回合数
	方法：构造函数、析构函数、添加宠物方法、删除宠物方法、选择当前宠物方法、获取当前宠物方法、宠物战斗方法
使用多态特性，设计宠物的攻击和防御方法，具体要求如下：
	宠物攻击方法，每次攻击时，随机选择一种技能进行攻击，输出攻击的宠物名字、技能名字、伤害值等信息。
	宠物防御方法，每次防御时，随机选择一个技能进行防御，输出防御的宠物名字、技能名字、防御值等信息。
实现一个测试程序，包括以下内容：
	创建若干个宠物，并添加到Battle类中
	选择一个宠物进行战斗，每回合随机选择攻击或防御，输出战斗信息
	当宠物生命值为0时，自动选择下一个宠物进行战斗
	当所有宠物生命值为0时，输出战斗结束信息

请在设计过程中，充分运用类和对象的封装、继承和多态特性，并使用良好的编码风格和注释，以便代码的可读性和可维护性。作业难度适中，但需要对类和对象的多态特性有一定的了解和掌握。

*/

#include <iostream>
#include <string>


using namespace std;

class Skill	//技能类
{
public:
	//构造函数的声明
	Skill(string name, string type, int damage, string description);
	//析构函数的声明
	~Skill();

	//获取和设置属性方法的声明
	void setName(string name);
	void setType(string type);
	void setDamage(int damage);
	void setDescription(string description);

	//获取属性方法的声明
	string getName();
	string getType();
	int getDamage();
	string getDescription();
	void printSkill();
private:
	//属性的声明
	string name;
	string type;
	int damage;
	string description;
};






