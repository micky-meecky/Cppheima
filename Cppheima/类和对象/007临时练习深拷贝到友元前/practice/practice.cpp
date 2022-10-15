#include <iostream>
#include <string>

using namespace std;

class Math 
{
public:

	Math(Math & m)	//����һ���������캯��
	{
		m_A = m.m_A;
		m_B = new int(*m.m_B); //��������һ�����
	}
	~Math()	//����һ����������
	{
		if (m_B != NULL)
		{
			delete m_B;
			m_B = NULL;
		}
	}
	//����һ���вι��캯��
	Math(int a, int b)
	{
		this->m_A = a;
		m_B = new int (b);
	}
	int add(void)//�ӷ�
	{
		return m_A + *m_B;
	}
	int deduct(void)//����
	{
		return m_A > *m_B ?  m_A - *m_B : *m_B - m_A;
	}

public:
	mutable int  m_A;
	int *m_B;
};

class English
{
public:
//�޲ι��캯�� �����������涨�����вι��캯�����������ﲻ������޲ι��캯��
	English()	
	{
		cout << "English ��Ĭ�Ϲ��캯��" << endl;
		m_Word1 = "apple";
	}
	English(string str1)	//�вι��캯��
	{
		cout << "English ���вι��캯��" << endl;
		m_Word1 = "apple";
		m_Word2 = str1;
	}
	string Getword1() 
	{
		return m_Word1;
	}
	string Getword2()
	{
		return m_Word2;
	}
	string Getword3()	//��̬��Ա����ֻ�ܷ���m_Word3
	{
		return m_Word3;
	}

	mutable string m_Word1;
	string m_Word2;
	static string m_Word3;	//��̬��Ա����
};
string English::m_Word3 = "banana";//��̬��Ա���������ʼ��


class Caculus
{
public:
	Caculus(int a,int b,string str):eng(str),mt(a,b)
	{
		cout << "��ʼ���б�" << endl;
	}



	int& GetResult()//�����õķ�ʽ����result�����ص���result[0]��ֵ
	{
		int* result = new int[2];	//����new����һ�����������飬����������ͷ�
		result[0] = mt.add();
		result[1] = mt.deduct();
		/*cout << "result = " << result << " *result = " << *result << endl;
		cout << "result[1] = " << result + 1 << " *result = " << *(result + 1) << endl;*/
		return *result;
	}

	string* GetWords()//��ָ�뷽ʽ���أ����ص���s[0]�ĵ�ַ
	{
		static string s[3] = {eng.Getword1(),eng.Getword2(), eng.Getword3()};//������̬��Ա����������Ա��ⷵ�ؾֲ�������ַ
		return s;
	}
	//������������
	~Caculus()
	{
		
	}
public:
	//int Opt;
	English eng;
	Math mt;
};



int main(void)
{

	//��ϰĿ�ģ���ϰ+��Ϥ��֪ʶ�㣨��ǳ���������캯����thisָ�룬���ã���װ��������
	//����һ��Learning��,��������Ƕ���࣬Math, English.�����캯�������ã�
	//Math������Ӽ�����,�����.�������this)
	//English������������ʳ�ʼ���ʹ�ӡ���������ʼ���б���̬��Ա����,�����󳣺���)

	//������������Ϸ���

	//English e("peach");
	//cout << e.Getword1() << endl;
	Caculus start(2,3,"peach");
	std::cout << "add = " << start.GetResult() << " deduct = " << *(&start.GetResult() + 1) << endl;//ȡ�ڶ���Ԫ�ص�ֵ������ȡַ��ȡֵ�ķ�ʽ��ȡ
	//string *s = start.GetWords();
	std::cout << "word1 = " << *start.GetWords() << endl;
	std::cout << "word2 = " << *(start.GetWords() + 1) << endl;
	std::cout << "word3 = " << *(start.GetWords() + 2) << endl;


	system("pause");
	return 0;
}