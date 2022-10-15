#include <iostream>
#include <string>

using namespace std;

/*

	友元：三种.
	1.全局函数作友元
	2.成员函数作友元
	3.类作友元

	下列程序包含以上三种方式；

	（1）：Building 有客厅，主卧，次卧。
	（2）：girlf类可以访问三个房间。（用3）
	（3）：commonf类只能访问客厅和主卧。（用2）
	（4）：陌生人只能访问客厅。（用1）

*/

class Building;
//注意声明顺序，这里有个陷阱：顺序极其重要，后面的类在前面的类中被用到需要提前声明；


class girlf
{
public:
	girlf();
	void gvisit();//比如这里，将定义写在类外就是为了避免写在这里而导致的说building内什么什么没定义的错误发生
private:
	Building* building;
};

class commonf
{
public:
	commonf();
	void cvisit();

private:
	Building* buildingc;
};
class Building
{
	
	friend class girlf;
	friend void commonf::cvisit();
	friend void stranger();

public:
	Building();
public:
	string m_Room_setting;
private:
	string m_Room_mbed;
	string m_Room_sbed;
};
Building::Building()
{
	this->m_Room_setting = "客厅";
	this->m_Room_sbed = "次卧";
	this->m_Room_mbed = "主卧";
}
girlf::girlf()
{
	this->building = new Building;
}
commonf::commonf()
{
	this->buildingc = new Building;
}

void girlf::gvisit()
{
	cout << "girlfriend正通过类作友元访问" << building->m_Room_setting << endl;
	cout << "girlfriend正通过类作友元访问" << building->m_Room_sbed << endl;
	cout << "girlfriend正通过类作友元访问" << building->m_Room_mbed << endl;
}
void commonf::cvisit()
{
	cout << "commonfriend正通过类作友元访问" << buildingc->m_Room_setting << endl;
	cout << "commonfriend正通过类作友元访问" << buildingc->m_Room_sbed << endl;
	cout << "commonfriend正通过类作友元访问" << buildingc->m_Room_mbed << endl;
}
void stranger()
{
	Building building;
	cout << "stranger正通过类作友元访问" << building.m_Room_setting << endl;
	cout << "stranger正通过类作友元访问" << building.m_Room_sbed << endl;
}
void test1()
{
	girlf girlfriend;
	commonf commonfriend;
	girlfriend.gvisit();
	cout << endl;
	commonfriend.cvisit();
	cout << endl;
	stranger();
	cout << endl;
}
int main(void)
{
	test1();
	system("pause");
	return 0;
}