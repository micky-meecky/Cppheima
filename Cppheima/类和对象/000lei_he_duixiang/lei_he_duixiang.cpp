#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;


//*********************��װ ʵ����****************************************************
//�е���ṹ�壬ֻ�����ṹ����Ǳ���������Ǻ��������Կ�����������Ľṹ��
//����Ҫ�����ǣ��ṹ��Ĭ��Ȩ����public�����Ĭ��Ȩ����private��
//ʵ������ ͨ��һ���ഴ��һ������ʵ����һ������ ������verilog HDL������
//���е����Ժ���Ϊͳ��Ϊ��Ա�����ԣ� ��Ա���ԣ���Ա��������Ϊ�� ��Ա��������Ա����

//����һ���� ����װ��
class circle
{
	//����Ȩ��
public:


	//����
	int r;
	//��Ϊ��ͨ��Ϊһ��������
	double perimeter()
	{
		return 2 * PI * r;
	}


};

//���һ��ѧ���࣬������ѧ�ţ����������Ը�ѧ�����Ը�ֵ������ʾ
class student
{
public:				//����һ������Ȩ�ޣ���߰�ȫ��

	string name;
	string num;

public:
	void display()
	{
		cout << "name: " << name << "\tnum: " << num << endl;
	}
	void setname(string Name) //ͨ����Ϊȥ�������Ը�ֵ
	{
		name = Name;
	}
	void setnum(string Num)
	{
		num = Num;
	}
};



//*******************************����Ȩ��******************************************
//����Ȩ�ޣ�public		��Ա �������������
//����Ȩ�ޣ�protected	��Ա ���ڿ��Է��ʣ����ⲻ���Է��� �̳� ���ӿ��Է��ʸ��׵ı�������
//˽��Ȩ�ޣ�private		��Ա ���ڿ��Է��ʣ����ⲻ���Է��� �̳� ���Ӳ����Է��ʸ��׵ı�������
//����һ��������������Ȩ�޵���
class person
{
public:
	string name; //����˭���ܷ���
protected:
	string car;	//���Ǳ�����Ʒ������˭�����Է��ʣ������ӿ��Է���
private:
	string key;	//���п����룬��˽����Ʒ��˭�����ܷ���

//�����ܷ���
public:
	void func()
	{
		name = "����";
		car = "����";
		key = "123456";
	}

};

//*****************************��Ա����˽�л�*********************************************
//�����е�������������˽�л������������ṩ�����Ե����ýӿڣ�
//�ŵ㣺 �����������ö�дȨ�ޣ�����дȨ�ޣ����ǿ��Լ���������ݵ���Ч�ԣ�


//*****************************�������-��װ-����****************************************
//1.�󳤷��������������
//2.��ȫ�ֺ����ͳ�Ա�����ֱ��ж������������Ƿ����

class lover
{
//�ṩ���ýӿ�
public:
	//����Name �ɶ���д���ⲿ�ӿ�
	void SetName(string name)
	{
		Name = name;
	}
	string ReadNname()
	{
		return Name;
	}
	//�������䣬�ɶ���д����������д��ʱ���ж�����ĺ����ԣ�
	void SetAge(int age)
	{
		if (age > 150 || age < 0)
		{
			Age = 0;
			cout << "Are you kidding me ?\nAre you a saint or demon?" << endl;
			
			return;
		}
		else
		{
			Age = age;
		}
	}
	int ReadAge()
	{
		return Age;
	}

	//��������,ֻ��д���ܶ�
	void SetLover(string lover)
	{
		Lover = lover;
	}

//����˽�л�
private: 
	string Name;
	int Age;
	string Lover;
};



int main(void)
{
	//*********************��װ ʵ����****************************************************

	//circle c1; //����һ������
	//c1.r = 10; //�������������Խ��и�ֵ
	//cout << "the perimeter is :" << c1.perimeter() << endl;


	//student st;
	///*st.name = "yyf";
	//st.num = "S20060809000";*/
	//st.setname("yyf");
	//st.setnum("S000000000");

	//st.display();

	//*******************************����Ȩ��**********************************************

	//person p1;
	//p1.name = "����";
	////p1.car = "����";//����


	//*****************************��Ա����˽�л�*********************************************
	lover l1;
	l1.SetName("����");
	l1.SetAge(13);
	l1.SetLover("����Ұ���");
	cout << "name: " << l1.ReadNname() << endl;
	cout << "age: " << l1.ReadAge() << endl;



	system("pause");
	return 0;
}