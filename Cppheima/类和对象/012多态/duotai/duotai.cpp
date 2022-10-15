#include <iostream>
#include <string>

using namespace std;

/*
	在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容

因此可以将虚函数改为纯虚函数

纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;

当类中有了纯虚函数，这个类也称为==抽象类==

抽象类特点：
- 无法实例化对象
- 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

*/

class Base
{
public:
	virtual void func() = 0;//创建纯虚函数
};
class Son:public Base
{
	void func()
	{
		cout << "重写抽象类的纯虚函数" << endl;
	}
};




/*
	用多态和普通方式实现两个数的计算操作；
*/
//普通方式,缺点，可维护性差，扩展性低，没有需求有变化，都需要改之前的源代码。
class Caculator
{
public:
	int add()
	{
		return m_A + m_B;
	}
	int sub()
	{
		return m_A - m_B;
	}
	int mul()
	{
		return m_A * m_B;
	}
public:
	int m_A;
	int m_B;
};
//动态多态实现，代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
//C++开发提倡利用多态设计程序架构，因为多态优点很多
class Caculator2
{
public:

	virtual int cac() //创建一个虚函数
	{
		return 0;
	}

	int m_A;
	int m_B;
};
class Add :public Caculator2
{
	int cac()	//重写父类的虚函数
	{
		return m_A + m_B;
	}
};
class Sub :public Caculator2
{
	int cac()
	{
		return m_A - m_B;
	}
};
class Mul :public Caculator2
{
	int cac()
	{
		return m_A * m_B;
	}
};


/*
	动态多态实现原理
	见ipad笔记
*/


/*
多态初步使用小结：

多态满足条件

- 有继承关系
- 子类重写父类中的虚函数

多态使用条件

- 父类的指针或引用指向子类对象

重写：函数返回值类型  函数名 参数列表 完全一致称为重写
*/

class Animal
{
public:
	Animal()
	{

	}

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Cat : public Animal
{
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog : public Animal
{
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
void Speak(Animal &animal)
{
	animal.speak();
}


/*
	多态是C++面向对象三大特性之一

多态分为两类

- 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
- 动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：

- 静态多态的函数地址早绑定  -  编译阶段确定函数地址
- 动态多态的函数地址晚绑定  -  运行阶段确定函数地址

*/



void test01()
{
	Cat cat;
	Dog dog;
	Speak(cat);
	Speak(dog);
}

void test02()
{
//	Caculator c;
//	c.m_A = 10;
//	c.m_B = 10;
//
//	cout << c.m_A << " + " << c.m_B << " = " << c.add() << endl;
//
//	cout << c.m_A << " - " << c.m_B << " = " << c.sub() << endl;
//
//	cout << c.m_A << " * " << c.m_B << " = " << c.mul() << endl;


	Caculator2* C2 = new Add();
	C2->m_A = 1000;
	C2->m_B = 1000;
	cout << C2->m_A << " + " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;	//用完要手动销毁

	C2 = new Sub();
	C2->m_A = 1000;
	C2->m_B = 1000;
	cout << C2->m_A << " - " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;

	C2 = new Mul();
	C2->m_A = 10;
	C2->m_B = 10;
	cout << C2->m_A << " * " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;
}

void test03()
{
	//Base a; // 不能创建一个Base对象，因为它是一个抽象类。
	//Son s;
	Base* base = new Son;
	base->func();
	delete base;
}

int main(void)
{
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
}

