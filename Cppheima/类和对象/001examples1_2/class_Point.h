#pragma once
#include <iostream> 
#include <string>

using namespace std;

class Point
{
public:
	void Setx(double x);

	void Sety(double y);

	double Getx();

	double Gety();


private:
	double Point_x;
	double Point_y;
};