#include <iostream>
#include <string>
#include "IDmanagement.h"

using namespace std;

//1.manuel display
//2.input id
//3.show id
//4.rectify id
//5.delete id
//6.clear system(confirm needed)
//0.exit system





int main() {

	int select = 0,sure; //����ѡ�����, ȷ���˳�����
	showMenu();	//��ʾ�˵�

	books abs; //����һ��ͨѶ¼�ṹ�壬���а������1000����person�ṹ��
	abs.m_size = 0;	//��ʼ������������ֵ

	cout << "please choose a option number to continue: " << endl;

	cin >> select; 
		while (true)
		{
			if (select <= 5 && select >= 0)
			{
				switch (select)
				{
				case 1:
					addinfo(&abs);
					showMenu();	//��ʾ�˵�
					cout << endl;
					showid(&abs);
					cout << "please choose a option number to continue: " << endl;
					cout << endl;
					cin >> select;
					continue;
				case 2:
					showid1(&abs);
					showMenu();	//��ʾ�˵�
					cout << endl;
					showid(&abs);
					cout << "please choose a option number to continue: " << endl;
					cout << endl;
					cin >> select;
					continue;
				case 3:
					rectify(&abs);
					showMenu();	//��ʾ�˵�
					cout << endl;
					showid(&abs);
					cout << "please choose a option number to continue: " << endl;
					cout << endl;
					cin >> select;
					continue;
				case 4:
					deleteid(&abs);
					showMenu();	//��ʾ�˵�
					cout << endl;
					showid(&abs);
					cout << "please choose a option number to continue: " << endl;
					cout << endl;
					cin >> select;
					continue;
				case 5:
					abs.m_size = 0;
					cout << "clear system successfully!! " << endl;
					system("pause");
					system("cls");
					showMenu();	//��ʾ�˵�
					cout << endl;
					showid(&abs);
					cout << "please choose a option number to continue: " << endl;
					cout << endl;
					cin >> select;
					continue;
				case 0:
					sure = exitf();
					if (sure != 0)
					{
						system("pause");

						return 0;
					}
					else if(sure == 0)
					{
						system("cls");
						showMenu();	//��ʾ�˵�
						cout << endl;
						showid(&abs);
						cout << "please choose a option number to continue: " << endl;
						cout << endl;
						cin >> select;
						continue;
					}
				default: break;
				}
			}
			else
			{
				cout << "There is not the option." << endl;
				cout << "****************Please try again!********" << endl;
				while (getchar() != '\n')
					continue;
				cin >> select;
				continue;
			}
			break;

		}

		cout << "There is not the option." << endl;

	system("pause");

	return 0;
}
