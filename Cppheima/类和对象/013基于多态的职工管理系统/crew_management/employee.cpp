#include "Worker.h"
#include "employee.h"
#include "WorkManager.h"


Employee::Employee(int id, string name, int deptid, int time)//���������Ϣ
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
	this->m_Time = 0;
	Employee::GetWorkingTime(time);
	Employee::CaculateSalary();
}

void Employee::GetKey(string key) // ��������
{
	if (this->Key != NULL)
	{
		delete this->Key;
		this->Key = NULL;
	}
	this->Key = new string(key);
}

void Employee::showInfo()	//��ʾ��Ϣ�������벻��ʱ���޷��鿴н�ʣ�����Ϊ0000ʱ������ʾĬ��н��
{
	string k = "0000";
	char yn = 'n';
	int time;

	cout << "���Ա������빤��ʱ���Լ����鿴����н�ʣ�y/n��ʾ��������ʱ������н��/�鿴����õ�н��,�����鿴Ĭ��н�ʣ���";
	while (true)
	{
		cin >> yn;
		while (yn == '\n')
			continue;
		if (yn == 'y')
		{
			this->m_Time = 0;
			cout << "�����뱾�¹���ʱ��" << endl;
			while (this->m_Time == 0)
			{
				cin >> time;
				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					WorkManager::Clearbuff();
					cout << "���벻�Ϸ��������ԡ�" << endl;
				}
				else if (time < 0 || time > 31 * 24)
				{
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "��������ȷ��Χ�ڵ�����" << endl;
				}
				else
				{
					Employee::GetWorkingTime(time);

					cin.clear();
				}
			}
			cout << "���������루0000���鿴Ĭ��н�ʣ�����н�����룺****��exit��ʾ�˳���" << endl;
			while (true)
			{
				cin >> k;

				if (k == "exit")
				{
					break;
				}
				Employee::GetKey(k);

				if (*(this->Key) == "admin")
				{
					Employee::CaculateSalary();
					cout << "m_ID: " << to_string(this->m_ID) << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "      ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << m_Salary << "\t\t";
					break;
				}
				else if (*(this->Key) == "0000")
				{
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "      ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << Employee_Salary << "\t\t";
					break;
				}
				else
				{
					cout << "��������޷��鿴н�ʣ������ԡ�" << endl;
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					continue;
				}

			}
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			//system("pause");
			break;
		}
		else if (yn == 'n')
		{
			cout << "���������루0000���鿴Ĭ��н�ʣ�����н�����룺****��exit��ʾ�˳���" << endl;
			while (true)
			{
				cin >> k;

				if (k == "exit")
				{
					break;
				}
				Employee::GetKey(k);

				if (*(this->Key) == "admin")
				{
					Employee::CaculateSalary();
					cout << "m_ID: " << to_string(this->m_ID) << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "      ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << m_Salary << "\t\t";
					break;
				}
				else if (*(this->Key) == "0000")
				{
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "      ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << Employee_Salary << "\t\t";
					break;
				}
				else
				{
					cout << "��������޷��鿴н�ʣ������ԡ�" << endl;
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					continue;
				}
			}
			break;
		}
		else
		{
			cout << "m_ID: " << this->m_ID << "          ";
			cout << "m_Name: " << this->m_Name << "          ";
			cout << "m_DeptID: " << this->GetDeptName() << "      ";
			cout << "m_Time:" << this->m_Time << "          ";
			cout << "m_Salary: " << Employee_Salary << endl;
			//cout << "��������������" << endl;
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			break;
		}
	}
	cout << endl;
}

string Employee::GetDeptName()
{
	return string("��ͨԱ��");
}

void Employee::GetWorkingTime(int time)
{
	this->m_Time = time;
}

void Employee::CaculateSalary()
{
	this->m_Salary = this->m_Time * 40;
	//return this->m_Salary;
}

Employee::~Employee()
{
	if (this->Key != NULL)
	{
		delete this->Key;
		this->Key = NULL;
	}

}
