#include <iostream>
#include <string>

using namespace std;
//�����Ա�����������࣬һ��person��һ��phone��������̬��Ա�뺯����


//��̬��Ա�����ص㣺
	//1 �ڱ���׶η����ڴ�
	//2 ���������������ʼ��
	//3 ���ж�����ͬһ������

//phone ��
class Phone
{
public:

	Phone(string brand) :Brand(brand) {}//��ʼ���б��൱�ڵ����вι��캯��
	//������̬����
	static void fun1()
	{
		Price = 10086;
	}

	static int Price;
	string Brand;
private:
	static void fun2()
	{
		cout << "˽�еľ�̬��Ա��������" << endl;
	}
	static int a;
};
int Phone::Price = 8848;

//person��
class Person
{
public:

	Person(string name,string p_brand): Name(name),P_Brand(p_brand){}
	
	//����
	string Name;

	//�ֻ�Ʒ��
	Phone P_Brand;

};



void test1()
{
	//1��ͨ��������ʾ�̬��Ա����
	Person P("����", "��ΪP60");
	cout << P.Name << "����" << P.P_Brand.Brand << ", " << Phone::Price << "Ԫ" << endl; //����������ʼ��������ͻᱨ��
	P.P_Brand.fun1(); 
	//P.P_Brand.fun2();
	cout << P.Name << "����" << P.P_Brand.Brand << ", " << P.P_Brand.Price << "Ԫ" << endl;

	//2.ͨ�����������������
	cout << P.Name << "����" << P.P_Brand.Brand << ", " << Phone::Price << "Ԫ" << endl;
}


int main(void)
{
	test1();

	system("pause");
	return 0;
}