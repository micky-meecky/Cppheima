#include<iostream>
#include<string>

using namespace std;


//��������أ���ע��������������������أ�Ҳ���������������أ����ǲ��������������Ͷ��������������أ�
//	1.+������	p1.operator+��&p����Ϊ p1 + p, Ҳ��������������
//	2.<<���������	���������������أ���Ϊ�޷��������ʱP���ұߵ�ϰ�ߣ�
//	3.++/--��������� ��������õ���������Ĺ��̣���Ϊǰ�úͺ��ã�
//	4.=���������  ���´���������ʵ�飬�����Զ����ٵ���������ʵ����=��ֵ���������ֵ����������˵������������ǳ����֮��
//				  ������ͻ�����ڴ��ظ��ͷŵ�����. ��ֵ����� operator=, �����Խ���ֵ����,��������Ա��д�����ɱ������Զ���
//				  �����캯��һ����
//	5.��ϵ�����==����	(�����)
//	6.�������������()����	(��������Ĵ������º���)

class Person
{
	friend Person operator+(Person& p1, Person& p2);
	friend ostream& operator<<(ostream& cout, Person& p);
	friend Person operator+(Person& p1, int num);
	friend Person& operator++(Person& p, int);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
	//��Ա������ʽ
	Person operator-(Person& p)
	{
		Person temp(0,0);
		temp.m_A = this->m_A - p.m_A;
		temp.m_B = this->m_B - p.m_B;
		return temp;
	}
	//ǰ��++�����
	Person& operator++()
	{
		m_A++;
		return *this;//���ﷵ�ص����Լ����������
	}
	//ǰ��--�����
	Person& operator--()
	{
		m_A--;
		return *this;//���ﷵ�ص����Լ����������
	}
	//����++�����
	//Person& operator++(int)
	//{
	//	Person *temp = new Person(*this);//������һ������temp����ʱ�����ڶ������Ϳ��Է������Լ��ˣ�
	//	temp->m_B = this->m_B;
	//	this->m_B++;
	//	return *temp;//���ﷵ�ص�����ʱ������Ȼ�������������õķ�ʽ�����ˣ�������Ȼ���صĲ����Լ����޷�������ʽ������
	//}

	//����--���������
		Person& operator--(int)
	{
		Person *temp = new Person(*this);//������һ������temp����ʱ�����ڶ������Ϳ��Է������Լ��ˣ�
		temp->m_B = this->m_B;
		this->m_B;
		return *temp;//���ﷵ�ص�����ʱ������Ȼ�������������õķ�ʽ�����ˣ�������Ȼ���صĲ����Լ����޷�������ʽ������
	}


private:
	int m_A;
	int m_B;

};

class Integer
{
	friend void test_fuzhi();
public:
	Integer(int num)
	{
		m_Num = new int(num);
	} 
	//��ֵ=����
	Integer& operator=(const Integer &pp)
	{
		//�������ж�this���m_Num�Ƿ�Ϊ�գ����������ͷ���˵
		if (m_Num != NULL)
		{
			delete m_Num;
			m_Num = NULL;
		}
		//����������и�ֵ����
		this->m_Num = new int(*pp.m_Num);
		return *this;
	}
	
	//��ϵ==����
	bool operator==(Integer &pp)
	{
		//if (this->m_Num == pp.m_Num)
			return this->m_Num == pp.m_Num ? true : false;
	}

	//����()����
	void operator()(int a,int b)
	{
		cout << "a = " << a << " b = " << b << endl;
	}


	~Integer()
	{
		if (m_Num != NULL)
		{
			delete m_Num;
			m_Num = NULL;
		}
	}

private:
	int *m_Num;
};
//ȫ�ֺ���ʵ�ֵ�+��������� 
Person operator+(Person &p1, Person &p2)
{
	Person temp(0,0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//+��������� ���Է����������� 
Person operator+(Person& p1, int num)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
//++���������
Person& operator++(Person &p, int)
{
	Person* temp = new Person(p);//������һ������temp����ʱ�����ڶ������Ϳ��Է������Լ��ˣ�
	temp->m_B = p.m_B;
	p.m_B++;
	return *temp;//���ﷵ�ص�����ʱ������Ȼ�������������õķ�ʽ�����ˣ�������Ȼ���صĲ����Լ����޷�������ʽ������
}
// <<���������
ostream& operator<<(ostream &cout, Person &p)
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test_jia()
{
	Person P1(10,10);
	Person P2(20,20);
	cout << P1 << endl;
	cout << P2 << endl;
	Person P3 = P1 + P2;
	cout << P3 << endl;
	Person P4 = P1 - P2;
	cout << P4 << endl;
	Person P5 = P1 + 100;
	++(++P5);
	cout << P5 << endl;
	cout << (P5++)++ << endl;
	cout << P5 << endl;
	cout << P5 << endl;
}

void test_fuzhi()
{
	Integer PP1(10);
	Integer PP2(20);
	Integer PP3(15);
	PP2 = PP1 = PP3;
	cout << "m_Num = " << *PP1.m_Num << " " << endl;
	cout << "m_Num = " << *PP2.m_Num << " " << endl;
	bool a;
	a = PP1 == PP2;
	cout << noboolalpha << a << endl;
	PP1(1, 2);//�ر��������ã�����ʵ���ǣ����Գ���Ϊ�º�����
	//����һ������������Ϊ�������вι��캯�������Բ������Ĭ�Ϲ��캯���������ڴ������������ʱ����Ҫ����(20);
	Integer(20)(20, 30);
}

int main(void)
{
	test_jia();
	test_fuzhi();

	system("pause");
	return 0;
}





