#include <iostream>
#include <string>

using namespace std;

/*

	��Ԫ������.
	1.ȫ�ֺ�������Ԫ
	2.��Ա��������Ԫ
	3.������Ԫ

	���г�������������ַ�ʽ��

	��1����Building �п��������ԣ����ԡ�
	��2����girlf����Է����������䡣����3��
	��3����commonf��ֻ�ܷ��ʿ��������ԡ�����2��
	��4����İ����ֻ�ܷ��ʿ���������1��

*/

class Building;
//ע������˳�������и����壺˳������Ҫ�����������ǰ������б��õ���Ҫ��ǰ������


class girlf
{
public:
	girlf();
	void gvisit();//�������������д���������Ϊ�˱���д����������µ�˵building��ʲôʲôû����Ĵ�����
private:
	Building* building;
};

class commonf
{
public:
	commonf();
	void cvisit();

private:
	Building* buildingc;
};
class Building
{
	
	friend class girlf;
	friend void commonf::cvisit();
	friend void stranger();

public:
	Building();
public:
	string m_Room_setting;
private:
	string m_Room_mbed;
	string m_Room_sbed;
};
Building::Building()
{
	this->m_Room_setting = "����";
	this->m_Room_sbed = "����";
	this->m_Room_mbed = "����";
}
girlf::girlf()
{
	this->building = new Building;
}
commonf::commonf()
{
	this->buildingc = new Building;
}

void girlf::gvisit()
{
	cout << "girlfriend��ͨ��������Ԫ����" << building->m_Room_setting << endl;
	cout << "girlfriend��ͨ��������Ԫ����" << building->m_Room_sbed << endl;
	cout << "girlfriend��ͨ��������Ԫ����" << building->m_Room_mbed << endl;
}
void commonf::cvisit()
{
	cout << "commonfriend��ͨ��������Ԫ����" << buildingc->m_Room_setting << endl;
	cout << "commonfriend��ͨ��������Ԫ����" << buildingc->m_Room_sbed << endl;
	cout << "commonfriend��ͨ��������Ԫ����" << buildingc->m_Room_mbed << endl;
}
void stranger()
{
	Building building;
	cout << "stranger��ͨ��������Ԫ����" << building.m_Room_setting << endl;
	cout << "stranger��ͨ��������Ԫ����" << building.m_Room_sbed << endl;
}
void test1()
{
	girlf girlfriend;
	commonf commonfriend;
	girlfriend.gvisit();
	cout << endl;
	commonfriend.cvisit();
	cout << endl;
	stranger();
	cout << endl;
}
int main(void)
{
	test1();
	system("pause");
	return 0;
}