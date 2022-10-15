#include <iostream>
#include <string>
#include <math.h>
#include "class_Point.h"
#include "class_Circle.h"
#include "class_Cube.h"

using namespace std;

//�Ѿ�ע���˵�class Point

//class Point
//{
//public:
//	void Setx(double x)
//	{
//		Point_x = x;
//	}
//	void Sety(double y)
//	{
//		Point_y = y;
//	}
//	double Getx()
//	{
//		return Point_x;
//	}
//	double Gety()
//	{
//		return Point_y;
//	}
//
//private:
//	double Point_x;
//	double Point_y;
//};

//�Ѿ�ע���˵�class Circle

//class Circle
//{
//public:
//	void Setr(double r)
//	{
//		Cir_r = r;
//	}
//	void Setc(Point center)
//	{
//		Cir_Centre = center; //����������㸳ֵ���뱻��ֵ����ͬһ�ֱ�������
//	}
//	double Getr()
//	{
//		return Cir_r;
//	}
//	Point Get_center()
//	{
//		return Cir_Centre;
//
//	}
//
////���ԣ�
//private:
//	double Cir_r;//radius 
//	Point Cir_Centre;//Բ������
//};

void center_point(Point p, Circle c)
{
	//�������Բ���������ľ����ж�
	//�ù�ʽ(x - xc)2 + (y - yc)2 > cr2?�ж�
	double x1, y1;
	x1 = (p.Getx() - c.Get_center().Getx()) * (p.Getx() - c.Get_center().Getx());
	y1 = (p.Gety() - c.Get_center().Gety()) * (p.Gety() - c.Get_center().Gety());
	if ((x1 + y1) == (c.Getr() * c.Getr()))
	{
		cout << "�õ���Բ��" << endl;
	}
	else if ((x1 + y1) < (c.Getr() * c.Getr()))
	{
		if ((x1 + y1) != 0)
			cout << "�õ���Բ��,�Ҳ���Բ�ġ�" << endl;
		else
			cout << "�õ���Բ���غϡ�" << endl;
	}
	else if ((x1 + y1) > (c.Getr() * c.Getr()))
	{
		cout << "�õ���Բ�⡣" << endl;
		cout << "�Ҹõ���Բ�ľ���Ϊ��" << sqrt(x1 + y1) - c.Getr() << endl;
	}
}
void example_2()
{	
	//��������
	Point P;
	Point Center;
	Circle C;
	double cx, cy, r, px, py;
	cout << "please enter your circle center's axis:  " << endl;
	//����x����֤��Ϸ���
	while (true)
	{
		
		if (cin >> cx) //isdigit()ֻ�����ַ��ͱ���
		{
			cout << endl << "the input of x = " << cx << " .\nPlease enter the y: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	//����y����֤��Ϸ���
	while (true)
	{
		if (cin >> cy)
		{
			cout << endl << "the input of y = " << cy << " .\nPlease enter the r: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	//����r����֤��Ϸ���
	while (true)
	{
		
		if (cin >> r)
		{
			cout << endl << "the input of r = " << r << " .\nPlease enter the point's x: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	//����px����֤��Ϸ���
	while (true)
	{
	
		if (cin >> px)
		{
			cout << endl << "the input of r = " << px << " .\nPlease enter the point's y: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	//����py����֤��Ϸ���
	while (true)
	{
		
		if (cin >> py)
		{
			cout << endl << "the input of r = " << py << " .\n";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}

	//��ֵ������
	P.Setx(px);
	P.Sety(py);
	C.Setr(r);
	Center.Setx(cx);
	Center.Sety(cy);
	C.Setc(Center);

	center_point(P, C);
	system("pause");
}


//�Ѿ�ע���˵�class Cube

//class Cube
//{
//public:
//	void SetLength(double length)
//	{
//		if (length < 0.0)
//		{
//			cout << "your input is illegal" << endl;
//			return;
//		}
//		else
//			Length = length;
//	}
//	void SetWidth(double width)
//	{
//		if (width < 0.0)
//		{
//			cout << "your input is illegal" << endl;
//			return;
//		}
//		else
//			Width= width;
//	}
//	void SetHight(double hight)
//	{
//		if (hight < 0.0)
//		{
//			cout << "your input is illegal" << endl;
//			return;
//		}
//		else
//			Hight = hight;
//	}
//
//	double GetLength()
//	{
//		return Length;
//	}
//	double GetWidth()
//	{
//		return Width;
//	}
//	double GetHight()
//	{
//		return Hight;
//	}
//	double GetArea()
//	{
//		return Area = 2 * (Length * Width + Length * Hight + Width * Hight);
//	}
//	double GetVolume()
//	{
//		return Length * Width * Hight;
//	}
//	//��Ա�жϺ���
//	int Compare_cy(Cube& c2)
//	{
//		int i, j,k,l;
//
//		double c11[3], c22[3], temp1 = 0, temp2 = 0;
//
//		c11[0] = GetLength();
//		c11[1] = GetWidth();
//		c11[2] = GetHight();
//
//
//		c22[0] = c2.GetLength();
//		c22[1] = c2.GetWidth();
//		c22[2] = c2.GetHight();
//
//		for (i = 0; i < 3; i++)
//		{
//			for (j = 0; j < 3 - i - 1; j++)
//			{
//				if (c11[j] > c11[j + 1])
//				{
//					temp1 = c11[j + 1];
//					c11[j + 1] = c11[j];
//					c11[j] = temp1;
//				}
//				if (c22[j] > c22[j + 1])
//				{
//					temp2 = c22[j + 1];
//					c22[j + 1] = c22[j];
//					c22[j] = temp2;
//				}
//			}
//		}
//		for (k = 0, l = 0; k < 3; k++)
//		{
//			if (c11[k] == c22[k])
//				l++;	//ÿ��һ������l��һ��
//			else
//				return 0;
//		}
//		if (l == 2)//��l����2ʱ����ζ��������һ���ı߳����򷵻�1����˼������һ���ģ�
//			return 1;
//	}
//
//private:
//	double Length;
//	double Width;
//	double Hight;
//	double Area;
//	double Volume;
//};

//ȫ������Բ�ıȽϺ���
int Compare(Cube& c1, Cube& c2)//���ܸı䳤��ߵ�ֵ����Ҫ��ʡ�����ڴ棬��������
{
	int i, j;
	//int a, b;
	int k, l;
	i = 0;
	j = 0;
	double c11[3], c22[3], temp1 = 0, temp2 = 0;
	//��ֵ��
	c11[0] = c1.GetLength();
	c11[1] = c1.GetWidth();
	c11[2] = c1.GetHight();

	c22[0] = c2.GetLength();
	c22[1] = c2.GetWidth();
	c22[2] = c2.GetHight();

	//���ı��ֵ������
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 - i - 1; j++)
		{
			if (c11[j] > c11[j + 1])
			{
				temp1 = c11[j + 1];
				c11[j + 1] = c11[j];
				c11[j] = temp1;
			}
			if (c22[j] > c22[j + 1])
			{
				temp2 = c22[j + 1];
				c22[j + 1] = c22[j];
				c22[j] = temp2;
			}
		}
	}
	//����Ϊ���Դ��룬�������Ƿ�������
	//cout << endl << "c11 = ";
	//for (a = 0; a < 3; a++)
	//{
	//	cout << c11[a] << "\t";
	//}
	//cout << endl << "c22 = ";
	//for (b = 0; b < 3; b++)
	//{
	//	cout << c22[b] << "\t";
	//}
	//cout << endl;

	for (k = 0,l = 0; k < 3; k++)
	{
		if (c11[k] == c22[k])
			l++;
		else
			return 0;
	}
	if (l == 2)
		return 1;
}

//����example_1����һ������bug��û�м������ĺϷ���
void example_1(void)
{
	Cube c1;
	double l1,w1,h1;
	cout << "please enter your cube parameter of length: " << endl << "\t";
	//cin >> l1;
	while (true)
	{
		if (cin >> l1)
		{
			cout << endl << "the input of l1 = " << l1 << " .\nPlease enter the point's w1: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c1.SetLength(l1);
	cout << "please enter your cube parameter of width: " << endl << "\t";
	while (true)
	{
		if (cin >> w1)
		{
			cout << endl << "the input of w1 = " << w1 << " .\nPlease enter the point's h1: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c1.SetWidth(w1);
	cout << "please enter your cube parameter of hight: " << endl << "\t";
	while (true)
	{
		if (cin >> h1)
		{
			cout << endl << "the input of h1 = " << h1 << " .\n";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c1.SetHight(h1);
	cout << endl << "your cube's parameters is follow: " << endl << endl;
	cout << "length = " << l1 << "\t";
	cout << "width =  " << w1 << "\t";
	cout << "hight =  " << h1 << "\t" << endl << endl;

	cout <<"please wait for caculating..." << endl;
	system("pause");
	cout << endl << "\tThe area = " << c1.GetArea() << "\tThe volume = " << c1.GetVolume() << endl;


	Cube c2;
	double l2, w2, h2;
	cout << "please enter your second cube parameter of length: " << endl << "\t";
	while (true)
	{
		if (cin >> l2)
		{
			cout << endl << "the input of l2 = " << l2 << " .\nPlease enter the point's w2: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c2.SetLength(l2);
	cout << "please enter your second cube parameter of width: " << endl << "\t";
	while (true)
	{
		if (cin >> w2)
		{
			cout << endl << "the input of r = " << w2 << " .\nPlease enter the point's h2: ";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c2.SetWidth(w2);
	cout << "please enter your second cube parameter of hight: " << endl << "\t";
	while (true)
	{
		if (cin >> h2)
		{
			cout << endl << "the input of h2 = " << h2 << " .\n";
			break;
		}
		else
		{
			cout << endl << "your input is not leagal,Pls try again: ";
			cin.clear();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	c2.SetHight(h2);
	cout << endl << "your second cube's parameters is follow: " << endl << endl;
	cout << "length = " << l2 << "\t";
	cout << "width =  " << w2 << "\t";
	cout << "hight =  " << h2 << "\t" << endl << endl;

	cout << "please wait for caculating..." << endl;
	system("pause");
	cout << endl << "\tThe area = " << c2.GetArea() << "\tThe volume = " << c2.GetVolume() << endl;

	//ȫ���жϺ���,����Ҫ��������������ĳ����˳�򣬹���Ҫ����Ƚϣ�
	
		int tf1;
		tf1 = Compare(c1,c2);//���ܸı䳤��ߵ�ֵ����Ҫ��ʡ�����ڴ棬��������
		system("pause");
		if (tf1)
		{
			cout << endl <<  "�����÷�ʽ���ݲ��������ȽϺ�����ʾ��" << "c1 �� c2" << "��һ���������塣" << endl;
		}
		else 
			cout << endl << "�����÷�ʽ���ݲ��������ȽϺ�����ʾ��" << "c1 �� c2" << "��������һ���������塣" << endl;
		cout << "\nGood bye!" << endl;

	//��Ա�жϺ���,����Ҫ��������������ĳ����˳�򣬹���Ҫ����Ƚϣ�
		int tf2;
		tf2 =c1.Compare_cy(c2);//���ܸı䳤��ߵ�ֵ����Ҫ��ʡ�����ڴ棬��������
		system("pause");
		if (tf2)
		{
			cout << endl << "�ó�Ա������ʾ��" << "c1 �� c2" << "��һ���������塣" << endl;
		}
		else
			cout << endl << "�ó�Ա������ʾ��" << "c1 �� c2" << "��������һ���������塣" << endl;
		cout << "\nGood bye!" << endl;
}

void menul()
{
	cout << "************************** Welcome to my caculus. ************************" << endl;
	cout << "************************** y1 for Cube caculation ************************" << endl;
	cout << "************************** y2 for Circle caculation ************************" << endl;
	cout << "************************** exit() for Circle caculation ************************" << endl;
}

int main(void)
{
	menul();

	string i = "y";
	while (1) 
	{
		cout << "Please choose a project to go ahead." << endl << "\t>>>>";
		if (cin >> i && (i == "y1" || i == "y2"))
		{
			if (i == "y1")
			{
				//����1 ����������ࣺ ����������������������ȫ�ֺ����ͳ�Ա�����ֱ�ʵ�ֶ������������Ƿ�һ�������жϣ�
				string opt1;
				while (1)
				{
					cout << "****************************************    y1    ********************************************" << endl;
					cout << "Input y for starting project, or 'n' or other illeagal characters to quit" << endl << "\t>>>>";
					cin >> opt1;

					if (opt1 == "y")
					{
						cout << "You will start the caculation." << endl ;
						example_1();
						cout << "to clear the screen" << endl;
						system("pause");
						system("cls");
						//cout << "Input y for starting project,or 'n' or other illeagal characters to quit" << endl << "\t>>>>";
						menul();
					}
					else
					{
						cout << "good bye!" << endl;
						system("pause");
						system("cls");
						menul();
						break;
					}
				}
				continue;
			}
			else 
			{
				//����2�� �ж�԰����λ�ù�ϵ��Ҫ����ͷ�ļ��ͷֿ���cpp�ʼ�
				string opt2;
				while (1)
				{
					cout << "****************************************    y2    ********************************************" << endl;
					cout << "Input y for starting project, or 'n' or other illeagal characters to quit" << endl << "\t>>>>";
					cin >> opt2;
					if (opt2 == "y")
					{
						cout << "You will start the caculation." << endl;
						example_2();
						cout << "to clear the screen" << endl;
						system("pause");
						system("cls");
						//cout << "Input y for starting project,or 'n' or other illeagal characters to quit" << endl << "\t>>>>";
						menul();
					}
					else
					{
						cout << "good bye!" << endl;
						system("pause");
						system("cls");
						menul();
						break;
					}
				}
			}
			cin.clear();
			system("pause");
			system("cls");
			menul();
			continue;
		}
		else if (i != "y1" && i != "y2" && i != "exit()")
		{
			cout << endl << "There's no the option." << endl << "\tPls try again(y1 for Cube caculation,y2 for Circle caculation)" << endl << "\t>>>>";
			cin.clear();
			system("pause");
			system("cls");
			menul();
			continue;
		}
		else if( i == "exit()")
		{
			cin.clear();
			cout << "you have choose the quit option. " << endl;
			cout << "Quiting. . . . . . ." << endl;
			break;
		}
	}
	system("pause");
	return 0;
}



