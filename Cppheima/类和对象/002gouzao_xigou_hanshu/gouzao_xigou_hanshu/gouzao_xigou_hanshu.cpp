#include <iostream>
#include <string>

using namespace std;

class Person
{


//1������
//���ղ������з���  �вι��캯��    �޲ι��캯����Ĭ�Ϲ��캯����


public:
	//���캯��
	Person()
	{
		cout << "��ͨ���캯������" << endl;
	}
	//�вι��캯��
	Person(int a)
	{
		age = a;
		cout << "�вι��캯������" << endl;

	}
	
	//�������ͽ��з���  ��ͨ���캯��    �������캯��
	//�������캯��
	//�������캯���ĵ���ʱ��
	//1��ʹ��һ���Ѿ������õĶ�������ʼ����һ������
	//2����ֵ���ݵķ�ʽ �������Ĳ�����ֵ
	//3����ֵ�ķ�ʽ���ؾֲ�����
	Person(const Person &P) //ע��д��
	{
		age = P.age;
		cout << "�������캯������" << endl;
	}
	//��������
	~Person()
	{
		cout << "������������" << endl;
	}
public:
	int age;

};

void test01()
{
	////�޲ι��캯��


	//�вι��캯��
	//���ŷ�
	//Person P1; //����Ĭ�Ϲ��캯����ʱ���ܼ�()����Ϊ���������������������Ϊ�Ǻ�������
	//Person P2(10);
	//Person P3(P2);
	//cout << "P2�����䣺" << P2.age << endl;
	//cout << "P3�����䣺" << P3.age << endl;

	////��ʾ��
	//Person P1;
	//Person P2 = Person(10);
	//Person P3 = Person(P2);
	////Person(10);	//���������ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
	////Person(p5);	//�����Ե��ÿ������캯�� ����ʼ�������������� Person(p5); ��������Ϊ����Ϊ Person p5; 

	//	//��ʽ��
	//Person p6 = 10; // Person p6 = 10; �ȼ���д��  Person p6 = Person(10)
	//Person p7 = p6;




}



int main(void)
{
	//Person P2;
	test01();

	system("pause");
	return EXIT_SUCCESS;
}