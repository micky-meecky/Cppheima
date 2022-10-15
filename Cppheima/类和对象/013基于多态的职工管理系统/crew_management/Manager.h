#pragma once
#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;


class Manager : public Worker
{
public:
	Manager(int id, string name, int deptid, int time);

	void GetKey(string key);

	//显示个人信息
	void showInfo();

	//获取岗位信息
	string GetDeptName();

	//获取上岗时长
	virtual void GetWorkingTime(int time);

	//薪资计算
	virtual void CaculateSalary();

	~Manager();
};
