#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cube
{
public:
	void SetLength(double length);

	void SetWidth(double width);

	void SetHight(double hight);


	double GetLength();

	double GetWidth();

	double GetHight();

	double GetArea();

	double GetVolume();

	//��Ա�жϺ���
	int Compare_cy(Cube& c2);


private:
	double Length;
	double Width;
	double Hight;
	double Area;
	double Volume;
};
