#include <iostream>
using namespace std;


class Person
{
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person()
	{
		cout << "��ͨ���캯��" << endl;
	}
	//�в������캯��
	Person(int age,int height)
	{
		Height = new int(height);//��ʱHeight�ڶ���������������Ҫ����Ա�ֶ�delete��
		Age = age;
		cout << "�вι��캯��" << endl;
	}
	//�������캯��
	Person(const Person &p)
	{
		Age = p.Age;
		//Height = p.Height; //ǳ���� -- ����ͬһ��������ַ�ڴ��ظ��ͷţ��Ƿ�������
		Height = new int(*p.Height);//����� -- ��������������ַ��Ÿ�����������ԣ������ͷŸ��Եĵ�ַ
		cout << "�������캯��" << endl;
	}
	//��������
	~Person()
	{
		if (Height != NULL)
		{
			delete Height;
			Height = NULL;//�������Ұָ��
		}
		cout << "��������" << endl;
	}

	int Age;
	int* Height;


};

void test01()
{
	Person P3;			//Ĭ�Ϲ��캯������д��Person P3(); ��������������Ϊ��д���Ǹ�����
	Person P1(18,160);	//���ŷ������вι��캯��
	Person P2(P1);		//���ŷ����ÿ������캯��
	cout << "P1�������ǣ� " << P1.Age << "P1������ǣ�" << *P1.Height << endl;
	cout << "P2�������ǣ� " << P2.Age << "P2������ǣ�" << *P2.Height << endl;
}

int main(void)
{
	test01();

	system("pause");
	return 0;
}
//����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ������������ֹǳ�������������⣻

