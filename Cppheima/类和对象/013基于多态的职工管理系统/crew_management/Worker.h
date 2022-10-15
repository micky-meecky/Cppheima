#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#define Employee_Salary "6000Ԫ"
#define Manager_Salary "12000Ԫ"
#define Boss_Salary "30000Ԫ"

using namespace std;


class Worker//����Ա��������࣬���ڴ���������ͬ��λ�Ķ�̬
{
	friend class Employee;
	friend class Manager;
	friend class Boss;
	friend class WorkManager;
	//friend void WorkManager::_init_array();

public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ���뺯��
	virtual void GetKey(string key) = 0;

	//��ȡ��λ��Ϣ
	virtual string GetDeptName() = 0;

	//��ȡ�ϸ�ʱ��
	virtual void GetWorkingTime(int time) = 0;

	//н�ʼ���(��h�㣬��ͨԱ��40/h���ϰ�400/h������75/h,����Ӱ�н��)
	virtual void CaculateSalary() = 0;


	int m_ID = 0;
	string m_Name;
	int m_DeptID;
	string *Key;
	int m_Time;


private:
	int m_Salary;//нˮ��Ҫ���ܲ��ܿ�

};