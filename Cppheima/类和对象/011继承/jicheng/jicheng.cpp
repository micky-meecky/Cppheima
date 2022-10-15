#include <iostream>
#include <string>

using namespace std;

/*
	继承语法： class <子类名> : <继承方式> <父类名>{};

	继承方式：三种
	1.public 将父类所有属性继承，原封不动
	2.protected 将父类public，protected两种属性全变为protected属性到子类中
	3.private 将父类中public,protected 两种属性全变为private属性到子类中
	4.注意，父类中的private，子类是无法访问的，无论是哪种继承方式；但是都会继承，也就是继承了个没有密码的银行卡
*/



/*
	查看父子类模型：
	1.首先先创建个含有子类的cpp，
	2.然后在开始打开VS的开发命令提示符窗口
	3.定位到当前工程盘符，
	4.cd /路径名
	5.cl /d1 reportSingleClassLayoutSon "所属文件名" 回车即可
*/

/*
	构造和析构顺序：构造是先有父亲，再有儿子；
*/

/*
	继承中同名的成员处理 
	如果通过子类的对象访问父类同名成员属性则需要加个作用域S.Base::m_A
	如果通过子类的对象访问父类同名成员函数则需要加个作用域S.Base::m_A

	1. 子类对象可以直接访问到子类中同名成员
	2. 子类对象加作用域可以访问到父类同名成员
	3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
	*/

/*
	静态成员和非静态成员出现同名
	同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）
	注意静态成员属性需要类内声明，类外初始化
	对于静态成员有两种访问方式：
	1.通过对象访问
	2.通过类名直接访问
	*/


/*
	多继承：语法格式：class <子类名> : <继承方式> <父类名>，<继承方式> <父类名> ... {};
	对于不同父类下同名成员，在子类中访问时为了避免出现二义性，应加上作用域；
*/

/*
	菱形继承的问题：
	1. 羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
	2. 草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。
	1.好解决，加作用于即可
	2.不好解决，需要加virtual，给中间的子类设置虚继承，此时公共的父类叫做虚基类。
	虚继承，继承的不是数据，而是vbptr（指针）指向vbtable
*/
class Base
{
public:
	Base()
	{
		m_A = 100;
		m_A1 = 100;
		m_Al = 300;
		//cout << "父类的构造函数" << endl;
	}
	~Base()
	{
		//cout << "父类的析构函数" << endl;
	}
	void func()
	{
		cout << "父类的func函数" << endl;
	} 
	void func(int )//与上面那个函数形成重载
	{
		cout << "父类的func函数+int" << endl;
	}
	static void func1()
	{
		cout << "父类的静态func函数" << endl;
	}
public:
	int m_A;
	static int m_SA;
	int m_A1;
	int m_Al;
protected:
	int m_B;
private:
	int m_C;
};
int Base::m_SA = 100;

class Base1
{
public:
	Base1()
	{
		m_A1 = 111;
	}

	int m_A1;
};

class Son :virtual public Base//虚继承，继承的不是数据，而是vbptr（指针）指向vbtable
{
public:
	Son()
	{
		m_A = 200;
		//cout << "子类的构造函数" << endl;
	}
	~Son()
	{
		//cout << "子类的析构函数" << endl;
	}

	static void func1()
	{
		cout << "子类的静态func函数" << endl;
	}

	void func()
	{
		cout << "子类的func函数" << endl;
	}
	
public:
	static int m_SA;
	int m_D;
	int m_A;
};
int Son::m_SA = 200;

class Son1 :virtual public Base, public Base1 //虚继承，继承的不是数据，而是vbptr（指针）指向vbtable
{

};

class Son2 :public Son, public Son1
{
	//菱形继承里的孙子
};

void test01()
{
	Son S;

	cout << "Son's A = " << S.m_A << endl;
	cout << "Base's A = " << S.Base::m_A << endl;
	//cout << "sizeofSon = " << sizeof(Son) << endl;
	S.func();
	S.Base::func();
	//S.func(100)
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	S.Base::func(100);
}

void test02()
{
	Son S1;

	//静态同名成员属性
	//两种，1.通过对象访问数据
	cout << "//1.通过对象访问数据" << endl;
	cout << "Son's m_SA = " << S1.m_SA << endl;
	cout << "Base's m_SA = " << S1.Base::m_SA << endl;
	//2.通过类名访问数据
	cout << "//2.通过作用域访问数据" << endl;
	cout << "Son's m_SA = " << Son::m_SA << endl;
	//第一个::代表用类名访问，第二个::代表Base作用域下的
	cout << "Base's m_SA = " << Son::Base::m_SA << endl;
	//静态同名成员函数
	//两种，1.通过对象调用
	cout << "//1.通过对象调用" << endl;
	S1.func1();
	S1.Base::func1();

	//2.通过类名调用
	cout << "//1.通过作用域调用" << endl;
	Son::func1();
	Son::Base::func1();


}

void test03()
{
	Son1 S1;
	cout << "Son1's Base's m_A1 = " << S1.Base::m_A1 << endl;
	cout << "Son1's Base1's m_A1 = " << S1.Base1::m_A1 << endl;

	cout << endl << "------------------- 菱形继承 --------------------" << endl;

	Son2 S2;//对于菱形继承，这里的m_Al虽然程序没有报错，但是明显这里存在不明确性
	S2.Son::m_Al = 180;
	S2.Son1::m_Al = 280;
	cout << "Son's m_Al = " << S2.Son::m_Al << endl;
	cout << "Son1's m_Al = " << S2.Son1::m_Al << endl;
	cout << "Son's m_Al = " << S2.m_Al << endl;
}

int main(void)
{
	//test01();	//继承语法，方式，父子模型
	//test02();	//继承析构构造顺序，静态与非静态同名成员的处理
	test03();	//多继承，菱形继承

	system("pause");
	return 0;
}