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

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ��Ϣ
	string GetDeptName();

	//��ȡ�ϸ�ʱ��
	virtual void GetWorkingTime(int time);

	//н�ʼ���
	virtual void CaculateSalary();

	~Manager();
};
