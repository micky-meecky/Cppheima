#include "WorkManager.h"

//���캯������
WorkManager::WorkManager()
{

	ifstream ifs;
	string lock = "chngxukazaizheliburangyunxing le";

	ifs.open(FILENAME, ios::in);


	//�ļ������ڣ���ʧ�ܣ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ�Ϊ���ж�
		this->m_FileEmpty = 0;

		ifs.close();
		return;
	}
	else    //�ļ��򿪳ɹ�
	{
		char ch;
		(ifs >> ch);
		//�ļ����ڣ�����û�����ݼ�¼
		if (ifs.eof())
		{
			cout << "�ļ����ڣ���������Ϊ��" << endl;
			//��ʼ������
			this->m_EmpNum = 0;

			//��ʼ������ָ��
			this->m_EmpArray = NULL;

			//��ʼ���ļ�Ϊ���ж�
			this->m_FileEmpty = 0;

			ifs.close();
			return;

		}
		//�ļ����ڣ��Ҵ�������
		else
		{
			//�ú������ڼ���ļ����Ѵ��ڵ��������ݣ���������
			int n = GetEmpNum();
			this->m_EmpNum = n;
			this->m_EmpArray = new Worker * [this->m_EmpNum];//��仰����Ҫ������������Ϊ��ʼ�����µ��޷������ڴ�Ĵ���
			//cout << "�ļ�������" << n << "������" << endl;

			//�ú������ڽ��ļ�������ӵ�����
			TorF = _init_array();
			if (TorF == 1)
			{
				;
			}
			else
			{
				cout << "���ݳ�������worK.txt�ļ�" << endl;

				//system("pause");
				while (lock != "chengxuasdasdk#$^$#elibuadasdrangsdasyunsdfsdxing l4564bjjke")
				{
					cout << "���˳�ϵͳ�����������. . . ";
					cin >> lock;	 //ϵͳ�����⣬���ü���ʹ��
				}
			}

			//Ĭ�ϰ�ID��С����
			Order_ID();

			//��ʼ���ļ�Ϊ���ж�
			this->m_FileEmpty = 1;

			//this->StdOut();
		}
	}
}

//չʾ�˵��Ľ���
void WorkManager::ShowManue()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//����ְ��
void WorkManager::Add_Emp()
{
	cout << "��������Ҫ���Ա���ĸ�����" << endl;
	int addNum = 0;

	while (true)
	{
		cin >> addNum;
		if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "���벻�Ϸ��������ԡ�" << endl;
			continue;
		}
		else if (addNum < 0 || addNum > 9999)
		{
			cout << "���볬����Χ�������ԣ�";
			continue;
		}
		else
			break;
	}
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = addNum + this->m_EmpNum;

		//����һ���¿ռ�
		Worker** newSpace = new Worker * [newSize]; //��new ����һ��װWorker*�Ķ����ڴ�ռ䣬ÿһ��Worker*������һ����̬����������ͬ��Ա������

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������ݣ���������ID�����������ű�ţ�����ʱ����
		for (int j = 0; j < addNum; j++)
		{

			int id;
			string name;
			int deptid = 1;
			int time;

			int seq_x, seq_y, ab_a;//ð������������ѭ������,ab_a���ж϶ϲ�ı���
			Worker* seq_temp = NULL;
			int ID_a, ID_b;

			//����ID �Ĳ���
			cout << "������ְ��ID�����Ϊ9999������-1�����������һ��Ψһ��ID����" << endl;
			while (true)
			{
				cin >> id;
				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					Clearbuff();
					cout << "���벻�Ϸ��������ԡ�" << endl;
					continue;
				}
				else if (id == -1)
				{
					//int searchID = 0;
					while (true)	//��İ취����С����������е�ID��ѡ���м�ȱ�ٵ���Щ������С�ģ�
					{
						//��ð������
						Order_ID();

						if (this->m_EmpNum > 2)
						{
							for (ab_a = 0; ab_a < this->m_EmpNum - 1; ab_a++)
							{
								ID_a = this->m_EmpArray[ab_a]->m_ID;
								ID_b = this->m_EmpArray[ab_a + 1]->m_ID - 1;
								if (ID_a < ID_b)//�����жϲ㣬�ɲ���
								{
									//ѡ����������С���Ǹ�����Ϊ�µ�id��
									id = ID_a + 1;

									//������forѭ��
									break;
								}
								else
								{

									if (ab_a == this->m_EmpNum - 2)
									{
										id = this->m_EmpNum + 1;
									}
									else
										//id���������������ʼ���+1��ֱ���жϲ�
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
						cout << id << "�����У�������ѡ��";
						continue;
					}
					else
					{
						break;
					}
				}
			}

			//������������
			cout << "������������(����-1Ĭ����IDΪ���� )" << endl;
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


			//���빤��ʱ������.
			cout << "������ְ������ʱ�������Ϊ744������-1����Ĭ��160h����" << endl;
			while (true)
			{
				cin >> time;
				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "���벻�Ϸ��������ԡ�" << endl;
					continue;
				}
				else if (time == -1)
				{
					time = 160;
					break;
				}
				else if (time > 744 || time < -1)
				{
					cout << "���볬����Χ�������ԣ�";
					continue;
				}
				else
				{
					break;
				}
			}


			//����ְλ����
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cout << "�������λ��(����-1Ĭ��Ϊ��ͨԱ�� )" << endl;

			Worker* worker = NULL;

			while (true)
			{
				cin >> deptid;
				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "���벻�Ϸ��������ԡ�" << endl;
					continue;
				}
				if (deptid > 0 && deptid < 4)
				{
					switch (deptid)
					{
					case 1: //��ͨԱ��
						worker = new Employee(id, name, 1, time);
						break;
					case 2: //����
						worker = new Manager(id, name, 2, time);
						break;
					case 3:  //�ϰ�
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
					cout << "���볬����Χ�������ԣ�";
					continue;
				}
			}
			newSpace[this->m_EmpNum] = worker;

			//�ͷ�ԭ�пռ�
			//delete[] this->m_EmpArray;

			//�����¿ռ��ָ��
			this->m_EmpArray = newSpace;

			//�����µĸ���
			this->m_EmpNum += 1;

		}
		//����ѭ������



		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
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
	cout << "��û������κ���" << endl;
	}
system("pause");
}

//�޸�ְ����Ϣ������ְ����������Ϊ�޸�
void WorkManager::Add_Emp(int idx, int newid)
{

	//���������ݣ���������ID�����������ű�ţ�����ʱ����
	int id;
	string name;
	int deptid = 1;
	int time;

	int seq_x, seq_y, ab_a;//ð������������ѭ������,ab_a���ж϶ϲ�ı���
	Worker* seq_temp = NULL;
	int ID_a, ID_b;

	id = newid;

	//������������
	cout << "������������(����-1���ֲ��� )" << endl;
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


	//���빤��ʱ������.
	cout << "������ְ������ʱ�������Ϊ744������-1���ֲ��䣩��" << endl;
	while (true)
	{
		cin >> time;
		if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "���벻�Ϸ��������ԡ�" << endl;
			continue;
		}
		else if (time == -1)
		{
			time = this->m_EmpArray[idx]->m_Time;
			break;
		}
		else if (time > 744 || time < -1)
		{
			cout << "���볬����Χ�������ԣ�";
			continue;
		}
		else
		{
			break;
		}
	}


	//����ְλ����
	cout << "��ѡ���ְ���ĸ�λ��" << endl;
	cout << "1����ְͨ��" << endl;
	cout << "2������" << endl;
	cout << "3���ϰ�" << endl;
	cout << "�������λ��(����-1���ֲ��� )" << endl;

	Worker* worker = NULL;

	while (true)
	{
		cin >> deptid;
		if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "���벻�Ϸ��������ԡ�" << endl;
			continue;
		}
		if (deptid > 0 && deptid < 4)
		{
			switch (deptid)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1, time);
				break;
			case 2: //����
				worker = new Manager(id, name, 2, time);
				break;
			case 3:  //�ϰ�
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
			cout << "���볬����Χ�������ԣ�";
			continue;
		}
	}

	delete this->m_EmpArray[idx];

	this->m_EmpArray[idx] = worker;
	//��ʾ��Ϣ
	cout << "�ɹ��޸ĵ�" << id << "��ְ����Ϣ��" << endl;
	Order_ID();

	//this->m_FileEmpty = 1;
	this->save();
	//system("pause");
}

//���浽�ļ�
void WorkManager::save()
{
	//д�ļ�
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

//��ȡ�ļ�����
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

//�б��ʼ��
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

	for (int i = 0; i < this->m_EmpNum - 1; i++)	//����ļ��е�ID�Ƿ����ظ�
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

//��ʾ�б���Ϣ����
void WorkManager::Show()
{
	cout.setf(ios::left);
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int choice_show = 0;//����ѡ���ĸ������ʽ
	int error_count = 0;//�����������������������

	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//�ļ����ڣ�����û�����ݼ�¼
		if (ifs.eof())
		{
			cout << "�ļ����ڣ���������Ϊ��" << endl;
			//��ʼ������
			this->m_EmpNum = 0;

			//��ʼ������ָ��
			this->m_EmpArray = NULL;
			ifs.close();
			return;
		}
		else
		{
			cout << "�鿴н����Ϣ�𣿣�1��������н��(����������)��2����Ĭ��н�ʣ�3����������" << endl;
			while (true)
			{
				cin >> choice_show;

				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					while (getchar() != '\n')	//���������
					{
						cin.clear();
						cin.sync();
						continue;
					}
					cout << "���벻�Ϸ��������ԡ�" << endl;
				}
				else if (choice_show == 1)
				{
					string key_show;
					cout << "���������룺";
					while (true)
					{
						cin >> key_show;
						if (key_show == "admin")
						{
							for (int i = 0; i < this->m_EmpNum; i++)
							{

								cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
									<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
									<< " ���ű�ţ� " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
									<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time;
								cout << "����н��: " << "\t" << setw(5) << this->m_EmpArray[i]->m_Salary << endl;
							}
							error_count = 0;
							break;
						}
						else
						{
							error_count++;
							cout << "�������" << error_count << "�Ρ�";
							if (error_count < 3)
							{
								cout << "(�㻹�� " << 3 - error_count << "���ᣩ" << endl;
								continue;
							}
							else
							{
								error_count = 0;
								cout << "Ŷ��3�λ��������꣬�������»ص�������....." << endl;
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

						cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
							<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
							<< " ���ű�ţ� " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
							<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time;
						if (this->m_EmpArray[i]->m_DeptID == 1)
							cout << "\t" << setw(5) << "Ĭ��н��: " << Employee_Salary << endl;
						else if (this->m_EmpArray[i]->m_DeptID == 2)
							cout << "\t" << setw(5) << "Ĭ��н��: " << Manager_Salary << endl;
						else if (this->m_EmpArray[i]->m_DeptID == 3)
							cout << "\t" << setw(5) << "Ĭ��н��: " << Boss_Salary << endl;
						else
							cout << " ����" << endl;
					}
					break;
				}
				else if (choice_show == 3)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
							<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
							<< " ���ű�ţ� " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
							<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time << endl;
					}
					break;
				}
				else
				{
					cout << "���볬����Χ�������ԣ�";
					while (getchar() != '\n')	//���������
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

//��ʽ������б�
void WorkManager::StdOut()
{
	cout.setf(ios::left);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[i]->m_ID
			<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << "\t" << setw(8) << this->m_EmpArray[i]->GetDeptName()
			<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[i]->m_Time << endl;
	}
}

//��ID����ð��
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

//��ID������ð��
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

//ɾ��ְ����Ϣ
void WorkManager::Delete()
{
	string key_delete;
	int error_count = 0;
	int id;
	int index = 0;//�����������ַ
	string goon;

	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������Ա�����Լ���" << endl;

		while (true)
		{
			cin >> key_delete;
			if (key_delete == "administration")
			{
				//����Ƿ����ID��Ա��
				cout << "��������Ҫɾ����ID" << endl;
				while (true)
				{
					cin >> id;

					if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
					{
						while (getchar() != '\n')	//���������
						{
							cin.clear();
							cin.sync();
							continue;
						}
						cout << "���벻�Ϸ��������ԡ�" << endl;
					}

					if (IsExist(id, &index))
					{
						//�ѡ�index����Ԫ��ɾ��������Ĳ���
						for (int j = index; j < this->m_EmpNum - 1; j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						if (this->m_EmpNum == 0)
							this->m_FileEmpty = 0; //ɾ���������Ϊ0

						this->save();

						cout << "ɾ���ɹ�" << endl;
						break;
					}
					else
					{
						cout << "���ݿ�û�и�ID��Ա��,";
						cout << "�����밴 1 �������˳�" << endl;
						Clearbuff();

						cin >> goon;
						if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
						{
							while (getchar() != '\n')	//���������
							{
								cin.clear();
								cin.sync();
								continue;
							}
							cout << "���벻�Ϸ��������ԡ�" << endl;
						}
						else if (goon == "1")
						{
							Clearbuff();
							cout << "��������Ҫɾ����ID ";
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
				cout << "�������" << error_count << "�Ρ�";
				if (error_count < 3)
				{
					cout << "(�㻹�� " << 3 - error_count << "���ᣩ" << endl;
					continue;
				}
				else
				{
					error_count = 0;
					cout << "Ŷ��3�λ��������꣬�������»ص�������....." << endl;
					system("pause");
					return;
				}
			}
			break;
		}
	}

	system("pause");

}

//ID�����Լ�⣬����bool����
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

//�޸ĳ�Ա
void WorkManager::Rectify()
{
	int index;
	int id;
	string goon;


	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		system("cls");
		this->Show();
		while (getchar() != '\n')	//���������
		{
			cin.clear();
			cin.sync();
			continue;
		}

		cout << "�������޸�ְ���ı�ţ�" << endl;

		while (true)
		{
			cin >> id;
			if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
			{
				Clearbuff();
				cout << "���벻�Ϸ��������ԡ�" << endl;
			}
			if (IsExist(id, &index))
			{
				//���ҵ���ŵ�ְ��

				//delete this->m_EmpArray[index];
				cout << "�鵽�� " << id << "��ְ�� " << endl;
				this->Add_Emp(index, id);
				break;
			}
			else
			{
				cout << "���ݿ�û�и�ID��Ա��,";
				cout << "�����밴 1 �������˳�" << endl;
				Clearbuff();

				cin >> goon;
				if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
				{
					Clearbuff();
					cout << "���벻�Ϸ��������ԡ�" << endl;
				}
				else if (goon == "1")
				{
					Clearbuff();
					cout << "��������Ҫɾ����ID ";
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

//����ְ��
void WorkManager::Find()
{
	string choice;
	int id, index_find = 0;
	int deptid;
	int time;
	string name;

	int idx[MAXLIST];//��������
	int num = 0;


	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//ѡ��1��ID��/2��������3��ְ�����ͣ�4������ʱ��������
		while (true)
		{
			cout << "ѡ��1��ID��2��������3��ְ�����ͣ�4������ʱ������ʽ����" << endl;
			cout << "��ѡ��������ͣ� ";
			cin >> choice;
			if (choice == "1")		//��ID
			{

				while (true)
				{
					cout << endl << "������������ҵ�ID��";
					cin >> id;
					if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
					{
						Clearbuff();
						continue;
						cout << "���벻�Ϸ���������: " << endl;
					}
					else
					{
						if (IsExist(id, &index_find))//��ΪIDÿ������Ψһ�ģ�����ֻ��Ҫ�ҵ�һ������
						{
							cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[index_find]->m_ID
								<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[index_find]->m_Name
								<< " ���ű�ţ� " << "\t" << setw(4) << this->m_EmpArray[index_find]->GetDeptName()
								<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[index_find]->m_Time << endl;
						}
						else
						{
							cout << "��Ǹ��û�Ҵ������������Ŀ" << endl;
							break;
						}
					}
				}
				break;
			}
			else if (choice == "2")		//������
			{
				cout << endl << "������������ҵ�������";
				while (true)
				{
					cin >> name;
					num = FindName(idx, name);
					if (num > 0)
					{
						cout << "��Ϊ���ҵ� " << num << "��������������ְԱ��������ʾ��" << endl;

						//������ҵ�����Ŀ
						for (int i = 0; i < num; i++)
						{
							cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " ���ű�ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;
						}
						break;
					}
					else
					{
						cout << "��Ǹ��û�Ҵ������������Ŀ " << endl;
						break;
					}
				}
				break;
			}
			else if (choice == "3")		//��ְ������
			{
				cout << endl << "������������ҵ�ְ�����ͣ�";
				while (true)
				{
					cin >> deptid;

					if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
					{
						Clearbuff();
						continue;
						cout << "���벻�Ϸ���������: " << endl;
					}
					num = FindDept(idx, deptid);
					if (num > 0)
					{
						cout << "��Ϊ���ҵ� " << num << "��������������ְԱ��������ʾ��" << endl;

						//������ҵ�����Ŀ
						for (int i = 0; i < num; i++)
						{
							cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " ���ű�ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;

						}
						break;
					}
					else
					{
						cout << "��Ǹ��û�Ҵ������������Ŀ " << endl;
						break;
					}
				}
				break;
			}
			else if (choice == "4")		//����ʱ��
			{
				cout << endl << "������������ҵĹ���ʱ����";
				while (true)
				{
					cin >> time;
					if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
					{
						Clearbuff();
						continue;
						cout << "���벻�Ϸ���������: " << endl;
					}
					else if (time < 0 || time > 744)
					{
						cout << "���볬����Χ��������: " << endl;
						Clearbuff();
						continue;
					}
					num = FindTime(idx, time);
					if (num > 0)
					{
						cout << "��Ϊ���ҵ� " << num << "��������������ְԱ��������ʾ��" << endl;

						//������ҵ�����Ŀ
						for (int i = 0; i < num; i++)
						{
							cout << "ְ���ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->m_ID
								<< " ְ�������� " << "\t" << setw(8) << this->m_EmpArray[idx[i]]->m_Name
								<< " ���ű�ţ� " << "\t" << setw(4) << this->m_EmpArray[idx[i]]->GetDeptName()
								<< " ����ʱ���� " << "\t" << setw(3) << this->m_EmpArray[idx[i]]->m_Time << endl;

						}
						break;
					}
					else
					{
						cout << "��Ǹ��û�Ҵ������������Ŀ " << endl;
						break;
					}
				}
				break;
			}
			else
			{
				cout << "���벻�Ϸ��������ԡ�" << endl;
				Clearbuff();//��������
				continue;
			}
		}
	}
	system("pause");
}

//��������
int WorkManager::FindName(int* idx, string name)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//ȫ������һ��
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
	return j;//����������ͬ�ĸ���
}

//��������
int WorkManager::FindDept(int* idx, int deptid)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//ȫ������һ��
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
	return j;//����ְ��������ͬ�ĸ���
}

//���ҹ���ʱ��
int WorkManager::FindTime(int* idx, int time)
{
	int j = 0;
	for (int i = 0; i <= this->m_EmpNum - 1; i++)//ȫ������һ��
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
	return j;//����ְ��������ͬ�ĸ���
}

//���ֲ�ͬ��ʽ������
void WorkManager::Order_all()
{
	string choice;
	string choiceod;

	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//ѡ��1��ID��/2��������3��ְ�����ͣ�4������ʱ��������
		while (true)
		{
			cout << "��ѡ������ʽ����1��ID��2��ְ�ܲ��ţ�3������ʱ����:";
			cin >> choice;
			if (choice == "1")
			{
				this->Order_ID();
				this->Show();
				this->save();
				cout << "��Ҫ��Ϊ�Ӵ�С��ʾ��(y���ǣ��������˳�)";
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
						//cout << "���벻�Ϸ��������ԡ�" << endl;
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
				cout << "��Ҫ��Ϊ�Ӵ�С��ʾ��(y���ǣ��������˳�)";
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
						//cout << "���벻�Ϸ��������ԡ�" << endl;
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
				cout << "��Ҫ��Ϊ�Ӵ�С��ʾ��(y���ǣ��������˳�)";
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
						//cout << "��" << endl;
						break;
					}
					break;
				}
				break;
			}
			else
			{
				cout << "���벻�Ϸ��������ԡ�" << endl;
				Clearbuff();//��������
				continue;
			}
		}
	}
	system("pause");
}

//��ְ�ܲ���
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

//��ְ�ܲ��ŵ���
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

//������ʱ������
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

//������ʱ������
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

//�������
void WorkManager::Emptify()
{
	if (this->m_FileEmpty == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{

		string choice;
		while (true)
		{
			cout << "ȷ����գ�" << endl;
			cout << "1��ȷ��" << endl;
			cout << "2������" << endl;
			cin >> choice;
			if (choice == "1")
			{
				//��ģʽ ios::trunc �������ɾ���ļ������´���
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
				cout << "��ճɹ���" << endl;
				break;
			}
			else if (choice == "2")
			{
				cout << "ȡ�����" << endl;
				break;
			}
			else
			{
				cout << "���벻�Ϸ��������ԡ�" << endl;
				Clearbuff();//��������
				continue;
			}
		}
		this->Clearbuff();
		system("pause");
	}
}

//�˳�����
void WorkManager::ExitSystem()
{
	cout << "��ӭ�´��������ݰݣ�" << endl;
	system("pause");
	exit(0);
}

//���id�Ƿ������е��ظ���
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

//���������
void WorkManager::Clearbuff()
{
	while (getchar() != '\n')	//���������
	{
		cin.clear();
		cin.sync();
		continue;
	}
}

//������������
WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}

