#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Worker.h"
#include "WorkManager.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"

#define FILENAME "Member.txt"
#define MAXLIST 99
#define SUOJIN 10 //��׼���������ֵ

using namespace std;

class WorkManager
{
public:
	//���캯������
	WorkManager();


	//չʾ�˵��Ľ���
	void ShowManue();

	//����ְ��
	void Add_Emp();

	//����ְ��
	void Add_Emp(int idx,int newid);

	//���浽�ļ�
	void save();

	//��ȡ�ļ�����
	int GetEmpNum();

	//�б��ʼ��
	int _init_array();

	//��ʾ�б���Ϣ����
	void Show();

	//��ʽ������б�
	void StdOut();

	//��ID����ð��
	void Order_ID();

	//��ID������ð��
	void Order_ID_Reverse();

	//ɾ��ְ����Ϣ
	void Delete();

	//ID�����Լ�⣬����bool����
	bool IsExist(int id, int* idx);

	//�޸ĳ�Ա
	void Rectify();

	//����ְ��
	void Find();

	//��������
	int FindName(int *idx, string name);

	//����ְ������
	int FindDept(int* idx, int deptid);

	//���ҹ���ʱ��
	int FindTime(int* idx, int time);

	//����
	void Order_all();

	//��ְ�ܲ���
	void Order_Deptid();

	//��ְ�ܲ��ŵ���
	void Order_Deptid_Reverse();

	//������ʱ������
	void Order_Time();

	//������ʱ������
	void Order_Time_Reverse();

	//�������
	void Emptify();



	//�˳�����
	void ExitSystem();

	//���id�Ƿ������е��ظ���
	bool IsRepeat(int id);

	//���������
	static void Clearbuff();

	//������������
	~WorkManager();

	//�ж��ļ���ȡ�Ƿ���������쳣��1������0,����
	int TorF = 1;	

	//��¼�ļ��е���������
	int m_EmpNum;

	//�����ļ�Ϊ�յı�־����0��ʾû���ļ�������Ϊ��
	int m_FileEmpty;

	//Ա�������ָ��
	Worker** m_EmpArray;//����ָ�룬�洢������̬��*worker����ָ��Worker���͵�ָ��Worker��ָ���ָ�롣
};