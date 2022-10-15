#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//定义学生结构体
	struct stu {
		string name;
		int age;
		int score;
	};
//定义教师结构体
	struct teacher
	{
		int id;
		string name;
		int age;
		stu student;
	};
//案例1的学生结构体定义
	struct stt
	{
		string name1;
		int score1;
	};
//案例1的教师结构体定义；注意一定要将里面的嵌套结构体写在前面，因为C/C++是串行的
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

//结构体数组；
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
//结构体指针
void jiegoutizhizhen(void)
{
	//创建结构体变量并且赋初值
	 stu s = { "张三", 8,100 };
	//通过指针指向结构体变量
	 stu * p = &s;
	 //通过指针访问结构体变量数据
	 cout << "\tname:  " << p->name
		 << "\tage:  " << p->age
		 << "\tscore:  " << p->score << endl;
}
//结构体嵌套
void jiegoutiqiantao(void)
{
	teacher t;
	t.id = 1;
	t.name = "曹操";
	t.age = 50;
	t.student.age = 10;
	t.student.name = "李四";
	t.student.score = 99;

	cout << "\tname: " << t.name
		<< "\tid: " << t.id
		<< "\tage: " << t.age << endl
		<< "\tstudent's name:  " << t.student.name
		<< "\tstudent's age:  " << t.student.age
		<< "\tstudent's score:  " << t.student.score << endl;

}
//结构体函数+结构体const
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
	//po->age = 100;	//报错，因为po是个const的指针。 
	cout << "\tname: " << po->name
		<< "\tage: " << po->age
		<< "\tscore: " << po->score << endl;
}

//结构体案例1
void jiegoutianli1(void)
{
	teacher1 t1[3] = {
	};

	int len = sizeof(t1) / sizeof(t1[0]);

	shuruhanshu(t1,len); //结构体数组用值传递方式将变量初始化
	printinfo(t1,len);	//结构体数组用地址传递方式打印

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
void printinfo(const teacher1 *tea1, int len)//用const避免输出的时候更改结构体变量的数值
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
	输出结果如下：
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










