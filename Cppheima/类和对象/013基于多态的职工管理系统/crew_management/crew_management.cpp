#include <iostream>
#include <string>
#include <iomanip>
#include "WorkManager.h"//包含管理系统的类的头文件
#include "Worker.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"

using namespace std;


//测试菜单功能的测试函数
void test01(void)
{
	WorkManager wm;
	wm.ShowManue();
}
void test02(void)
{
	WorkManager wm;
	wm.ShowManue();

	
	Worker* worker = NULL;
	worker = new Employee(3,"张三",01,160);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "张三", 01, 160);
	worker->showInfo();
	delete worker;

	worker = new Boss(1, "杨亚峰", 01, 160);
	worker->showInfo();
	delete worker;
	system("pause");
}

void test03(void)//测试标准输出方式 ，记住setw() 需要 <iomanip>头文件
{
	cout.setf(ios::left);
	cout << "num" << "\t" <<setw(10) << "name" << "\t" << setw(10) << "ad" << endl;
	cout << "nu" << "\t" << setw(10) << "n222ame" << "\t" << setw(10) << "ad" << endl;
	cout << "num222" << "\t" << setw(10) << "nam33e" << "\t" << setw(10) << "ad" << endl;
	system("pause");
}

int main(void)
{
	//test01();
	//test02();
	//test03();

	char choice = '8';
	WorkManager wm;
	
	while (true)
	{	
		wm.ShowManue();//展示菜单

		cout << "请选择：" ;
		cin >> choice;

		while (choice == '\n')
			continue;

		switch (choice)
		{
			case '0': //退出系统
			{
				wm.ExitSystem();
				WorkManager::Clearbuff();
				break;
			}
			case '1': //添加职工
			{
				wm.Add_Emp();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '2': //显示职工
			{
				wm.Show();
				WorkManager::Clearbuff();
				system("pause");
				system("cls");
				break;
			}
			case '3': //删除职工
			{
				wm.Delete();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '4': //修改职工
			{
				wm.Rectify();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '5': //查找职工
			{
				wm.Find();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '6': //排序职工
			{
				wm.Order_all();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '7': //清空文件
			{
				wm.Emptify();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			default:
			{
				cout << "您的输入不合法，请重试！" << endl;
				WorkManager::Clearbuff();
				system("pause");
				system("cls");
				break;
	
			}
			WorkManager::Clearbuff();
		}
		if (choice == '0')
			break;	//确认是0，退出
	}



	system("pause");
	return 0;
}