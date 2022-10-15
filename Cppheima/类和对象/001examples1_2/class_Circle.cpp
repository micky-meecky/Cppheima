#include "class_Circle.h"


	void Circle::Setr(double r)
	{
		Cir_r = r;
	}
	void Circle::Setc(Point center)
	{
		Cir_Centre = center; //这里必须满足赋值的与被赋值的是同一种变量类型
	}
	double Circle::Getr()
	{
		return Cir_r;
	}
	Point Circle::Get_center()
	{
		return Cir_Centre;

	}
