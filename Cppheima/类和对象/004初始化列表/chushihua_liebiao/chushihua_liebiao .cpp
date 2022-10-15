#include <iostream>
using namespace std;

class List
{
public:

	List(int a, int b, int c) :A(a), B(b), C(c) {} //初始化列表，注意语法写法


	int A;
	int B;
	int C;
};



int main(void)
{
	List L(1, 2, 3);
	cout << "a = " << L.A << endl;
	cout << "b = " << L.B << endl;
	cout << "c = " << L.C << endl;
	system("pause");
	return 0;
}