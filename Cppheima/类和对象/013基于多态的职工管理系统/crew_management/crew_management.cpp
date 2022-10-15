#include <iostream>
#include <string>
#include <iomanip>
#include "WorkManager.h"//��������ϵͳ�����ͷ�ļ�
#include "Worker.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"

using namespace std;


//���Բ˵����ܵĲ��Ժ���
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
	worker = new Employee(3,"����",01,160);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 01, 160);
	worker->showInfo();
	delete worker;

	worker = new Boss(1, "���Ƿ�", 01, 160);
	worker->showInfo();
	delete worker;
	system("pause");
}

void test03(void)//���Ա�׼�����ʽ ����סsetw() ��Ҫ <iomanip>ͷ�ļ�
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
		wm.ShowManue();//չʾ�˵�

		cout << "��ѡ��" ;
		cin >> choice;

		while (choice == '\n')
			continue;

		switch (choice)
		{
			case '0': //�˳�ϵͳ
			{
				wm.ExitSystem();
				WorkManager::Clearbuff();
				break;
			}
			case '1': //���ְ��
			{
				wm.Add_Emp();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '2': //��ʾְ��
			{
				wm.Show();
				WorkManager::Clearbuff();
				system("pause");
				system("cls");
				break;
			}
			case '3': //ɾ��ְ��
			{
				wm.Delete();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '4': //�޸�ְ��
			{
				wm.Rectify();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '5': //����ְ��
			{
				wm.Find();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '6': //����ְ��
			{
				wm.Order_all();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			case '7': //����ļ�
			{
				wm.Emptify();
				WorkManager::Clearbuff();
				system("cls");
				break;
			}
			default:
			{
				cout << "�������벻�Ϸ��������ԣ�" << endl;
				WorkManager::Clearbuff();
				system("pause");
				system("cls");
				break;
	
			}
			WorkManager::Clearbuff();
		}
		if (choice == '0')
			break;	//ȷ����0���˳�
	}



	system("pause");
	return 0;
}