#include <iostream>
#include <string>
#include <math.h>
#include "class_Point.h"
#include "class_Circle.h"
#include "class_Cube.h"

using namespace std;

//已经注释了的class Point

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

//已经注释了的class Circle

//class Circle
//{
//public:
//	void Setr(double r)
//	{
//		Cir_r = r;
//	}
//	void Setc(Point center)
//	{
//		Cir_Centre = center; //这里必须满足赋值的与被赋值的是同一种变量类型
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
////属性：
//private:
//	double Cir_r;//radius 
//	Point Cir_Centre;//圆心坐标
//};

void center_point(Point p, Circle c)
{
	//这里进行圆心坐标与点的距离判断
	//用公式(x - xc)2 + (y - yc)2 > cr2?判断
	double x1, y1;
	x1 = (p.Getx() - c.Get_center().Getx()) * (p.Getx() - c.Get_center().Getx());
	y1 = (p.Gety() - c.Get_center().Gety()) * (p.Gety() - c.Get_center().Gety());
	if ((x1 + y1) == (c.Getr() * c.Getr()))
	{
		cout << "该点在圆上" << endl;
	}
	else if ((x1 + y1) < (c.Getr() * c.Getr()))
	{
		if ((x1 + y1) != 0)
			cout << "该点在圆内,且不再圆心。" << endl;
		else
			cout << "该点与圆心重合。" << endl;
	}
	else if ((x1 + y1) > (c.Getr() * c.Getr()))
	{
		cout << "该点在圆外。" << endl;
		cout << "且该点与圆的距离为：" << sqrt(x1 + y1) - c.Getr() << endl;
	}
}
void example_2()
{	
	//创建对象
	Point P;
	Point Center;
	Circle C;
	double cx, cy, r, px, py;
	cout << "please enter your circle center's axis:  " << endl;
	//输入x并验证其合法性
	while (true)
	{
		
		if (cin >> cx) //isdigit()只接受字符型变量
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
	//输入y并验证其合法性
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
	//输入r并验证其合法性
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
	//输入px并验证其合法性
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
	//输入py并验证其合法性
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

	//赋值给对象
	P.Setx(px);
	P.Sety(py);
	C.Setr(r);
	Center.Setx(cx);
	Center.Sety(cy);
	C.Setc(Center);

	center_point(P, C);
	system("pause");
}


//已经注释了的class Cube

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
//	//成员判断函数
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
//				l++;	//每对一个，则l加一；
//			else
//				return 0;
//		}
//		if (l == 2)//当l等于2时，意味着有三个一样的边长，则返回1，意思就是是一样的；
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

//全局两个圆的比较函数
int Compare(Cube& c1, Cube& c2)//因不能改变长宽高的值，且要节省更多内存，故用引用
{
	int i, j;
	//int a, b;
	int k, l;
	i = 0;
	j = 0;
	double c11[3], c22[3], temp1 = 0, temp2 = 0;
	//赋值：
	c11[0] = c1.GetLength();
	c11[1] = c1.GetWidth();
	c11[2] = c1.GetHight();

	c22[0] = c2.GetLength();
	c22[1] = c2.GetWidth();
	c22[2] = c2.GetHight();

	//不改变初值地排序
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
	//以下为调试代码，看排序是否正常；
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

//这里example_1存在一个严重bug，没有检查输入的合法性
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

	//全局判断函数,因需要考虑两个长方体的长宽高顺序，故需要排序比较；
	
		int tf1;
		tf1 = Compare(c1,c2);//因不能改变长宽高的值，且要节省更多内存，故用引用
		system("pause");
		if (tf1)
		{
			cout << endl <<  "用引用方式传递参数创建比较函数显示：" << "c1 与 c2" << "是一样的立方体。" << endl;
		}
		else 
			cout << endl << "用引用方式传递参数创建比较函数显示：" << "c1 与 c2" << "不不不是一样的立方体。" << endl;
		cout << "\nGood bye!" << endl;

	//成员判断函数,因需要考虑两个长方体的长宽高顺序，故需要排序比较；
		int tf2;
		tf2 =c1.Compare_cy(c2);//因不能改变长宽高的值，且要节省更多内存，故用引用
		system("pause");
		if (tf2)
		{
			cout << endl << "用成员函数显示：" << "c1 与 c2" << "是一样的立方体。" << endl;
		}
		else
			cout << endl << "用成员函数显示：" << "c1 与 c2" << "不不不是一样的立方体。" << endl;
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
				//案例1 设计立方体类： 求立方体面积和体积；并用全局函数和成员函数分别实现对两个立方体是否一样做出判断；
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
				//案例2， 判断园与点的位置关系；要求，用头文件和分开的cpp问价
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



