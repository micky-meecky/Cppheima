#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;
void dis();
void Change_brand(string& a, string& b, string& c);


//定义一个抽象类，四个纯虚函数输出四个步骤

class Process
{
public:
	virtual void P1() = 0;
	virtual void P2() = 0;
	virtual void P3() = 0;
	virtual void P4() = 0;
	void Start()
	{
		P1();
		P2();
		P3();
		P4();
	}
};
class Sp1 : public Process
{
public:
	virtual void P1()
	{
		cout << "步骤1" << endl;
	}
	virtual void P2()
	{
		cout << "步骤2" << endl;
	}
	virtual	void P3()
	{
		cout << "步骤3" << endl;
	}
	virtual void P4()
	{
		cout << "步骤4" << endl;
	}
};
class Sp2 : public Process
{
public:
	virtual void P1()
	{
		cout << "步骤11" << endl;
	}
	virtual void P2()
	{
		cout << "步骤22" << endl;
	}
	virtual	void P3()
	{
		cout << "步骤33" << endl;
	}
	virtual void P4()
	{
		cout << "步骤44" << endl;
	}
};
void maketea(Process* p)
{
	p->Start();
	delete p;

}
void test()
{
	maketea(new Sp1);
	maketea(new Sp2);
}


//虚析构和纯虚析构
class Animal
{
public:
	virtual void Speak() = 0;//定义一个纯虚函数

	Animal()		//构造函数调用
	{
		cout << "父类的构造函数调用" << endl;
	}
	//virtual ~Animal()
	//{
	//	cout << "父类的析构函数调用" << endl;
	//}
	virtual ~Animal() = 0;//纯虚析构函数

};
Animal::~Animal()//纯虚析构内部需要具体代码实现，为了避免万一父类中有堆取数据需要释放的问题
{
	cout << "父类的析构函数调用" << endl;
}
class Cat : public Animal	//定义一个子类
{
public:
	Cat(string cat)
	{
		CatName = new string(cat);	//定义一个在子类中定义在堆区的变量
		cout << "子类的构造函数调用" << endl;
	}
	virtual void Speak()
	{
		cout << *CatName << "在喵喵喵。。。" << endl;
	}

	~Cat()
	{
		cout << "子类的析构函数调用" << endl;		//这会发现根本就没有调用子类的析构函数，会造成内存泄漏

		//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
		//怎么解决？给基类增加一个虚析构函数
		//虚析构函数就是用来解决通过父类指针释放子类对象

		if (this->CatName != NULL)
		{
			delete CatName;				//手动释放
			CatName = NULL;
		}
	}
private:
	string* CatName;
};
void speak(Animal *animal)	//定义一个将父类的引用指向子类对象的函数,以产生多态
{
	//animal = new Cat("警长黑猫");
	animal->Speak();
	delete animal;
}
void test02()
{
	//string s;
	Animal* animal = new Cat("加菲猫");
	animal->Speak();
	delete animal;

	cout << "\n" << endl;

	speak(new Cat("黑猫警长"));


}


/*
	案例：组装电脑，要求如下：
	电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）（底层）

	将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商 （中间层）

	创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口。（消费层）

	测试时组装三台不同的电脑进行工作
*/

//创建CPU 抽象基类
class CPU
{
public:
	CPU()
	{
		//cout << "CPU begins to caculate ......" << endl;
	}
	virtual void cpu() = 0;
	virtual ~CPU(){}
};

//创建GPU 抽象基类
class GPU
{
public:
	virtual void gpu() = 0;
	virtual ~GPU() {}
};

//创建MEM 抽象基类
class MEM
{
public:
	virtual void mem() = 0;
	virtual ~MEM() {}
};

//创建Intel厂商类(Intel 即生产CPU也生产GPU)
class Intel:public CPU,public GPU
{
	friend class Computer;
public:

	Intel(string b)
	{
		brandI_C = new string(b);
		brandI_G = new string(b);
	}

	virtual void cpu()
	{
		cout << "Intel" << " CPU is caculating ...... " << endl;
	}
	virtual void gpu()
	{
		cout <<  "Intel" << " GPU is caculating for graphic display ...... " << endl;
	}

	~Intel()
	{
		if (brandI_C != NULL)
		{
			delete brandI_C;
			brandI_C = NULL;
		}
		if (brandI_G != NULL)
		{
			delete brandI_G;
			brandI_G = NULL;
		}
	}
private:
	string* brandI_C;
	string* brandI_G;
};

//创建NVIDIA厂商类
class NVIDIA :public GPU, public CPU
{
	friend class Computer;
public:

	NVIDIA(string b)
	{
		brandN = new string(b);
	}

	virtual void gpu()
	{
		cout << "NVIDIA" << " GPU is caculating for graphic display ...... " << endl;
	}
	virtual void cpu()
	{
		cout << "NVIDIA" << " GPU is caculating for graphic display ...... " << endl;
	}

	~NVIDIA()
	{
		if (brandN != NULL)
		{
			delete brandN;
			brandN = NULL;
		}
	}
private:
	string* brandN;
};

//创建Sumsung厂商类
class Sumsung :public MEM
{
	friend class Computer;
public:

	Sumsung(string b)
	{
		brandM = new string(b);
	}

	virtual void mem()
	{
		cout << "Sumsung" << " Memory is storing ...... " << endl;
	}

	~Sumsung()
	{
		if (brandM != NULL)
		{
			delete brandM;
			brandM = NULL;
		}
	}
private:
	string* brandM;
};

//创建电脑类
class Computer
{
public:
	Computer(string *cpu_b, string *gpu_b, string *mem_b)
	{
		brand_c = *cpu_b;
		brand_g = *gpu_b;
		brand_m = *mem_b;

		intel = new Intel(brand_c);
		nvidia = new NVIDIA(brand_g);
		sumsung = new Sumsung(brand_m);
	}
	void Working()
	{
		cout << "PC is working on ......" << endl;
		if (brand_c == "Intel")
		{
			c_cpu = new Intel(brand_c);	//将对象指针赋给父类指针产生多态
			c_cpu->cpu();
		}
		else if(brand_c == "Nvidia")
		{
			c_cpu = new NVIDIA(brand_c);	//将对象指针赋给父类指针产生多态
			c_cpu->cpu();
		}
		else
		{
			cout << brand_c << " CPU is caculating for graphic display ...... " << endl;
		}

		if (brand_g == "Nvidia")
		{
			c_gpu = nvidia;	//将对象指针赋给父类指针产生多态
			c_gpu->gpu();
		}
		else if (brand_g == "Intel")
		{
			c_gpu = intel;	//将对象指针赋给父类指针产生多态
			c_gpu->gpu();
		}
		else
		{
			cout << brand_g << " GPU is caculating for graphic display ...... " << endl;
		}

		if (brand_m == "Sumsung")
		{
			c_mem = sumsung;//将对象指针赋给父类指针产生多态
			c_mem->mem();
		}
		else
		{
			cout << brand_m << " Memory is storing ...... " << endl;
		}
		cout << "\nThe system's state is follow: \n";

		cout << *(intel->brandI_C) << " CPU: " << (int)rand() % (100 - 30 + 1) + 30 << "%" <<endl;//随机一个30-100的运行占用率
		cout << *(nvidia->brandN) << " GPU: " << (int)rand() % (100 - 30 + 1) + 30 << "%" << endl;//随机一个30-100的运行占用率
		cout << *(sumsung->brandM) << " MEM: " << (int)rand() % (100 - 30 + 1) + 30 << "%" << endl;//随机一个30-100的运行占用率

	}

	~Computer()
	{
		if (intel != NULL)
		{
			delete intel;
			intel = NULL;
		}
		if (sumsung != NULL)
		{
			delete sumsung;
			sumsung = NULL;
		}
		if (nvidia != NULL)
		{
			delete nvidia;
			nvidia = NULL;
		}

		
	}
private:
	Intel *intel;
	Sumsung *sumsung;
	NVIDIA *nvidia;

	string brand_c;
	string brand_g;
	string brand_m;

//由于CPU,GPU,MEM都是抽象类，无法创建对象，但是指针是可以的，因为要产生多态嘛！
	CPU* c_cpu;	
	GPU* c_gpu;
	MEM* c_mem;
};

//创建一个类用于显示
class Display
{
public:
	void display()
	{
		cout << "There are three different elements which is produced by different company respectively! " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "Companies:    " << "Intel     " << "Sumsung   " << "NVIDIA    " << endl;
		cout << "Elements:     " << "CPU       " << "GPU       " << "Memory    " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

	}
};

void dis()
{
	ofstream ofs2;
	ofs2.open("test03.txt", ios::app);
	string C_cpu, C_gpu, C_mem, C_other;
	string sure;
	C_cpu = "Intel";
	C_gpu = "Nvidia";
	C_mem = "Sumsung";
	C_other = "Kingston";

	Display display;
	display.display();
	system("pause");
 
	cout << endl << "please enter the brand you want: (\" q! \" to just go on)";
	ofs2 << endl << "please enter the brand you want: (\" q! \" to just go on)";
	ofs2.close();

	Change_brand(C_cpu, C_gpu, C_mem);
	ofs2.open("test03.txt", ios::app);
	cout << endl << "test begin: The 1st computers are generating ......" << endl;
	ofs2 << endl << "test begin: The 1st computers are generating ......" << endl;
	system("pause");
	system("cls");
	display.display();

	Computer C1(&C_cpu, &C_gpu, &C_mem);
	C1.Working();

	ofs2 << endl << "please enter the brand you want: (\" q! \"  to just go on)";
	cout << endl << "please enter the brand you want: (\" q! \"  to just go on)";
	ofs2.close();
	Change_brand(C_cpu, C_gpu, C_mem);

	ofs2.open("test03.txt", ios::app);
	ofs2 << endl << "test begin: The 2nd computers are generating ......" << endl;
	cout << endl << "test begin: The 2nd computers are generating ......" << endl;
	system("pause");
	system("cls");
	display.display();

	Computer C2(&C_cpu, &C_gpu, &C_mem);
	C2.Working();

	ofs2 << endl << "please enter the brand you want: (\" q! \"  to just go on)";
	cout << endl << "please enter the brand you want: (\" q! \"  to just go on)";
	ofs2.close();
	Change_brand(C_cpu, C_gpu, C_mem);
	ofs2.open("test03.txt", ios::app);
	ofs2 << "please enter the brand you want: " << endl;
	ofs2 << endl << "test begin: The 3rd computers are generating ......" << endl;
	cout << "please enter the brand you want: " << endl;
	cout << endl << "test begin: The 3rd computers are generating ......" << endl;
	system("pause");
	system("cls");
	display.display();

	Computer C3(&C_cpu, &C_gpu, &C_mem);
	C3.Working();
	ofs2.close();
}

void Change_brand(string &a,string &b,string &c)
{
	ofstream ofs1;
	ofs1.open("test03.txt", ios::app);
	string temp; //临时变量储存判断语句执行前的引用地址的变量的值
	temp = a;
	cout << endl << "CPU brand: ";
	ofs1 << endl << "CPU brand: ";
	cin >> temp;
	if (temp != "q!")
	{
		a = temp;
	}
	else
		return;
	
	temp = b;
	cout << endl << "GPU brand: ";
	ofs1 << endl << "GPU brand: ";
	cin >> temp;
	if (temp != "q!")
	{
		b = temp;
	}
	else
		return;

	temp = c;
	cout << endl << "MEM brand: ";
	ofs1 << endl << "MEM brand: ";
	cin >> temp;
	if (temp != "q!")
	{
		c = temp;
	}
	else
		return;
	ofs1.close();

}

//创建测试函数,有点逻辑混乱(已解决)
void test03()
{
	srand((unsigned)time(0));

	ofstream ofs;
	ofs.open("test03.txt",ios::app);
	
	{
		ofs << "There are three different elements which is produced by different company respectively! " << endl;
		ofs << "---------------------------------------------------------------------------------------" << endl;
		ofs << "Companies:    " << "Intel     " << "Sumsung   " << "NVIDIA    " << endl;
		ofs << "Elements:     " << "CPU       " << "GPU       " << "Memory    " << endl;
		ofs << "---------------------------------------------------------------------------------------" << endl;
	}


	string C_cpu, C_gpu, C_mem, C_other;
	string sure;
	C_cpu = "Intel";
	C_gpu = "Nvidia";
	C_mem = "Sumsung";
	C_other = "Kingston";


	cout << "You can enter any brand whatever brand you want: (y to go on / n to quit)";
	ofs << "You can enter any brand whatever brand you want: (y to go on / n to quit)";
	cout << endl;
	while (true)
	{
		cin >> sure;

		if (sure == "y")
		{
			while (getchar() != '\n')
				continue;
			dis();
			break;
		}
		else if (sure == "n")
		{
			cout << endl << "bye!" << endl;
			ofs << endl << "bye!" << endl;
			while (getchar() != '\n')
				continue;
			break;
		}
		else
		{
			while (getchar() != '\n')
				continue;
			cout << "There is not the exit option." << endl;
			cout << "****************Please try again!********" << endl;
			ofs << "There is not the exit option." << endl;
			ofs << "****************Please try again!********" << endl;
			continue;
		}
	}
	
	ofs.close();
}

int main(void)
{
	//test();
	//test02();
	test03();


	system("pause");

	return 0;

}



