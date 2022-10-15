#pragma once
#include <iostream>
#include <string>
using namespace std;
//菜单界面

#define MAXN 1000

struct person {

	string name;
	int age;
	int sex;//(0:male,1:famale)
	string id;
	string phone;
};

struct books {
	int m_size;
	person idarrary[MAXN];
};

void showMenu()
{
	cout << "*******************************"	<< endl;
	cout << "*******  1、add id        *****"	<< endl;
	cout << "*******  2、show id       *****"	<< endl;
	cout << "*******  3、rectify id    *****"	<< endl;
	cout << "*******  4、delete id     *****"	<< endl;
	cout << "*******  5、clear system  *****"	<< endl;
	cout << "*******  0、exit system   *****"	<< endl;
	cout << "*******************************"	<< endl;
}

//退出函数
int exitf(void)
{
	cout << "are you sure? please enter y/n to confirm." << endl;
	cout << "\t\t************ \ty to quit and vice versa!!!\t *************" << endl;
	string sure;
	
	while (true)
	{
		cin >> sure;

		if (sure == "y")
		{
			cout << "welcome to next time" << endl;
			while (getchar() != '\n')
				continue;
			return 1;
			break;
		}
		else if (sure == "n")
		{	
			while (getchar() != '\n')
				continue;
			return 0;
			break;
		}
		else
		{
			while (getchar() != '\n')
				continue;
			cout << "There is not the exit option." << endl;
			cout << "****************Please try again!********" << endl;
			continue;
		}
	}
}

//add id
void addinfo(books* abs)
{
	if (abs->m_size == MAXN)
	{
		cout << "the books is full ,can not add anymore!" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "please enter the name: " << endl;
		cin >> name;
		(abs->idarrary[abs->m_size]).name = name;

		//age
		int age = 0;
		cout << "please enter the age: " << endl;
		cin >> age;
		abs->idarrary[abs->m_size].age = age;

		//sex
		int sex = 0;
		string quit = "q" ;
		cout << "please enter the sex: " << endl;
		cout << "********************\t1 for male\t**********************" << endl;
		cout << "********************\t0 for famale\t***********************" << endl;
		while (quit != "q!")
		{
			cin >> sex;

			if (sex == 0 || sex == 1)
			{
				abs->idarrary[abs->m_size].sex = sex;
				break;
			}
			else
			{
				cout << "your input is wrong , please try again ,or q! to quit." << endl;
				quit = getchar();
			}
		}

		//id
		string idnum;
		cout << "please enter the id number: " << endl;
		cin >> idnum;
		abs->idarrary[abs->m_size].id = idnum;

		//phone
		string phonenum;
		cout << "please enter the phone number" << endl;
		cin >> phonenum;
		abs->idarrary[abs->m_size].phone = phonenum;

		//abs.m_size
		abs->m_size++;

		cout << "Add successfully!!!" << endl << endl;
		cout << "There are " << abs->m_size << " id" << endl;

		system("pause");
		system("cls");
	}
}

void showid(books* abs)
{
	if (abs->m_size == 0)
	{
		cout << "there is no id info at all." << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "name：" << abs->idarrary[i].name << "\t";
			cout << "age：" << abs->idarrary[i].age << "\t";
			cout << "sex：" << (abs->idarrary[i].sex == 1 ? "男" : "女") << "\t";
			cout << "id：" << abs->idarrary[i].id;
			cout << " phone：" << abs->idarrary[i].phone << "\t" << endl;
		}
	}
	//system("pause");
	//system("cls");
}


void showid1(books* abs)
{
	system("cls");
	if (abs->m_size == 0)
	{
		cout << "there is no id info at all." << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "name：" << abs->idarrary[i].name << "\t\t";
			cout << "age：" << abs->idarrary[i].age << "\t\t";
			cout << "sex：" << (abs->idarrary[i].sex == 1 ? "男" : "女") << "\t\t";
			cout << "id：" << abs->idarrary[i].id << "\t\t";
			cout << "phone：" << abs->idarrary[i].phone << "\t\t" << endl;
		}
	}
	system("pause");
	system("cls");
}


int isExist(books* abs, string namefind)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->idarrary[i].name == namefind)
			return i;
		else
			continue;
	}
	return -1;
}


void rectify(books* abs)
{
	cout << "please enter the one you want to rectify: " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->idarrary[ret].name = name;

		//age
		cout << "please enter the age：" << endl;
		int age = 0;
		cin >> age;
		abs->idarrary[ret].age = age;

		//性别
		cout << "please enter the sex：" << endl;
		cout << "0 -- famale" << endl;
		cout << "1 -- male" << endl;
	
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				abs->idarrary[ret].sex = sex;
				break;
			}
			cout << "ERROR input ,please try again: ";
		}

		//id
		cout << "please enter the id：" << endl;
		string id;
		cin >> id;
		abs->idarrary[ret].id = id;

		//phone
		cout << "please enter the phone：" << endl;
		string phone = "";
		cin >> phone;
		abs->idarrary[ret].phone = phone;

		cout << "rectify successfully" << endl;
	}
	else
	{
		cout << "there is no one you want" << endl;
	}

	system("pause");
	system("cls");
	
}

//delete
void deleteid(books* abs)
{
	cout << "please enter the name you want to delete: " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->idarrary[i] = abs->idarrary[i+1];
		}
		abs->m_size--;
		cout << "delete successfully!" << endl;
	}
	else
	{
		cout << "there is no one you want" << endl;
	}

	system("pause");
	system("cls");
}











