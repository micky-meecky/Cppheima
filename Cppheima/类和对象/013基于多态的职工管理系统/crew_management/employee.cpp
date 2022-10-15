#include "Worker.h"
#include "employee.h"
#include "WorkManager.h"


Employee::Employee(int id, string name, int deptid, int time)//输入基本信息
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
	this->m_Time = 0;
	Employee::GetWorkingTime(time);
	Employee::CaculateSalary();
}

void Employee::GetKey(string key) // 输入密码
{
	if (this->Key != NULL)
	{
		delete this->Key;
		this->Key = NULL;
	}
	this->Key = new string(key);
}

void Employee::showInfo()	//显示信息，当密码不对时，无法查看薪资，密码为0000时，则显示默认薪资
{
	string k = "0000";
	char yn = 'n';
	int time;

	cout << "可以本月输入工作时长以继续查看本月薪资（y/n表示重新输入时长计算薪资/查看计算好的薪资,其他查看默认薪资）：";
	while (true)
	{
		cin >> yn;
		while (yn == '\n')
			continue;
		if (yn == 'y')
		{
			this->m_Time = 0;
			cout << "请输入本月工作时长" << endl;
			while (this->m_Time == 0)
			{
				cin >> time;
				if (cin.fail())		//C++的验证输入合法性的代码
				{
					WorkManager::Clearbuff();
					cout << "输入不合法，请重试。" << endl;
				}
				else if (time < 0 || time > 31 * 24)
				{
					while (getchar() != '\n')	//清除缓冲区
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "请输入正确范围内的数字" << endl;
				}
				else
				{
					Employee::GetWorkingTime(time);

					cin.clear();
				}
			}
			cout << "请输入密码（0000，查看默认薪资，具体薪资密码：****，exit表示退出）" << endl;
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
					cout << "密码错误，无法查看薪资，请重试。" << endl;
					while (getchar() != '\n')	//清除缓冲区
					{
						cin.clear();
						cin.sync();
						continue;
					}
					continue;
				}

			}
			while (getchar() != '\n')	//清除缓冲区
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
			cout << "请输入密码（0000，查看默认薪资，具体薪资密码：****，exit表示退出）" << endl;
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
					cout << "密码错误，无法查看薪资，请重试。" << endl;
					while (getchar() != '\n')	//清除缓冲区
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
			//cout << "输入有误，请重试" << endl;
			while (getchar() != '\n')	//清除缓冲区
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
	return string("普通员工");
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
