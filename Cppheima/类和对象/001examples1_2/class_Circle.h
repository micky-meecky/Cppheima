#pragma once
#include <iostream> 
#include <string>
#include "class_Point.h"

using namespace std;

class Circle
{
public:
	void Setr(double r);

	void Setc(Point center);

	double Getr();

	Point Get_center();


	//ÊôÐÔ£º
private:
	double Cir_r;//radius 
	Point Cir_Centre;//Ô²ÐÄ×ø±ê
};