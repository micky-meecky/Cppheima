#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;
void dis();
void Change_brand(string& a, string& b, string& c);


//����һ�������࣬�ĸ����麯������ĸ�����

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
		cout << "����1" << endl;
	}
	virtual void P2()
	{
		cout << "����2" << endl;
	}
	virtual	void P3()
	{
		cout << "����3" << endl;
	}
	virtual void P4()
	{
		cout << "����4" << endl;
	}
};
class Sp2 : public Process
{
public:
	virtual void P1()
	{
		cout << "����11" << endl;
	}
	virtual void P2()
	{
		cout << "����22" << endl;
	}
	virtual	void P3()
	{
		cout << "����33" << endl;
	}
	virtual void P4()
	{
		cout << "����44" << endl;
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


//�������ʹ�������
class Animal
{
public:
	virtual void Speak() = 0;//����һ�����麯��

	Animal()		//���캯������
	{
		cout << "����Ĺ��캯������" << endl;
	}
	//virtual ~Animal()
	//{
	//	cout << "�����������������" << endl;
	//}
	virtual ~Animal() = 0;//������������

};
Animal::~Animal()//���������ڲ���Ҫ�������ʵ�֣�Ϊ�˱�����һ�������ж�ȡ������Ҫ�ͷŵ�����
{
	cout << "�����������������" << endl;
}
class Cat : public Animal	//����һ������
{
public:
	Cat(string cat)
	{
		CatName = new string(cat);	//����һ���������ж����ڶ����ı���
		cout << "����Ĺ��캯������" << endl;
	}
	virtual void Speak()
	{
		cout << *CatName << "��������������" << endl;
	}

	~Cat()
	{
		cout << "�����������������" << endl;		//��ᷢ�ָ�����û�е������������������������ڴ�й©

		//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
		//��ô���������������һ������������
		//���������������������ͨ������ָ���ͷ��������

		if (this->CatName != NULL)
		{
			delete CatName;				//�ֶ��ͷ�
			CatName = NULL;
		}
	}
private:
	string* CatName;
};
void speak(Animal *animal)	//����һ�������������ָ���������ĺ���,�Բ�����̬
{
	//animal = new Cat("������è");
	animal->Speak();
	delete animal;
}
void test02()
{
	//string s;
	Animal* animal = new Cat("�ӷ�è");
	animal->Speak();
	delete animal;

	cout << "\n" << endl;

	speak(new Cat("��è����"));


}


/*
	��������װ���ԣ�Ҫ�����£�
	������Ҫ��ɲ���Ϊ CPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢�����ײ㣩

	��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo���� ���м�㣩

	�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿڡ������Ѳ㣩

	����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/

//����CPU �������
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

//����GPU �������
class GPU
{
public:
	virtual void gpu() = 0;
	virtual ~GPU() {}
};

//����MEM �������
class MEM
{
public:
	virtual void mem() = 0;
	virtual ~MEM() {}
};

//����Intel������(Intel ������CPUҲ����GPU)
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

//����NVIDIA������
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

//����Sumsung������
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

//����������
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
			c_cpu = new Intel(brand_c);	//������ָ�븳������ָ�������̬
			c_cpu->cpu();
		}
		else if(brand_c == "Nvidia")
		{
			c_cpu = new NVIDIA(brand_c);	//������ָ�븳������ָ�������̬
			c_cpu->cpu();
		}
		else
		{
			cout << brand_c << " CPU is caculating for graphic display ...... " << endl;
		}

		if (brand_g == "Nvidia")
		{
			c_gpu = nvidia;	//������ָ�븳������ָ�������̬
			c_gpu->gpu();
		}
		else if (brand_g == "Intel")
		{
			c_gpu = intel;	//������ָ�븳������ָ�������̬
			c_gpu->gpu();
		}
		else
		{
			cout << brand_g << " GPU is caculating for graphic display ...... " << endl;
		}

		if (brand_m == "Sumsung")
		{
			c_mem = sumsung;//������ָ�븳������ָ�������̬
			c_mem->mem();
		}
		else
		{
			cout << brand_m << " Memory is storing ...... " << endl;
		}
		cout << "\nThe system's state is follow: \n";

		cout << *(intel->brandI_C) << " CPU: " << (int)rand() % (100 - 30 + 1) + 30 << "%" <<endl;//���һ��30-100������ռ����
		cout << *(nvidia->brandN) << " GPU: " << (int)rand() % (100 - 30 + 1) + 30 << "%" << endl;//���һ��30-100������ռ����
		cout << *(sumsung->brandM) << " MEM: " << (int)rand() % (100 - 30 + 1) + 30 << "%" << endl;//���һ��30-100������ռ����

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

//����CPU,GPU,MEM���ǳ����࣬�޷��������󣬵���ָ���ǿ��Եģ���ΪҪ������̬�
	CPU* c_cpu;	
	GPU* c_gpu;
	MEM* c_mem;
};

//����һ����������ʾ
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
	string temp; //��ʱ���������ж����ִ��ǰ�����õ�ַ�ı�����ֵ
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

//�������Ժ���,�е��߼�����(�ѽ��)
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



