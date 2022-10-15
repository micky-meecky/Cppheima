#include<iostream>
#include<string>

using namespace std;


//运算符重载：（注意事项：可以在类内做重载，也可以在类外做重载，但是不是所有重载类型都可以在类内重载）
//	1.+法重载	p1.operator+（&p）即为 p1 + p, 也可以做函数重载
//	2.<<运算符重载	不可在类内做重载，因为无法满足调用时P在右边的习惯；
//	3.++/--运算符重载 先理解内置递增运算符的过程，分为前置和后置；
//	4.=运算符重载  重新创建个类做实验，将属性都开辟到堆区，其实这里=赋值运算符就是值拷贝操作，说到拷贝就有深浅拷贝之分
//				  ，这里就会出现内存重复释放的问题. 赋值运算符 operator=, 对属性进行值拷贝,若开发人员不写，则由编译期自动给
//				  跟构造函数一样。
//	5.关系运算符==重载	(这个简单)
//	6.函数调用运算符()重载	(匿名对象的创建，仿函数)

class Person
{
	friend Person operator+(Person& p1, Person& p2);
	friend ostream& operator<<(ostream& cout, Person& p);
	friend Person operator+(Person& p1, int num);
	friend Person& operator++(Person& p, int);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//成员函数方式
	Person operator-(Person& p)
	{
		Person temp(0,0);
		temp.m_A = this->m_A - p.m_A;
		temp.m_B = this->m_B - p.m_B;
		return temp;
	}
	//前置++运算符
	Person& operator++()
	{
		m_A++;
		return *this;//这里返回的是自己的这个对象
	}
	//前置--运算符
	Person& operator--()
	{
		m_A--;
		return *this;//这里返回的是自己的这个对象
	}
	//后置++运算符
	//Person& operator++(int)
	//{
	//	Person *temp = new Person(*this);//创建了一个叫做temp的临时对象在对区，就可以返回他自己了；
	//	temp->m_B = this->m_B;
	//	this->m_B++;
	//	return *temp;//这里返回的是临时对象，虽然这样可以用引用的方式返回了，但是依然返回的不是自己，无法进行链式递增。
	//}

	//后置--运算符重载
		Person& operator--(int)
	{
		Person *temp = new Person(*this);//创建了一个叫做temp的临时对象在对区，就可以返回他自己了；
		temp->m_B = this->m_B;
		this->m_B;
		return *temp;//这里返回的是临时对象，虽然这样可以用引用的方式返回了，但是依然返回的不是自己，无法进行链式递增。
	}


private:
	int m_A;
	int m_B;

};

class Integer
{
	friend void test_fuzhi();
public:
	Integer(int num)
	{
		m_Num = new int(num);
	} 
	//赋值=重载
	Integer& operator=(const Integer &pp)
	{
		//首先先判断this里的m_Num是否为空，若否，则先释放再说
		if (m_Num != NULL)
		{
			delete m_Num;
			m_Num = NULL;
		}
		//再用深拷贝进行赋值操作
		this->m_Num = new int(*pp.m_Num);
		return *this;
	}
	
	//关系==重载
	bool operator==(Integer &pp)
	{
		//if (this->m_Num == pp.m_Num)
			return this->m_Num == pp.m_Num ? true : false;
	}

	//调用()重载
	void operator()(int a,int b)
	{
		cout << "a = " << a << " b = " << b << endl;
	}


	~Integer()
	{
		if (m_Num != NULL)
		{
			delete m_Num;
			m_Num = NULL;
		}
	}

private:
	int *m_Num;
};
//全局函数实现的+运算符重载 
Person operator+(Person &p1, Person &p2)
{
	Person temp(0,0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//+运算符重载 可以发生函数重载 
Person operator+(Person& p1, int num)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
//++运算符重载
Person& operator++(Person &p, int)
{
	Person* temp = new Person(p);//创建了一个叫做temp的临时对象在堆区，就可以返回他自己了；
	temp->m_B = p.m_B;
	p.m_B++;
	return *temp;//这里返回的是临时对象，虽然这样可以用引用的方式返回了，但是依然返回的不是自己，无法进行链式递增。
}
// <<运算符重载
ostream& operator<<(ostream &cout, Person &p)
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test_jia()
{
	Person P1(10,10);
	Person P2(20,20);
	cout << P1 << endl;
	cout << P2 << endl;
	Person P3 = P1 + P2;
	cout << P3 << endl;
	Person P4 = P1 - P2;
	cout << P4 << endl;
	Person P5 = P1 + 100;
	++(++P5);
	cout << P5 << endl;
	cout << (P5++)++ << endl;
	cout << P5 << endl;
	cout << P5 << endl;
}

void test_fuzhi()
{
	Integer PP1(10);
	Integer PP2(20);
	Integer PP3(15);
	PP2 = PP1 = PP3;
	cout << "m_Num = " << *PP1.m_Num << " " << endl;
	cout << "m_Num = " << *PP2.m_Num << " " << endl;
	bool a;
	a = PP1 == PP2;
	cout << noboolalpha << a << endl;
	PP1(1, 2);//特别像函数调用，但其实不是，所以称其为仿函数；
	//创建一个匿名对象，因为类中有有参构造函数，所以不会调用默认构造函数，所以在创建匿名对象的时候需要包含(20);
	Integer(20)(20, 30);
}

int main(void)
{
	test_jia();
	test_fuzhi();

	system("pause");
	return 0;
}





