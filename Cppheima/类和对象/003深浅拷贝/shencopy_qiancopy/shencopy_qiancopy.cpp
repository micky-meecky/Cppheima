#include <iostream>
using namespace std;


class Person
{
public:
	//无参（默认）构造函数
	Person()
	{
		cout << "普通构造函数" << endl;
	}
	//有参数构造函数
	Person(int age,int height)
	{
		Height = new int(height);//此时Height在堆区创建；所以需要程序员手动delete；
		Age = age;
		cout << "有参构造函数" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		Age = p.Age;
		//Height = p.Height; //浅拷贝 -- 导致同一个堆区地址内存重复释放，非法操作；
		Height = new int(*p.Height);//作深拷贝 -- 开辟两个堆区地址存放各个对象的属性，各自释放各自的地址
		cout << "拷贝构造函数" << endl;
	}
	//析构函数
	~Person()
	{
		if (Height != NULL)
		{
			delete Height;
			Height = NULL;//避免出现野指针
		}
		cout << "析构函数" << endl;
	}

	int Age;
	int* Height;


};

void test01()
{
	Person P3;			//默认构造函数不能写成Person P3(); 这样编译器会以为你写的是个函数
	Person P1(18,160);	//括号法调用有参构造函数
	Person P2(P1);		//括号法调用拷贝构造函数
	cout << "P1的年龄是： " << P1.Age << "P1的身高是：" << *P1.Height << endl;
	cout << "P2的年龄是： " << P2.Age << "P2的身高是：" << *P2.Height << endl;
}

int main(void)
{
	test01();

	system("pause");
	return 0;
}
//如果属性有在堆区开辟的，一定要自己提供拷贝函数，防止浅拷贝带来的问题；

