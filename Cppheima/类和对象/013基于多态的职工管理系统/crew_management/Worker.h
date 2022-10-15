#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#define Employee_Salary "6000元"
#define Manager_Salary "12000元"
#define Boss_Salary "30000元"

using namespace std;


class Worker//创建员工抽象基类，便于创建三个不同岗位的多态
{
	friend class Employee;
	friend class Manager;
	friend class Boss;
	friend class WorkManager;
	//friend void WorkManager::_init_array();

public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取密码函数
	virtual void GetKey(string key) = 0;

	//获取岗位信息
	virtual string GetDeptName() = 0;

	//获取上岗时长
	virtual void GetWorkingTime(int time) = 0;

	//薪资计算(按h算，普通员工40/h，老板400/h，经理75/h,不算加班薪资)
	virtual void CaculateSalary() = 0;


	int m_ID = 0;
	string m_Name;
	int m_DeptID;
	string *Key;
	int m_Time;


private:
	int m_Salary;//薪水需要加密才能看

};