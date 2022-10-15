#include "class_Cube.h"


	void Cube::SetLength(double length)
	{
		if (length < 0.0)
		{
			cout << "your input is illegal" << endl;
			return;
		}
		else
			Length = length;
	}
	void Cube::SetWidth(double width)
	{
		if (width < 0.0)
		{
			cout << "your input is illegal" << endl;
			return;
		}
		else
			Width = width;
	}
	void Cube::SetHight(double hight)
	{
		if (hight < 0.0)
		{
			cout << "your input is illegal" << endl;
			return;
		}
		else
			Hight = hight;
	}

	double Cube::GetLength()
	{
		return Length;
	}
	double Cube::GetWidth()
	{
		return Width;
	}
	double Cube::GetHight()
	{
		return Hight;
	}
	double Cube::GetArea()
	{
		return Area = 2 * (Length * Width + Length * Hight + Width * Hight);
	}
	double Cube::GetVolume()
	{
		return Length * Width * Hight;
	}
	//成员判断函数
	int Cube::Compare_cy(Cube& c2)
	{
		int i, j, k, l;

		double c11[3], c22[3], temp1 = 0, temp2 = 0;

		c11[0] = GetLength();
		c11[1] = GetWidth();
		c11[2] = GetHight();


		c22[0] = c2.GetLength();
		c22[1] = c2.GetWidth();
		c22[2] = c2.GetHight();

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
		for (k = 0, l = 0; k < 3; k++)
		{
			if (c11[k] == c22[k])
				l++;	//每对一个，则l加一；
			else
				return 0;
		}
		if (l == 2)//当l等于2时，意味着有三个一样的边长，则返回1，意思就是是一样的；
			return 1;
	}
