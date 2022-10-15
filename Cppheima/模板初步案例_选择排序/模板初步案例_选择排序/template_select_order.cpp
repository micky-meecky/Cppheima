#include <iostream>
#include <time.h>
#include <string>

using namespace std;

/*
- 利用函数模板封装一个排序的函数，可以对数组进行排序
- 排序规则从大到小，排序算法为选择排序
- 分别利用char数组和int数组进行测试

*/

//选择排序
template<typename T>
void Selectod(T& arr, int len)
{
	//select sort
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}

}

//冒泡排序
template<class T>
void bubblest(T & arr, int len)
{
	//bubble sort
	
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}

//quicksort快速排序
template<class T,class Tp>
int quicksort_main(T& arr, int low, int high,Tp pivot)
{
	int len = sizeof(arr) / sizeof(arr[low]);

	pivot = arr[low];

	while (low < high)
	{
		while (low < high && arr[high] >= pivot)
			high--;
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;

	return low;
}
template <class T>
void quicksort_part(T& arr, int low, int high)
{
	if (low < high)
	{
		int pivotpos = quicksort_main(arr, low, high,0);
		quicksort_part(arr, low, pivotpos-1);
		quicksort_part(arr, pivotpos+1, high);
		return;
	}
}


//随机赋值函数
template<class T>
void Assign(T& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		//一般性：rand() % (b-a+1)+ a ;    就表示  a~b 之间的一个随机整数。
		arr[i] = rand() % 20 + 1;//1-20
	}
}

//显示结果函数
template<class T>
void Showrst(T& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//算法选择函数
template<class T>
int Choose_Alg()
{	
	char ch;
	cout << endl << "请选择算法，1：选择，2：冒泡，3：快速，4：开发中" << endl;

	cin >> ch;
	while (1)
	{
		if (cin.fail())		//C++的验证输入合法性的代码
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "输入不合法，请重试。" << endl;
			continue;
		}
		else if (ch == '1')
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 1;
		}
		else if (ch == '2')
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 2;
		}
		else if (ch == '3')
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 3;
		}
		else
		{
			while (getchar() != '\n')	//清除缓冲区
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 99;
		}
	}

}

void test01()
{
	int arr[20] = {};
	int length = sizeof(arr) / sizeof(arr[0]);
	int chus;

	while (1)
	{

		Assign(arr, length);//随机赋值

		cout << endl << "原始结果为：" << endl;
		Showrst(arr, length);
		chus = Choose_Alg<int>();//显式指定类型
		if (chus == 1)
		{
			cout << endl << "选择排序结果：" << endl;
			Selectod(arr, length);
			Showrst(arr, length);

			system("pause");
			system("cls");
		}
		else if(chus == 2)
		{
			cout << endl << "循环排序结果：" << endl;
			bubblest(arr, length);
			Showrst(arr, length);
			system("pause");
			system("cls");
		}
		else if (chus == 3)
		{
			cout << endl << "快速排序结果：" << endl;
			quicksort_part(arr, 0, length-1);
			Showrst(arr, length);
			system("pause");
			system("cls");
		}
		else
		{
			system("pause");
			system("cls");
			break;
		}
	}

	//Assign(arr, length);
	////{2,0,3,1,8,4,6,7,5,9};
	//Showrst(arr, length);

	//cout << endl << "选择排序结果：" << endl;
	//Selectod(arr, length);
	//Showrst(arr, length);

	//Assign(arr, length);
	//cout << endl << "原始结果为：" << endl;
	//Showrst(arr, length);

	//cout << endl << "循环排序结果：" << endl;
	//bubblest(arr, length);
	//Showrst(arr, length);

	//Assign(arr, length);
	//cout << endl;

}


int main(void)
{
	srand((unsigned int)time(0));
	test01();
	system("pause");
	return 0;
}








