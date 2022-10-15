#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;


//*********************封装 实例化****************************************************
//有点像结构体，只不过结构体的是变量，类的是函数，可以看作是升级版的结构体
//其主要区别是：结构体默认权限是public，类的默认权限是private；
//实例化： 通过一个类创建一个对象，实例化一个对象 ，仿照verilog HDL来理解吧
//类中的属性和行为统称为成员，属性： 成员属性，成员变量，行为： 成员函数，成员方法

//创建一个类 【封装】
class circle
{
	//访问权限
public:


	//属性
	int r;
	//行为（通常为一个函数）
	double perimeter()
	{
		return 2 * PI * r;
	}


};

//设计一个学生类，属性有学号，姓名，可以给学生属性赋值，并显示
class student
{
public:				//创建一个访问权限，提高安全性

	string name;
	string num;

public:
	void display()
	{
		cout << "name: " << name << "\tnum: " << num << endl;
	}
	void setname(string Name) //通过行为去更改属性赋值
	{
		name = Name;
	}
	void setnum(string Num)
	{
		num = Num;
	}
};



//*******************************访问权限******************************************
//公共权限：public		成员 类内类外可以用
//保护权限：protected	成员 类内可以访问，类外不可以访问 继承 儿子可以访问父亲的保护内容
//私有权限：private		成员 类内可以访问，类外不可以访问 继承 儿子不可以访问父亲的保护内容
//创建一个包含三个访问权限的类
class person
{
public:
	string name; //名字谁都能访问
protected:
	string car;	//车是保护物品，不能谁都可以访问，但儿子可以访问
private:
	string key;	//银行卡密码，是私有物品，谁都不能访问

//类内能访问
public:
	void func()
	{
		name = "张三";
		car = "丰田";
		key = "123456";
	}

};

//*****************************成员属性私有化*********************************************
//将类中的所有属性设置私有化，并在类中提供对属性的设置接口；
//优点： 可以自行设置读写权限；对于写权限，我们可以检测输入数据的有效性；


//*****************************类与对象-封装-案例****************************************
//1.求长方体的面积与体积；
//2.用全局函数和成员函数分别判断两个长方体是否相等

class lover
{
//提供设置接口
public:
	//对于Name 可读可写的外部接口
	void SetName(string name)
	{
		Name = name;
	}
	string ReadNname()
	{
		return Name;
	}
	//对于年龄，可读可写；（并且在写的时候判断年龄的合理性）
	void SetAge(int age)
	{
		if (age > 150 || age < 0)
		{
			Age = 0;
			cout << "Are you kidding me ?\nAre you a saint or demon?" << endl;
			
			return;
		}
		else
		{
			Age = age;
		}
	}
	int ReadAge()
	{
		return Age;
	}

	//对于情人,只能写不能读
	void SetLover(string lover)
	{
		Lover = lover;
	}

//设置私有化
private: 
	string Name;
	int Age;
	string Lover;
};



int main(void)
{
	//*********************封装 实例化****************************************************

	//circle c1; //创建一个对象
	//c1.r = 10; //对这个对象的属性进行赋值
	//cout << "the perimeter is :" << c1.perimeter() << endl;


	//student st;
	///*st.name = "yyf";
	//st.num = "S20060809000";*/
	//st.setname("yyf");
	//st.setnum("S000000000");

	//st.display();

	//*******************************访问权限**********************************************

	//person p1;
	//p1.name = "李四";
	////p1.car = "本田";//报错


	//*****************************成员属性私有化*********************************************
	lover l1;
	l1.SetName("张武");
	l1.SetAge(13);
	l1.SetLover("波多野结裤");
	cout << "name: " << l1.ReadNname() << endl;
	cout << "age: " << l1.ReadAge() << endl;



	system("pause");
	return 0;
}