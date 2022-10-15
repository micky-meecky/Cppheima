#include <iostream>
#include <string>

using namespace std;

class Person
{


//1、分类
//按照参数进行分类  有参构造函数    无参构造函数（默认构造函数）


public:
	//构造函数
	Person()
	{
		cout << "普通构造函数调用" << endl;
	}
	//有参构造函数
	Person(int a)
	{
		age = a;
		cout << "有参构造函数调用" << endl;

	}
	
	//按照类型进行分类  普通构造函数    拷贝构造函数
	//拷贝构造函数
	//拷贝构造函数的调用时机
	//1、使用一个已经创建好的对象来初始化另一个对象
	//2、以值传递的方式 给函数的参数传值
	//3、以值的方式返回局部对象
	Person(const Person &P) //注意写法
	{
		age = P.age;
		cout << "拷贝构造函数调用" << endl;
	}
	//析构函数
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
public:
	int age;

};

void test01()
{
	////无参构造函数


	//有参构造函数
	//括号法
	//Person P1; //调用默认构造函数的时候不能加()，因为如果这样，编译器会误以为是函数声明
	//Person P2(10);
	//Person P3(P2);
	//cout << "P2的年龄：" << P2.age << endl;
	//cout << "P3的年龄：" << P3.age << endl;

	////显示法
	//Person P1;
	//Person P2 = Person(10);
	//Person P3 = Person(P2);
	////Person(10);	//匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象；
	////Person(p5);	//不可以调用拷贝构造函数 来初始化匿名函数对象 Person(p5); 编译器认为代码为 Person p5; 

	//	//隐式法
	//Person p6 = 10; // Person p6 = 10; 等价于写了  Person p6 = Person(10)
	//Person p7 = p6;




}



int main(void)
{
	//Person P2;
	test01();

	system("pause");
	return EXIT_SUCCESS;
}