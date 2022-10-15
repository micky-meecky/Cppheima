#include <iostream>
#include <time.h>
#include <string>

using namespace std;

/*
- ���ú���ģ���װһ������ĺ��������Զ������������
- �������Ӵ�С�������㷨Ϊѡ������
- �ֱ�����char�����int������в���

*/

//ѡ������
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

//ð������
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

//quicksort��������
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


//�����ֵ����
template<class T>
void Assign(T& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		//һ���ԣ�rand() % (b-a+1)+ a ;    �ͱ�ʾ  a~b ֮���һ�����������
		arr[i] = rand() % 20 + 1;//1-20
	}
}

//��ʾ�������
template<class T>
void Showrst(T& arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�㷨ѡ����
template<class T>
int Choose_Alg()
{	
	char ch;
	cout << endl << "��ѡ���㷨��1��ѡ��2��ð�ݣ�3�����٣�4��������" << endl;

	cin >> ch;
	while (1)
	{
		if (cin.fail())		//C++����֤����Ϸ��ԵĴ���
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "���벻�Ϸ��������ԡ�" << endl;
			continue;
		}
		else if (ch == '1')
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 1;
		}
		else if (ch == '2')
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 2;
		}
		else if (ch == '3')
		{
			while (getchar() != '\n')	//���������
			{
				cin.clear();
				cin.sync();
				continue;
			}
			return 3;
		}
		else
		{
			while (getchar() != '\n')	//���������
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

		Assign(arr, length);//�����ֵ

		cout << endl << "ԭʼ���Ϊ��" << endl;
		Showrst(arr, length);
		chus = Choose_Alg<int>();//��ʽָ������
		if (chus == 1)
		{
			cout << endl << "ѡ����������" << endl;
			Selectod(arr, length);
			Showrst(arr, length);

			system("pause");
			system("cls");
		}
		else if(chus == 2)
		{
			cout << endl << "ѭ����������" << endl;
			bubblest(arr, length);
			Showrst(arr, length);
			system("pause");
			system("cls");
		}
		else if (chus == 3)
		{
			cout << endl << "������������" << endl;
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

	//cout << endl << "ѡ����������" << endl;
	//Selectod(arr, length);
	//Showrst(arr, length);

	//Assign(arr, length);
	//cout << endl << "ԭʼ���Ϊ��" << endl;
	//Showrst(arr, length);

	//cout << endl << "ѭ����������" << endl;
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








