#include <iostream>
#include <string>

using namespace std;
//对象成员，创建两个类，一个person，一个phone；包含静态成员与函数；


//静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据

//phone 类
class Phone
{
public:

	Phone(string brand) :Brand(brand) {}//初始化列表，相当于调用有参构造函数
	//创建静态函数
	static void fun1()
	{
		Price = 10086;
	}

	static int Price;
	string Brand;
private:
	static void fun2()
	{
		cout << "私有的静态成员函数调用" << endl;
	}
	static int a;
};
int Phone::Price = 8848;

//person类
class Person
{
public:

	Person(string name,string p_brand): Name(name),P_Brand(p_brand){}
	
	//姓名
	string Name;

	//手机品牌
	Phone P_Brand;

};



void test1()
{
	//1、通过对象访问静态成员变量
	Person P("张三", "华为P60");
	cout << P.Name << "拿着" << P.P_Brand.Brand << ", " << Phone::Price << "元" << endl; //如果不类外初始化，这里就会报错
	P.P_Brand.fun1(); 
	//P.P_Brand.fun2();
	cout << P.Name << "拿着" << P.P_Brand.Brand << ", " << P.P_Brand.Price << "元" << endl;

	//2.通过类名用作用域访问
	cout << P.Name << "拿着" << P.P_Brand.Brand << ", " << Phone::Price << "元" << endl;
}


int main(void)
{
	test1();

	system("pause");
	return 0;
}