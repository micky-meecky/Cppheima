#include <iostream>
#include <string>

using namespace std;

/*
	�̳��﷨�� class <������> : <�̳з�ʽ> <������>{};

	�̳з�ʽ������
	1.public �������������Լ̳У�ԭ�ⲻ��
	2.protected ������public��protected��������ȫ��Ϊprotected���Ե�������
	3.private ��������public,protected ��������ȫ��Ϊprivate���Ե�������
	4.ע�⣬�����е�private���������޷����ʵģ����������ּ̳з�ʽ�����Ƕ���̳У�Ҳ���Ǽ̳��˸�û����������п�
*/



/*
	�鿴������ģ�ͣ�
	1.�����ȴ��������������cpp��
	2.Ȼ���ڿ�ʼ��VS�Ŀ���������ʾ������
	3.��λ����ǰ�����̷���
	4.cd /·����
	5.cl /d1 reportSingleClassLayoutSon "�����ļ���" �س�����
*/

/*
	���������˳�򣺹��������и��ף����ж��ӣ�
*/

/*
	�̳���ͬ���ĳ�Ա���� 
	���ͨ������Ķ�����ʸ���ͬ����Ա��������Ҫ�Ӹ�������S.Base::m_A
	���ͨ������Ķ�����ʸ���ͬ����Ա��������Ҫ�Ӹ�������S.Base::m_A

	1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
	2. ����������������Է��ʵ�����ͬ����Ա
	3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������
	*/

/*
	��̬��Ա�ͷǾ�̬��Ա����ͬ��
	ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������
	ע�⾲̬��Ա������Ҫ���������������ʼ��
	���ھ�̬��Ա�����ַ��ʷ�ʽ��
	1.ͨ���������
	2.ͨ������ֱ�ӷ���
	*/


/*
	��̳У��﷨��ʽ��class <������> : <�̳з�ʽ> <������>��<�̳з�ʽ> <������> ... {};
	���ڲ�ͬ������ͬ����Ա���������з���ʱΪ�˱�����ֶ����ԣ�Ӧ����������
*/

/*
	���μ̳е����⣺
	1. ��̳��˶�������ݣ���ͬ���̳��˶�������ݣ���������ʹ������ʱ���ͻ���������ԡ�
	2. ������̳��Զ�������ݼ̳������ݣ���ʵ����Ӧ������������������ֻ��Ҫһ�ݾͿ��ԡ�
	1.�ý�����������ڼ���
	2.���ý������Ҫ��virtual�����м������������̳У���ʱ�����ĸ����������ࡣ
	��̳У��̳еĲ������ݣ�����vbptr��ָ�룩ָ��vbtable
*/
class Base
{
public:
	Base()
	{
		m_A = 100;
		m_A1 = 100;
		m_Al = 300;
		//cout << "����Ĺ��캯��" << endl;
	}
	~Base()
	{
		//cout << "�������������" << endl;
	}
	void func()
	{
		cout << "�����func����" << endl;
	} 
	void func(int )//�������Ǹ������γ�����
	{
		cout << "�����func����+int" << endl;
	}
	static void func1()
	{
		cout << "����ľ�̬func����" << endl;
	}
public:
	int m_A;
	static int m_SA;
	int m_A1;
	int m_Al;
protected:
	int m_B;
private:
	int m_C;
};
int Base::m_SA = 100;

class Base1
{
public:
	Base1()
	{
		m_A1 = 111;
	}

	int m_A1;
};

class Son :virtual public Base//��̳У��̳еĲ������ݣ�����vbptr��ָ�룩ָ��vbtable
{
public:
	Son()
	{
		m_A = 200;
		//cout << "����Ĺ��캯��" << endl;
	}
	~Son()
	{
		//cout << "�������������" << endl;
	}

	static void func1()
	{
		cout << "����ľ�̬func����" << endl;
	}

	void func()
	{
		cout << "�����func����" << endl;
	}
	
public:
	static int m_SA;
	int m_D;
	int m_A;
};
int Son::m_SA = 200;

class Son1 :virtual public Base, public Base1 //��̳У��̳еĲ������ݣ�����vbptr��ָ�룩ָ��vbtable
{

};

class Son2 :public Son, public Son1
{
	//���μ̳��������
};

void test01()
{
	Son S;

	cout << "Son's A = " << S.m_A << endl;
	cout << "Base's A = " << S.Base::m_A << endl;
	//cout << "sizeofSon = " << sizeof(Son) << endl;
	S.func();
	S.Base::func();
	//S.func(100)
	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
	S.Base::func(100);
}

void test02()
{
	Son S1;

	//��̬ͬ����Ա����
	//���֣�1.ͨ�������������
	cout << "//1.ͨ�������������" << endl;
	cout << "Son's m_SA = " << S1.m_SA << endl;
	cout << "Base's m_SA = " << S1.Base::m_SA << endl;
	//2.ͨ��������������
	cout << "//2.ͨ���������������" << endl;
	cout << "Son's m_SA = " << Son::m_SA << endl;
	//��һ��::�������������ʣ��ڶ���::����Base�������µ�
	cout << "Base's m_SA = " << Son::Base::m_SA << endl;
	//��̬ͬ����Ա����
	//���֣�1.ͨ���������
	cout << "//1.ͨ���������" << endl;
	S1.func1();
	S1.Base::func1();

	//2.ͨ����������
	cout << "//1.ͨ�����������" << endl;
	Son::func1();
	Son::Base::func1();


}

void test03()
{
	Son1 S1;
	cout << "Son1's Base's m_A1 = " << S1.Base::m_A1 << endl;
	cout << "Son1's Base1's m_A1 = " << S1.Base1::m_A1 << endl;

	cout << endl << "------------------- ���μ̳� --------------------" << endl;

	Son2 S2;//�������μ̳У������m_Al��Ȼ����û�б�����������������ڲ���ȷ��
	S2.Son::m_Al = 180;
	S2.Son1::m_Al = 280;
	cout << "Son's m_Al = " << S2.Son::m_Al << endl;
	cout << "Son1's m_Al = " << S2.Son1::m_Al << endl;
	cout << "Son's m_Al = " << S2.m_Al << endl;
}

int main(void)
{
	//test01();	//�̳��﷨����ʽ������ģ��
	//test02();	//�̳���������˳�򣬾�̬��Ǿ�̬ͬ����Ա�Ĵ���
	test03();	//��̳У����μ̳�

	system("pause");
	return 0;
}