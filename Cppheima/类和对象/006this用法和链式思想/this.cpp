#include <iostream>
using namespace std;

/*
	  小结:	
			1.注意最好用命名规范m_Age的m是指member，成员的意思
			2.this 能区分不同对象共享的类中成员函数，指的就是具体那个对象，且不用人为传递参数
			3.注意引用的语法规则，以及引用返回的过程细则
			4.成员变量与成员函数分开存储的
			5.只有非静态变量才属于类的对象上
			6.this是隐含一个非静态成员函数内部的一个指针，且只能用于非静态函数内部
			7.C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针，
				但是如果成员函数中用到了this指针，就不可以了
			8.		if (this == NULL)
					{
						return;
					}
					遇到空指针访问，则可以用上面代表直接跳过；提高程序鲁棒性；
			9.静态成员函数和静态成员变量没有用到this指针，则可以正常调用的。
			10.成员函数后加const后我们称为这个函数为常函数，常函数内不可以修改成员属性，
				成员属性声明时加关键字mutable后，在常函数中依然可以修改。构造函数和析构函数不能用。
			11.声明对象前加const称该对象为常对象，常对象只能调用常函数。

*/
class Person
{
public:

	Person(int age, int money)
	{
		if (this == NULL)
		{
			return;
		}
		m_Age = age;//利用变量名的设置来区分
		this->money = money;//利用this 来区分同名变量
	}

	Person &func(const Person &p)//注意这里需要用引用的方式返回，否则的话使用的是值传递，而值传递会拷贝一份出来
		//此时不是P2了，而且拷贝使用的是默认拷贝构造函数，是空的，这样子返回的就是P2的拷贝，而非P2本体；
		//这里加了个const，也就说不能更改指了，由于是引用，也不能改地址
	{
		if (this == NULL)
		{
			cout << "访问空指针的函数" << endl;
			return *this;
		}
		//p.m_Age = 100;
		money += p.money;
		return *this;//这里的*this 就是this指向的P2的实体；
	}
	static void func1()
	{
		cout << "空指针访问静态成员函数的函数" << endl;
	}
	void func2()const
	{
		cout << "常对象能调用这个函数吗？" << endl;
	}

	void f(int age)const		//常函数
	{
		this->m_Age = age;
	}

	mutable int m_Age;//创建一个可修改的mutable的成员变量

	int money;
	static int a;	//创建一个类内静态成员变量
};

int Person::a = 10; //对静态成员变量进行类外初始化

void test1()
{
	const Person P1(10,1);	//创建一个常对象
	Person P2(20,0);
	P2.func(P1).func(P1);	//让P2的money加上P1的money两次
	P1.func2();	//报错，不能调用除常函数以外的其他函数,以为其他非常函数是可以更改成员变量的，而const的对象是不允许更改的

	Person* P3 = NULL;		//定义一个指向空指针的对象，也就是没有对象；

	P3->func(P1);	//空指针调用成员函数
	P3->func1();	//空指针调用成员函数

	cout << "空指针P3中的静态变量能访问,a = " << P3->a << endl;

	cout << "P2 的年龄是：" << P2.m_Age << " P2的钱有：" << P2.money << endl;
}
int main(void)
{
	test1();
	system("pause");
	return 0;
}