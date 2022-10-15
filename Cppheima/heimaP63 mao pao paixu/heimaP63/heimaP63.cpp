#include <iostream>
#include <string>
using namespace std;
void bubblesort(int* p, int alen);

//main函数 实现调用传递地址实参的函数来做冒泡排序，并打印输出
int main(void)
{
	int arr[10] = { 4,6,3,9,1,2,10,8,7,5 };

	int len = sizeof(arr) / sizeof(arr[0]);

	int k;

	bubblesort(arr,len);

	cout << "打印后的数组是：" << endl;
	for (k = 0; k < len; k++) 
	{
		cout << arr[k] << "\t";
	}
	cout << endl;
	system("pause");

}


void bubblesort(int * p, int alen)
{
	int temp = 0;
	for (int i = 0; i < alen; i++)
	{
		for (int j = 0; j < alen - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}