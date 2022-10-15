#include <iostream>
#include <string>

using namespace std;
//��ϰ����Ԫ�������ͣ���������أ�������+/-,==,=,(),<<,++;����������ʽ���
//����+��-��++��--�����������㣬
//�������()��α������<<ʵ�֣����Ҽ��ж������== 
//������Ԫ��ȫ�ֺ������࣬��Ա����(ע���Ա���������Ķ���˳���ر�ؼ����������ͻᱨ��)

class Caculate;
class Readab
{
public:
	Readab();
	void read1();

private:
	Caculate* cac;
};

class Caculate
{
	//friend class Readab;
	friend void Readab::read1();
	friend ostream& operator<<(ostream &cout, Caculate& p);
	friend void test01(void);
public:
	Caculate(int a, int b)
	{
		m_A = new int(a);
		m_B = new int(b);
	}

	//���ڵĶ�ȡ��Ա����
	void read1()
	{
		cout << "m_A = " << *this->m_A << "m_B = " << *this->m_B << endl;
	}
	//�Ӽ��˳����������
	Caculate& operator+(Caculate& p)
	{
		Caculate *temp1a = new Caculate(0,0);
		*temp1a->m_A = *this->m_A + *p.m_A;
		*temp1a->m_B = *this->m_B + *p.m_B;
		return *temp1a;
	}
	Caculate& operator-(Caculate& p)
	{
		Caculate *temp1d = new Caculate(0, 0);

		if(*this->m_A > *p.m_A)
			*temp1d->m_A = *this->m_A - *p.m_A;
		else 
			*temp1d->m_A = *p.m_A - *this->m_A;

		if (*this->m_B > *p.m_B)
			*temp1d->m_B = *this->m_B - *p.m_B;
		else 
			*temp1d->m_B = *p.m_B - *this->m_B;
		return *temp1d;
	}
	Caculate& operator*(Caculate& p)
	{
		Caculate *temp1m = new Caculate(0, 0);
		*temp1m->m_A = *this->m_A * *p.m_A;
		*temp1m->m_B = *this->m_B * *p.m_B;
		return *temp1m;
	}
	Caculate& operator/(Caculate& p)
	{
		Caculate *temp1a = new Caculate(0, 0);
		*temp1a->m_A = *this->m_A / *p.m_A;
		*temp1a->m_B = *this->m_B / *p.m_B;
		return *temp1a;
	}


	//�����Լ�����������ú���
	//ǰ��������
	Caculate& operator++()
	{
		(*this->m_A)++;
		(*this->m_B)++;
		return *this;
	}
	//ǰ���Լ���
	Caculate& operator--()
	{
		(*this->m_A)--;
		(*this->m_B)--;
		return *this;
	}
	//��������
	Caculate& operator++(int)
	{
		Caculate *temp2a = new Caculate(*this);
		*temp2a->m_A = *this->m_A;
		*temp2a->m_B = *this->m_B;
		(*this->m_A)++;
		(*this->m_B)++;
		return *temp2a;
	}

	//�����Լ�
	Caculate& operator--(int)
	{
		Caculate* temp2d = new Caculate(*this);
		*temp2d->m_A = *this->m_A;
		*temp2d->m_B = *this->m_B;
		(*this->m_A)--;
		(*this->m_B)--;
		return *temp2d;
	}

	//==,!=,>=,<=
	bool operator==(Caculate &p)
	{
		return *this->m_A == *p.m_A && *this->m_B == *p.m_B ? true : false;
	}
	bool operator!=(Caculate& p)
	{
		return *this->m_A != *p.m_A || *this->m_B != *p.m_B ? true : false;
	}
	bool operator>=(Caculate& p)
	{
		return *this->m_A >= *p.m_A && *this->m_B >= *p.m_B ? true : false;
	}
	bool operator<=(Caculate& p)
	{
		return *this->m_A <= *p.m_A && *this->m_B <= *p.m_B ? true : false;
	}

	//=��ֵ����
	Caculate& operator=(Caculate& p1)
	{
		if (this->m_A != NULL)
		{
			delete this->m_A;
			this->m_A = NULL;
		}
		if (this->m_B != NULL)
		{
			delete this->m_B;
			this->m_B = NULL;
		}

		this->m_A = new int(*p1.m_A);
		this->m_B = new int(*p1.m_B);
		return *this;
	}
	
	//��������
	void operator()()
	{
		cout << "************* ()���ع������" << endl;
		std::cout << "\t\t\tm_A = " << *this->m_A << " m_B = " << *this->m_B << endl;
	}

	//��������
	~Caculate()
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
		if (m_B != NULL)
		{
			delete m_B;
			m_B = NULL;
		}
	}

private:
	int *m_A;
	int *m_B;

};
Readab::Readab()
{
	cac = new Caculate(12, 12);//������ΪʲôҪ���������������������cac�أ�
}

void Readab::read1()
{
	cout << "cac's A = " << *cac->m_A << " cac's B = " << *cac->m_B << endl;
}


ostream& operator<<(ostream &cout,Caculate &p)
{
	cout << "m_A = " << *p.m_A << " m_B = " << *p.m_B << endl;
	return cout;
}


void test01(void)
{
	Caculate C1(1, 2);
	Caculate C2(1, 1);
	Caculate C3(1, 0);
	//if (C2 >= C3)
	//	cout << "C2 >= C3" << endl;
	//else 
	//	cout << "C2 <= C3" << endl;

	//cout << ++C2 << endl;
	cout << C2 << endl;
	C2++;
	cout << C2 << endl;
	C2--;
	cout << C2 << endl;
	++C2;
	cout << C2 << endl;
	--C2;
	cout << C2 << endl;
	C3 = C1;
	cout << C3 << endl;
	C3 = (C2 - C1);		//����ע���ڼӼ��˳�����������У����صľֲ��������벻����ջ�ϣ�
	cout << C3 << endl;
	C3();
	Caculate(0,100)();//����һ����������
	Readab r;
	r.read1();

}


int main(void)
{

	test01();


	system("pause");
	return 0;
}



