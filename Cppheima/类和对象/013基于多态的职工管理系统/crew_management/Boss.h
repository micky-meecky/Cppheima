#pragma once
#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;


class Boss : public Worker
{
public:
	Boss(int id, string name, int deptid, int time);

	void GetKey(string key);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ��Ϣ
	string GetDeptName();

	//��ȡ�ϸ�ʱ��
	virtual void GetWorkingTime(int time);

	//н�ʼ���
	virtual void CaculateSalary();

	~Boss();
};