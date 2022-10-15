#include <iostream>
#include <string>

using namespace std;

/*
	�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������

��˿��Խ��麯����Ϊ���麯��

���麯���﷨��virtual ����ֵ���� ������ �������б�= 0 ;

���������˴��麯���������Ҳ��Ϊ==������==

�������ص㣺
- �޷�ʵ��������
- ���������д�������еĴ��麯��������Ҳ���ڳ�����

*/

class Base
{
public:
	virtual void func() = 0;//�������麯��
};
class Son:public Base
{
	void func()
	{
		cout << "��д������Ĵ��麯��" << endl;
	}
};




/*
	�ö�̬����ͨ��ʽʵ���������ļ��������
*/
//��ͨ��ʽ,ȱ�㣬��ά���Բ��չ�Եͣ�û�������б仯������Ҫ��֮ǰ��Դ���롣
class Caculator
{
public:
	int add()
	{
		return m_A + m_B;
	}
	int sub()
	{
		return m_A - m_B;
	}
	int mul()
	{
		return m_A * m_B;
	}
public:
	int m_A;
	int m_B;
};
//��̬��̬ʵ�֣�������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
//C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ�
class Caculator2
{
public:

	virtual int cac() //����һ���麯��
	{
		return 0;
	}

	int m_A;
	int m_B;
};
class Add :public Caculator2
{
	int cac()	//��д������麯��
	{
		return m_A + m_B;
	}
};
class Sub :public Caculator2
{
	int cac()
	{
		return m_A - m_B;
	}
};
class Mul :public Caculator2
{
	int cac()
	{
		return m_A * m_B;
	}
};


/*
	��̬��̬ʵ��ԭ��
	��ipad�ʼ�
*/


/*
��̬����ʹ��С�᣺

��̬��������

- �м̳й�ϵ
- ������д�����е��麯��

��̬ʹ������

- �����ָ�������ָ���������

��д����������ֵ����  ������ �����б� ��ȫһ�³�Ϊ��д
*/

class Animal
{
public:
	Animal()
	{

	}

	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};
class Cat : public Animal
{
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Dog : public Animal
{
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};
void Speak(Animal &animal)
{
	animal.speak();
}


/*
	��̬��C++���������������֮һ

��̬��Ϊ����

- ��̬��̬: �������� �� ������������ھ�̬��̬�����ú�����
- ��̬��̬: ��������麯��ʵ������ʱ��̬

��̬��̬�Ͷ�̬��̬����

- ��̬��̬�ĺ�����ַ���  -  ����׶�ȷ��������ַ
- ��̬��̬�ĺ�����ַ���  -  ���н׶�ȷ��������ַ

*/



void test01()
{
	Cat cat;
	Dog dog;
	Speak(cat);
	Speak(dog);
}

void test02()
{
//	Caculator c;
//	c.m_A = 10;
//	c.m_B = 10;
//
//	cout << c.m_A << " + " << c.m_B << " = " << c.add() << endl;
//
//	cout << c.m_A << " - " << c.m_B << " = " << c.sub() << endl;
//
//	cout << c.m_A << " * " << c.m_B << " = " << c.mul() << endl;


	Caculator2* C2 = new Add();
	C2->m_A = 1000;
	C2->m_B = 1000;
	cout << C2->m_A << " + " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;	//����Ҫ�ֶ�����

	C2 = new Sub();
	C2->m_A = 1000;
	C2->m_B = 1000;
	cout << C2->m_A << " - " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;

	C2 = new Mul();
	C2->m_A = 10;
	C2->m_B = 10;
	cout << C2->m_A << " * " << C2->m_B << " = " << C2->cac() << endl;
	delete C2;
}

void test03()
{
	//Base a; // ���ܴ���һ��Base������Ϊ����һ�������ࡣ
	//Son s;
	Base* base = new Son;
	base->func();
	delete base;
}

int main(void)
{
	//test01();
	//test02();
	test03();
	
	system("pause");
	return 0;
}

