#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//����ѧ���ṹ��
	struct stu {
		string name;
		int age;
		int score;
	};
//�����ʦ�ṹ��
	struct teacher
	{
		int id;
		string name;
		int age;
		stu student;
	};
//����1��ѧ���ṹ�嶨��
	struct stt
	{
		string name1;
		int score1;
	};
//����1�Ľ�ʦ�ṹ�嶨�壻ע��һ��Ҫ�������Ƕ�׽ṹ��д��ǰ�棬��ΪC/C++�Ǵ��е�
	struct teacher1
	{
		string name1;
		struct stt st11[5];
	};


void jiegoutishuzu(void);
void jiegoutizhizhen(void);
void jiegoutiqiantao(void);
void jiegoutihanshu(void);
void zhichuandi(stu p);
void zhizhenchuandi(const stu* po);
void jiegoutianli1(void);
void shuruhanshu(teacher1 tea1[], int len);
void printinfo(const teacher1* tea1, int len);

int main(void)
{
	srand((unsigned int)time(NULL));
	//jiegoutishuzu();
	//jiegoutizhizhen();
	//jiegoutiqiantao();
	//jiegoutihanshu();
	jiegoutianli1();


	system("pause");
	return 0;
}

//�ṹ�����飻
void jiegoutishuzu(void)
{


	struct stu stuar[3] =
	{
		{"li",18,20},
		{"da",10,21},
		{"ade",45,52}
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "\tname:  " << stuar[i].name
			<< "\tage:   " << stuar[i].age
			<< "\tscore: " << stuar[i].score << endl;
	}

}
//�ṹ��ָ��
void jiegoutizhizhen(void)
{
	//�����ṹ��������Ҹ���ֵ
	 stu s = { "����", 8,100 };
	//ͨ��ָ��ָ��ṹ�����
	 stu * p = &s;
	 //ͨ��ָ����ʽṹ���������
	 cout << "\tname:  " << p->name
		 << "\tage:  " << p->age
		 << "\tscore:  " << p->score << endl;
}
//�ṹ��Ƕ��
void jiegoutiqiantao(void)
{
	teacher t;
	t.id = 1;
	t.name = "�ܲ�";
	t.age = 50;
	t.student.age = 10;
	t.student.name = "����";
	t.student.score = 99;

	cout << "\tname: " << t.name
		<< "\tid: " << t.id
		<< "\tage: " << t.age << endl
		<< "\tstudent's name:  " << t.student.name
		<< "\tstudent's age:  " << t.student.age
		<< "\tstudent's score:  " << t.student.score << endl;

}
//�ṹ�庯��+�ṹ��const
void jiegoutihanshu(void)
{
	stu t1 = { "lal",1,1 };
	zhichuandi(t1);
	cout << endl;
	zhizhenchuandi(&t1);

}
void zhichuandi(stu p)
{
	cout << "\tname: " << p.name
		<< "\tage: " << p.age
		<< "\tscore: " << p.score << endl;
}
void zhizhenchuandi(const stu* po)
{ 
	//po->age = 100;	//������Ϊpo�Ǹ�const��ָ�롣 
	cout << "\tname: " << po->name
		<< "\tage: " << po->age
		<< "\tscore: " << po->score << endl;
}

//�ṹ�尸��1
void jiegoutianli1(void)
{
	teacher1 t1[3] = {
	};

	int len = sizeof(t1) / sizeof(t1[0]);

	shuruhanshu(t1,len); //�ṹ��������ֵ���ݷ�ʽ��������ʼ��
	printinfo(t1,len);	//�ṹ�������õ�ַ���ݷ�ʽ��ӡ

}
void shuruhanshu(teacher1 tea1[],int len)
{
	string namear1 = "XYZ";
	string namear2 = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tea1[i].name1 = "Mr.";
		tea1[i].name1 += namear1[i];
		for (int j = 0; j < 5; j++)
		{
			tea1[i].st11[j].name1 = "std";
			tea1[i].st11[j].name1 += namear2[j];
			tea1[i].st11[j].score1 = rand() % 61 + 40;
		}
	}
}
void printinfo(const teacher1 *tea1, int len)//��const���������ʱ����Ľṹ���������ֵ
{
	cout << "tname: \t  " ;
	cout << "stname: \t";
	cout << "score: "<<endl;
	for (int k = 0; k < len; k++)
	{
		cout << "  " << (tea1 + k)->name1 << "\t\t";
		//for (int k1 = 0; k1 < len; k1++)
		//{
	
			for (int l = 0; l < 5; l++)
			{
				cout << (((tea1 + k)->st11) + l)->name1 << "\t\t";
				cout << (((tea1 + k)->st11) + l)->score1 << "\t";
				cout << endl << "\t\t";
			}
			cout << endl ;
		//}
		
	}
	cout << endl;

	/*
	���������£�
tname:    stname:       score:
  Mr.X          stdA            95
				stdB            99
				stdC            100
				stdD            89
				stdE            84

  Mr.Y          stdA            55
				stdB            43
				stdC            64
				stdD            87
				stdE            57

  Mr.Z          stdA            93
				stdB            58
				stdC            95
				stdD            81
				stdE            85 
*/
}










