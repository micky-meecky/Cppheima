#include <iostream>
#include <string>

using namespace std;

class Math 
{
public:

	Math(Math & m)	//创建一个拷贝构造函数
	{
		m_A = m.m_A;
		m_B = new int(*m.m_B); //堆区创建一个深拷贝
	}
	~Math()	//创建一个析构函数
	{
		if (m_B != NULL)
		{
			delete m_B;
			m_B = NULL;
		}
	}
	//创建一个有参构造函数
	Math(int a, int b)
	{
		this->m_A = a;
		m_B = new int (b);
	}
	int add(void)//加法
	{
		return m_A + *m_B;
	}
	int deduct(void)//减法
	{
		return m_A > *m_B ?  m_A - *m_B : *m_B - m_A;
	}

public:
	mutable int  m_A;
	int *m_B;
};

class English
{
public:
//无参构造函数 这里由于下面定义了有参构造函数，所以这里不会调用无参构造函数
	English()	
	{
		cout << "English 的默认构造函数" << endl;
		m_Word1 = "apple";
	}
	English(string str1)	//有参构造函数
	{
		cout << "English 的有参构造函数" << endl;
		m_Word1 = "apple";
		m_Word2 = str1;
	}
	string Getword1() 
	{
		return m_Word1;
	}
	string Getword2()
	{
		return m_Word2;
	}
	string Getword3()	//静态成员函数只能访问m_Word3
	{
		return m_Word3;
	}

	mutable string m_Word1;
	string m_Word2;
	static string m_Word3;	//静态成员变量
};
string English::m_Word3 = "banana";//静态成员变量类外初始化


class Caculus
{
public:
	Caculus(int a,int b,string str):eng(str),mt(a,b)
	{
		cout << "初始化列表" << endl;
	}



	int& GetResult()//用引用的方式返回result，返回的是result[0]的值
	{
		int* result = new int[2];	//利用new创建一个堆区的数组，问题是如何释放
		result[0] = mt.add();
		result[1] = mt.deduct();
		/*cout << "result = " << result << " *result = " << *result << endl;
		cout << "result[1] = " << result + 1 << " *result = " << *(result + 1) << endl;*/
		return *result;
	}

	string* GetWords()//用指针方式返回，返回的是s[0]的地址
	{
		static string s[3] = {eng.Getword1(),eng.Getword2(), eng.Getword3()};//创建静态成员变量，则可以避免返回局部变量地址
		return s;
	}
	//构造析构函数
	~Caculus()
	{
		
	}
public:
	//int Opt;
	English eng;
	Math mt;
};



int main(void)
{

	//练习目的，复习+熟悉新知识点（深浅拷贝，构造函数，this指针，引用，封装。。。）
	//创建一个Learning类,包含两个嵌套类，Math, English.（构造函数，引用）
	//Math类包含加减操作,并输出.（深拷贝，this)
	//English类包含两个单词初始化和打印输出，（初始化列表，静态成员函数,常对象常函数)

	//不用在意输入合法化

	//English e("peach");
	//cout << e.Getword1() << endl;
	Caculus start(2,3,"peach");
	std::cout << "add = " << start.GetResult() << " deduct = " << *(&start.GetResult() + 1) << endl;//取第二个元素的值可以先取址再取值的方式获取
	//string *s = start.GetWords();
	std::cout << "word1 = " << *start.GetWords() << endl;
	std::cout << "word2 = " << *(start.GetWords() + 1) << endl;
	std::cout << "word3 = " << *(start.GetWords() + 2) << endl;


	system("pause");
	return 0;
}