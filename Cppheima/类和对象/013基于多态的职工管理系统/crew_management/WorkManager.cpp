#include "WorkManager.h"

//构造函数调用
WorkManager::WorkManager()
{

	ifstream ifs;
	string lock = "chngxukazaizheliburangyunxing le";

	ifs.open(FILENAME, ios::in);


	//文件不存在，打开失败：
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件为空判断
		this->m_FileEmpty = 0;

		ifs.close();
		return;
	}
	else    //文件打开成功
	{
		char ch;
		(ifs >> ch);
		//文件存在，但是没有数据记录
		if (ifs.eof())
		{
			cout << "文件存在，但是数据为空" << endl;
			//初始化人数
			this->m_EmpNum = 0;

			//初始化数组指针
			this->m_EmpArray = NULL;

			//初始化文件为空判断
			this->m_FileEmpty = 0;

			ifs.close();
			return;

		}
		//文件存在，且存在数据
		else
		{
			//该函数用于检测文件内已存在的数据内容，返回人数
			int n = GetEmpNum();
			this->m_EmpNum = n;
			this->m_EmpArray = new Worker * [this->m_EmpNum];//这句话很重要，避免了数组为初始化导致的无法访问内存的错误
			//cout << "文件中已有" << n << "份数据" << endl;

			//该函数用于将文件内容添加到数组
			TorF = _init_array();
			if (TorF == 1)
			{
				;
			}
			else
			{
				cout << "数据出错，请检查worK.txt文件" << endl;

				//system("pause");
				while (lock != "chengxuasdasdk#$^$#elibuadasdrangsdasyunsdfsdxing l4564bjjke")
				{
					cout << "请退出系统检查无误再来. . . ";
					cin >> lock;	 //系统卡在这，不让继续使用
				}
			}

			//默认按ID大小排序
			Order_ID();

			//初始化文件为空判断
			this->m_FileEmpty = 1;

			//this->StdOut();
		}
	}
}

//展示菜单的界面
void WorkManager::ShowManue()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//增加职工
void WorkManager::Add_Emp()
{
	cout << "请输入您要添加员工的个数：" << endl;
	int addNum = 0;

	while (true)
	{
		cin >> addNum;
		if (cin.fail())		//C++的验证输入合法性的代码
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "输入不合法，请重试。" << endl;
			continue;
		}
		else if (addNum < 0 || addNum > 9999)
		{
			cout << "输入超出范围，请重试：";
			continue;
		}
		else
			break;
	}
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = addNum + this->m_EmpNum;

		//开辟一个新空间
		Worker** newSpace = new Worker * [newSize]; //用new 开辟一个装Worker*的堆区内存空间，每一个Worker*都成生一个多态，用来代表不同的员工类型

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据；（仅包含ID，姓名，部门编号，工作时长）
		for (int j = 0; j < addNum; j++)
		{

			int id;
			string name;
			int deptid = 1;
			int time;

			int seq_x, seq_y, ab_a;//冒泡排序的内外层循环变量,ab_a是判断断层的变量
			Worker* seq_temp = NULL;
			int ID_a, ID_b;

			//输入ID 的部分
			cout << "请输入职工ID（最大为9999，输入-1，则随机分配一个唯一的ID）：" << endl;
			while (true)
			{
				cin >> id;
				if (cin.fail())		//C++的验证输入合法性的代码
				{
					Clearbuff();
					cout << "输入不合法，请重试。" << endl;
					continue;
				}
				else if (id == -1)
				{
					//int searchID = 0;
					while (true)	//最笨的办法：从小到大遍历已有的ID，选择中间缺少的那些里面最小的；
					{
						//先冒泡排序
						Order_ID();

						if (this->m_EmpNum > 2)
						{
							for (ab_a = 0; ab_a < this->m_EmpNum - 1; ab_a++)
							{
								ID_a = this->m_EmpArray[ab_a]->m_ID;
								ID_b = this->m_EmpArray[ab_a + 1]->m_ID - 1;
								if (ID_a < ID_b)//表明有断层，可插入
								{
									//选择这里面最小的那个数作为新的id；
									id = ID_a + 1;

									//跳出该for循环
									break;
								}
								else
								{

									if (ab_a == this->m_EmpNum - 2)
									{
										id = this->m_EmpNum + 1;
									}
									else
										//id是连续的整数，故继续+1，直到有断层
										continue;
								}

							}
						}
						else if (this->m_EmpNum == 1)
						{
							if (this->m_EmpArray[0]->m_ID != 1)
								id = 1;
							else
								id = 2;
						}
						else if (this->m_EmpNum == 2)
						{
							if (this->m_EmpArray[0]->m_ID == 1)
							{
								if (this->m_EmpArray[1]->m_ID == 2)
									id = 3;
								else
									id = 2;
							}
							else
							{
								if (this->m_EmpArray[1]->m_ID == 1)
									id = (1 + this->m_EmpArray[0]->m_ID) / 2;
								else
								{
									if ((this->m_EmpArray[1]->m_ID > this->m_EmpArray[0]->m_ID - 1) || (this->m_EmpArray[0]->m_ID > this->m_EmpArray[1]->m_ID - 1))
									{
										id = this->m_EmpArray[1]->m_ID + this->m_EmpArray[0]->m_ID - 1 / 2;
									}
									else
									{
										id = (this->m_EmpArray[1]->m_ID > this->m_EmpArray[0]->m_ID) ? this->m_EmpArray[0]->m_ID - 1 : this->m_EmpArray[1]->m_ID - 1;
									}
								}
							}
						}
						else if (this->m_EmpNum == 0)
							id = 1;
						else
							id = 1;
						break;
					}
					break;
				}
				else
				{
					if (this->IsRepeat(id))
					{
						cout << id << "号已有，请重新选择。";
						continue;
					}
					else
					{
						break;
					}
				}
			}

			//输入姓名部分
			cout << "请输入姓名：(输入-1默认以ID为姓名 )" << endl;
			while (true)
			{
				cin >> name;

				if (name == "-1")
				{
					name = std::to_string(id);
					break;
				}
				else
				{
					break;
				}
			}


			//输入工作时长部分.
			cout << "请输入职工工作时长（最大为744，输入-1，则默认160h）：" << endl;
			while (true)
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
					continue;
				}
				else if (time == -1)
				{
					time = 160;
					break;
				}
				else if (time > 744 || time < -1)
				{
					cout << "输入超出范围，请重试：";
					continue;
				}
				else
				{
					break;
				}
			}


			//输入职位部分
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cout << "请输入岗位：(输入-1默认为普通员工 )" << endl;

			Worker* worker = NULL;

			while (true)
			{
				cin >> deptid;
				if (cin.fail())		//C++的验证输入合法性的代码
				{
					while (getchar() != '\n')	//清除缓冲区
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "输入不合法，请重试。" << endl;
					continue;
				}
				if (deptid > 0 && deptid < 4)
				{
					switch (deptid)
					{
					case 1: //普通员工
						worker = new Employee(id, name, 1, time);
						break;
					case 2: //经理
						worker = new Manager(id, name, 2, time);
						break;
					case 3:  //老板
						worker = new Boss(id, name, 3, time);
						break;
					default:
						break;
					}
					break;
				}
				else if (deptid == -1)
				{
					deptid = 1;
					worker = new Employee(id, name, deptid, time);
					break;
				}
				else
				{
					cout << "输入超出范围，请重试：";
					continue;
				}
			}
			newSpace[this->m_EmpNum] = worker;

			//释放原有空间
			//delete[] this->m_EmpArray;

			//更改新空间的指向
			this->m_EmpArray = newSpace;

			//更新新的个数
			this->m_EmpNum += 1;

		}
		//输入循环结束



		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		Order_ID();
		this->save();
		this->m_FileEmpty = 1;
	}
	else if (addNum == 0)
	{
	if (this->m_FileEmpty)
		this->save();
	else
		;
	cout << "您没有添加任何人" << endl;
	}
system("pause");
}

//修改职工信息用增加职工函数重载为修改
void WorkManager::Add_Emp(int idx, int newid)
{

	//输入新数据；（仅包含ID，姓名，部门编号，工作时长）
	int id;
	string name;
	int deptid = 1;
	int time;

	int seq_x, seq_y, ab_a;//冒泡排序的内外层循环变量,ab_a是判断断层的变量
	Worker* seq_temp = NULL;
	int ID_a, ID_b;

	id = newid;

	//输入姓名部分
	cout << "请输入姓名：(输入-1保持不变 )" << endl;
	while (true)
	{
		cin >> name;

		if (name == "-1")
		{
			name = this->m_EmpArray[idx]->m_Name;
			break;
		}
		else
		{
			break;
		}
	}


	//输入工作时长部分.
	cout << "请输入职工工作时长（最大为744，输入-1保持不变）：" << endl;
	while (true)
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
			continue;
		}
		else if (time == -1)
		{
			time = this->m_EmpArray[idx]->m_Time;
			break;
		}
		else if (time > 744 || time < -1)
		{
			cout << "输入超出范围，请重试：";
			continue;
		}
		else
		{
			break;
		}
	}


	//输入职位部分
	cout << "请选择该职工的岗位：" << endl;
	cout << "1、普通职工" << endl;
	cout << "2、经理" << endl;
	cout << "3、老板" << endl;
	cout << "请输入岗位：(输入-1保持不变 )" << endl;

	Worker* worker = NULL;

	while (true)
	{
		cin >> deptid;
		if (cin.fail())		//C++的验证输入合法性的代码
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "输入不合法，请重试。" << endl;
			continue;
		}
		if (deptid > 0 && deptid < 4)
		{
			switch (deptid)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1, time);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2, time);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3, time);
				break;
			default:
				break;
			}
			break;
		}
		else if (deptid == -1)
		{
			deptid = this->m_EmpArray[idx]->m_DeptID;
			worker = new Employee(id, name, deptid, time);
			break;
		}
		else
		{
			cout << "输入超出范围，请重试：";
			continue;
		}
	}

	delete this->m_EmpArray[idx];

	this->m_EmpArray[idx] = worker;
	//提示信息
	cout << "成功修改第" << id << "名职工信息！" << endl;
	Order_ID();

	//this->m_FileEmpty = 1;
	this->save();
	//system("pause");
}

//保存到文件
void WorkManager::save()
{
	//写文件
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << " "
			<< this->m_EmpArray[i]->m_Time << endl;
	}

	ofs.close();



}

//读取文件数量
int WorkManager::GetEmpNum()
{
	int Num = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptid = 1;
	int time;

	while (ifs >> id && ifs >> name && ifs >> deptid && ifs >> time)
	{
		Num++;
	}
	ifs.close();

	return Num;

}

//列表初始化
int WorkManager::_init_array()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptid = 1;
	int time;

	int i = 0;

	while (ifs >> id && ifs >> name && ifs >> deptid && ifs >> time)
	{
		Worker* worker1 = NULL;
		if (id * time < 0 || id > 9999 || time > 744)
		{
			return 0;
		}
		else
		{
			if (deptid == 1)
			{
				worker1 = new Employee(id, name, deptid, time);
			}
			else if (deptid == 2)
			{

				worker1 = new Manager(id, name, deptid, time);
			}
			else if (deptid == 3)
			{
				worker1 = new Boss(id, name, deptid, time);
			}
			else
			{
				return 0;
			}
		}
		this->m_EmpArray[i] = worker1;
		i++;
	}

	for (int i = 0; i < this->m_EmpNum - 1; i++)	//检测文件中的ID是否有重复
	{
		for (int j = 0; j < this->m_EmpNum - i - 1; j++)
		{
			if (this->m_EmpArray[j]->m_ID == this->m_EmpArray[j + 1]->m_ID)
				return 0;
			else
				continue;
		}
	}


	return 1;
}

//显示列表信息函数
void WorkManager::Show()
{
	cout.setf(ios::left);
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int choice_show = 0;//定义选择哪个输出方式
	int error_count = 0;//定义密码错误次数，最多三次

	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//文件存在，但是没有数据记录
		if (ifs.eof())
		{
			cout << "文件存在，但是数据为空" << endl;
			//初始化人数
			this->m_EmpNum = 0;

			//初始化数组指针
			this->m_EmpArray = NULL;
			ifs.close();
			return;
		}
		else
		{
			cout << "查看薪资信息吗？（1、看具体薪资(需输入密码)；2、看默认薪资；3、不看。）" << endl;
			while (true)
			{
				cin >> choice_show;

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
				else if (choice_show == 1)
				{
					string key_show;
					cout << "请输入密码：";
					while (true)
					{
						cin >> key_show;
						if (key_show == "admin")
						{
							for (int i = 0; i < this->m_EmpNum; i++)
							{

								cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
									<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
									<< " 部门编号： " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
									<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time;
								cout << "具体薪资: " << "\t" << setw(5) << this->m_EmpArray[i]->m_Salary << endl;
							}
							error_count = 0;
							break;
						}
						else
						{
							error_count++;
							cout << "密码错误" << error_count << "次。";
							if (error_count < 3)
							{
								cout << "(你还有 " << 3 - error_count << "机会）" << endl;
								continue;
							}
							else
							{
								error_count = 0;
								cout << "哦豁，3次机会已用完，正在重新回到主界面....." << endl;
								system("pause");
								return;
							}
						}
						break;
					}
					break;
				}
				else if (choice_show == 2)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{

						cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
							<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
							<< " 部门编号： " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
							<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time;
						if (this->m_EmpArray[i]->m_DeptID == 1)
							cout << "\t" << setw(5) << "默认薪资: " << Employee_Salary << endl;
						else if (this->m_EmpArray[i]->m_DeptID == 2)
							cout << "\t" << setw(5) << "默认薪资: " << Manager_Salary << endl;
						else if (this->m_EmpArray[i]->m_DeptID == 3)
							cout << "\t" << setw(5) << "默认薪资: " << Boss_Salary << endl;
						else
							cout << " 错误" << endl;
					}
					break;
				}
				else if (choice_show == 3)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
							<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
							<< " 部门编号： " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
							<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time << endl;
					}
					break;
				}
				else
				{
					cout << "输入超出范围，请重试：";
					while (getchar() != '\n')	//清除缓冲区
					{
						cin.clear();
						cin.sync();

						continue;
					}
					continue;
				}

			}
		}
	}
	//system("pause");
}

//格式化输出列表
void WorkManager::StdOut()
{
	cout.setf(ios::left);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
			<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
			<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time << endl;
	}
}

//按ID排序冒泡
void WorkManager::Order_ID()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_ID > this->m_EmpArray[seq_y + 1]->m_ID)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//按ID排序倒序冒泡
void WorkManager::Order_ID_Reverse()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_ID < this->m_EmpArray[seq_y + 1]->m_ID)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//删除职工信息
void WorkManager::Delete()
{
	string key_delete;
	int error_count = 0;
	int id;
	int index = 0;//数组的索引地址
	string goon;

	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "输入管理员密码以继续" << endl;

		while (true)
		{
			cin >> key_delete;
			if (key_delete == "administration")
			{
				//检测是否存在ID号员工
				cout << "请输入你要删除的ID" << endl;
				while (true)
				{
					cin >> id;

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

					if (IsExist(id, &index))
					{
						//把【index】号元素删掉，后面的补齐
						for (int j = index; j < this->m_EmpNum - 1; j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						if (this->m_EmpNum == 0)
							this->m_FileEmpty = 0; //删除后将这个置为0

						this->save();

						cout << "删除成功" << endl;
						break;
					}
					else
					{
						cout << "数据库没有该ID号员工,";
						cout << "继续请按 1 ，其他退出" << endl;
						Clearbuff();

						cin >> goon;
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
						else if (goon == "1")
						{
							Clearbuff();
							cout << "请输入你要删除的ID ";
							continue;
						}
						else
						{
							Clearbuff();
							break;
						}
					}
				}
				error_count = 0;
				break;
			}
			else
			{
				error_count++;
				cout << "密码错误" << error_count << "次。";
				if (error_count < 3)
				{
					cout << "(你还有 " << 3 - error_count << "机会）" << endl;
					continue;
				}
				else
				{
					error_count = 0;
					cout << "哦豁，3次机会已用完，正在重新回到主界面....." << endl;
					system("pause");
					return;
				}
			}
			break;
		}
	}

	system("pause");

}

//ID存在性检测，返回bool类型
bool WorkManager::IsExist(int id, int* idx)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			*idx = i;
			return true;
		}
		else
			continue;

	}
	return false;
}

//修改成员
void WorkManager::Rectify()
{
	int index;
	int id;
	string goon;


	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		system("cls");
		this->Show();
		while (getchar() != '\n')	//清除缓冲区
		{
			cin.clear();
			cin.sync();
			continue;
		}

		cout << "请输入修改职工的编号：" << endl;

		while (true)
		{
			cin >> id;
			if (cin.fail())		//C++的验证输入合法性的代码
			{
				Clearbuff();
				cout << "输入不合法，请重试。" << endl;
			}
			if (IsExist(id, &index))
			{
				//查找到编号的职工

				//delete this->m_EmpArray[index];
				cout << "查到： " << id << "号职工 " << endl;
				this->Add_Emp(index, id);
				break;
			}
			else
			{
				cout << "数据库没有该ID号员工,";
				cout << "继续请按 1 ，其他退出" << endl;
				Clearbuff();

				cin >> goon;
				if (cin.fail())		//C++的验证输入合法性的代码
				{
					Clearbuff();
					cout << "输入不合法，请重试。" << endl;
				}
				else if (goon == "1")
				{
					Clearbuff();
					cout << "请输入你要删除的ID ";
					continue;
				}
				else
				{
					Clearbuff();
					break;
				}
			}
		}
	}
	system("pause");

}

//查找职工
void WorkManager::Find()
{
	string choice;
	int id, index_find = 0;
	int deptid;
	int time;
	string name;

	int idx[MAXLIST];//索引数组
	int num = 0;


	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//选择按1、ID，/2、姓名，3、职工类型，4、工作时长、查找
		while (true)
		{
			cout << "选择按1、ID，2、姓名，3、职工类型，4、工作时长、方式查找" << endl;
			cout << "请选择查找类型： ";
			cin >> choice;
			if (choice == "1")		//按ID
			{

				while (true)
				{
					cout << endl << "请输入您想查找的ID：";
					cin >> id;
					if (cin.fail())		//C++的验证输入合法性的代码
					{
						Clearbuff();
						continue;
						cout << "输入不合法，请重试: " << endl;
					}
					else
					{
						if (IsExist(id, &index_find))//因为ID每个人是唯一的，所以只需要找到一个即可
						{
							cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[index_find]->m_ID
								<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[index_find]->m_Name
								<< " 部门编号： " << "\t" << setw(4) << this->m_EmpArray[index_find]->GetDeptName()
								<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[index_find]->m_Time << endl;
						}
						else
						{
							cout << "抱歉，没找打符合条件的条目" << endl;
							break;
						}
					}
				}
				break;
			}
			else if (choice == "2")		//按姓名
			{
				cout << endl << "请输入您想查找的姓名：";
				while (true)
				{
					cin >> name;
					num = FindName(idx, name);
					if (num > 0)
					{
						cout << "已为您找到 " << num << "个符合您条件的职员，如下所示：" << endl;

						//输出已找到的条目
						for (int i = 0; i < num; i++)
						{
							cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " 部门编号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;
						}
						break;
					}
					else
					{
						cout << "抱歉，没找打符合条件的条目 " << endl;
						break;
					}
				}
				break;
			}
			else if (choice == "3")		//按职工类型
			{
				cout << endl << "请输入您想查找的职工类型：";
				while (true)
				{
					cin >> deptid;

					if (cin.fail())		//C++的验证输入合法性的代码
					{
						Clearbuff();
						continue;
						cout << "输入不合法，请重试: " << endl;
					}
					num = FindDept(idx, deptid);
					if (num > 0)
					{
						cout << "已为您找到 " << num << "个符合您条件的职员，如下所示：" << endl;

						//输出已找到的条目
						for (int i = 0; i < num; i++)
						{
							cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " 部门编号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;

						}
						break;
					}
					else
					{
						cout << "抱歉，没找打符合条件的条目 " << endl;
						break;
					}
				}
				break;
			}
			else if (choice == "4")		//工作时长
			{
				cout << endl << "请输入您想查找的工作时长：";
				while (true)
				{
					cin >> time;
					if (cin.fail())		//C++的验证输入合法性的代码
					{
						Clearbuff();
						continue;
						cout << "输入不合法，请重试: " << endl;
					}
					else if (time < 0 || time > 744)
					{
						cout << "输入超出范围，请重试: " << endl;
						Clearbuff();
						continue;
					}
					num = FindTime(idx, time);
					if (num > 0)
					{
						cout << "已为您找到 " << num << "个符合您条件的职员，如下所示：" << endl;

						//输出已找到的条目
						for (int i = 0; i < num; i++)
						{
							cout << "职工号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " 职工姓名： " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " 部门编号： " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " 工作时长： " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;

						}
						break;
					}
					else
					{
						cout << "抱歉，没找打符合条件的条目 " << endl;
						break;
					}
				}
				break;
			}
			else
			{
				cout << "输入不合法，请重试。" << endl;
				Clearbuff();//清理缓冲区
				continue;
			}
		}
	}
	system("pause");
}

//查找姓名
int WorkManager::FindName(int* idx, string name)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//全部遍历一遍
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			idx[j] = i;
			j++;
			continue;
		}
		else
		{
			continue;
		}
	}
	return j;//返回姓名相同的个数
}

//查找姓名
int WorkManager::FindDept(int* idx, int deptid)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//全部遍历一遍
	{
		if (this->m_EmpArray[i]->m_DeptID == deptid)
		{
			idx[j] = i;
			j++;
			continue;
		}
		else
		{
			continue;
		}
	}
	return j;//返回职工类型相同的个数
}

//查找工作时长
int WorkManager::FindTime(int* idx, int time)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//全部遍历一遍
	{
		if (this->m_EmpArray[i]->m_Time == time)
		{
			idx[j] = i;
			j++;
			continue;
		}
		else
		{
			continue;
		}
	}
	return j;//返回职工类型相同的个数
}

//三种不同方式的排序
void WorkManager::Order_all()
{
	string choice;
	string choiceod;

	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//选择按1、ID，/2、姓名，3、职工类型，4、工作时长、查找
		while (true)
		{
			cout << "请选择排序方式（按1：ID，2：职能部门，3：工作时长）:";
			cin >> choice;
			if (choice == "1")
			{
				this->Order_ID();
				this->Show();
				this->save();
				cout << "是要改为从大到小显示？(y：是，其他：退出)";
				while (true)
				{
					cin >> choiceod;
					if (choiceod == "y")
					{
						system("cls");
						this->Order_ID_Reverse();
						this->Show();
						this->save();
						break;
					}
					else
					{
						//cout << "输入不合法，请重试。" << endl;
						break;
					}
					break;
				}
				break;
			}
			else if (choice == "2")
			{
				this->Order_Deptid();
				this->Show();
				this->save();
				cout << "是要改为从大到小显示？(y：是，其他：退出)";
				while (true)
				{
					cin >> choiceod;
					if (choiceod == "y")
					{
						system("cls");
						this->Order_Deptid_Reverse();
						this->Show();
						this->save();
						break;
					}
					else
					{
						//cout << "输入不合法，请重试。" << endl;
						break;
					}
					break;
				}
				break;
			}
			else if (choice == "3")
			{
				this->Order_Time();
				this->Show();
				this->save();
				cout << "是要改为从大到小显示？(y：是，其他：退出)";
				while (true)
				{
					cin >> choiceod;
					if (choiceod == "y")
					{
						system("cls");
						this->Order_Time_Reverse();
						this->Show();
						this->save();
						break;
					}
					else
					{
						//cout << "。" << endl;
						break;
					}
					break;
				}
				break;
			}
			else
			{
				cout << "输入不合法，请重试。" << endl;
				Clearbuff();//清理缓冲区
				continue;
			}
		}
	}
	system("pause");
}

//按职能部门
void WorkManager::Order_Deptid()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_DeptID > this->m_EmpArray[seq_y + 1]->m_DeptID)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//按职能部门倒序
void WorkManager::Order_Deptid_Reverse()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_DeptID < this->m_EmpArray[seq_y + 1]->m_DeptID)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//按工作时长排序
void WorkManager::Order_Time()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_Time > this->m_EmpArray[seq_y + 1]->m_Time)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//按工作时长排序
void WorkManager::Order_Time_Reverse()
{
	int seq_x, seq_y;
	Worker* seq_temp = NULL;

	for (seq_x = 0; seq_x < this->m_EmpNum - 1; seq_x++)
	{
		for (seq_y = 0; seq_y < this->m_EmpNum - 1 - seq_x; seq_y++)
		{
			if (this->m_EmpArray[seq_y]->m_Time < this->m_EmpArray[seq_y + 1]->m_Time)
			{
				seq_temp = this->m_EmpArray[seq_y];
				this->m_EmpArray[seq_y] = this->m_EmpArray[seq_y + 1];
				this->m_EmpArray[seq_y + 1] = seq_temp;
			}
		}
	}
}

//清除所有
void WorkManager::Emptify()
{
	if (this->m_FileEmpty == 0)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{

		string choice;
		while (true)
		{
			cout << "确认清空？" << endl;
			cout << "1、确认" << endl;
			cout << "2、返回" << endl;
			cin >> choice;
			if (choice == "1")
			{
				//打开模式 ios::trunc 如果存在删除文件并重新创建
				ofstream ofs(FILENAME, ios::trunc);
				ofs.close();
				if (this->m_EmpArray != NULL)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						if (this->m_EmpArray[i] != NULL)
						{
							delete this->m_EmpArray[i];
						}
					}
					this->m_EmpNum = 0;
					delete[] this->m_EmpArray;
					this->m_EmpArray = NULL;
					this->m_FileEmpty = true;
				}
				cout << "清空成功！" << endl;
				break;
			}
			else if (choice == "2")
			{
				cout << "取消清空" << endl;
				break;
			}
			else
			{
				cout << "输入不合法，请重试。" << endl;
				Clearbuff();//清理缓冲区
				continue;
			}
		}
		this->Clearbuff();
		system("pause");
	}
}

//退出程序
void WorkManager::ExitSystem()
{
	cout << "欢迎下次再来，拜拜！" << endl;
	system("pause");
	exit(0);
}

//检测id是否与已有的重复了
bool WorkManager::IsRepeat(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}

//清楚缓冲区
void WorkManager::Clearbuff()
{
	while (getchar() != '\n')	//清除缓冲区
	{
		cin.clear();
		cin.sync();
		continue;
	}
}

//析构函数调用
WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}

