#include "class_Circle.h"


	void Circle::Setr(double r)
	{
		Cir_r = r;
	}
	void Circle::Setc(Point center)
	{
		Cir_Centre = center; //����������㸳ֵ���뱻��ֵ����ͬһ�ֱ�������
	}
	double Circle::Getr()
	{
		return Cir_r;
	}
	Point Circle::Get_center()
	{
		return Cir_Centre;

	}
