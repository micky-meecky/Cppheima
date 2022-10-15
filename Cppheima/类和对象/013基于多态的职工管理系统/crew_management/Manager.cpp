#include "Worker.h"
#include "Manager.h"


Manager::Manager(int id, string name, int deptid, int time)//输入基本信息
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
	this->m_Time = 0;
	Manager::GetWorkingTime(time);
	Manager::CaculateSalary();

}

void Manager::GetKey(string key) // 输入密码
{
	if (this->Key != NULL)
	{
		delete this->Key;
		this->Key = NULL;
	}
	this->Key = new string(key);
}

void Manager::showInfo()	//显示信息，当密码不对时，无法查看薪资，密码为0000时，则显示默认薪资
{
	string k = "0000";
	char yn = 'n';
	int time;

	cout << "可以本月输入工作时长以继续查看本月薪资（y/n表示是/否,其他查看默认薪资）：";
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
					while (getchar() != '\n')	//清除缓冲区
					{
						cin.clear();
						cin.sync();
						continue;
					}
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
					Manager::GetWorkingTime(time);

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
				Manager::GetKey(k);

				if (*(this->Key) == "admin")
				{
					Manager::CaculateSalary();
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "          ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << m_Salary << endl;
					break;
				}
				else if (*(this->Key) == "0000")
				{
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "          ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << Manager_Salary << endl;
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
			system("pause");
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
				Manager::GetKey(k);

				if (*(this->Key) == "admin")
				{
					Manager::CaculateSalary();
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "          ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << m_Salary << endl;
					break;
				}
				else if (*(this->Key) == "0000")
				{
					cout << "m_ID: " << this->m_ID << "          ";
					cout << "m_Name: " << this->m_Name << "          ";
					cout << "m_DeptID: " << this->GetDeptName() << "          ";
					cout << "m_Time:" << this->m_Time << "          ";
					cout << "m_Salary: " << Manager_Salary << endl;
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
			/*cout << "m_ID: " << this->m_ID << "          ";
			cout << "m_Name: " << this->m_Name << "          ";
			cout << "m_DeptID: " << this->GetDeptName() << "          ";
			cout << "m_Time:" << this->m_Time << "          ";
			*/
			break;
		}
		else
		{
			cout << "m_ID: " << this->m_ID << "          ";
			cout << "m_Name: " << this->m_Name << "          ";
			cout << "m_DeptID: " << this->GetDeptName() << "          ";
			cout << "m_Time:" << this->m_Time << "          ";
			cout << "m_Salary: " << Manager_Salary << endl;
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
	//cout << "m_ID: " << this->m_ID << "\t\t";
	//cout << "m_Name: " << this->m_Name << "\t";
	//cout << "m_DeptID: " << this->GetDeptName() << "\t";
	//cout << "m_Time:" << this->m_Time << endl;
	cout << endl;

}

string Manager::GetDeptName()
{
	return string("经理");
}

void Manager::GetWorkingTime(int time)
{
	this->m_Time = time;
}

void Manager::CaculateSalary()
{
	this->m_Salary = this->m_Time * 75;
	//return this->m_Salary;
}

Manager::~Manager()
{
	if (this->Key != NULL)
	{
		delete this->Key;
		this->Key = NULL;
	}

}
