#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//---------------- ����� � ������������� � ������� --------------------------

bool search(int x, int*arr, int size, int& x_ret)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == x) {
			for (; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = x;
			x_ret = x;
			return true;
		}
	return false;
}

//----------------��������� ������--------------------------
void displayArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	srand(time(NULL));
	system("chcp 1251");
	system("cls");

	int siz;
	cout << "������ ����� ������: ";
	cin >> siz;
	int* A = new int[siz];
	int* B = new int[siz];

	for (int i = 0; i < siz; i++)
	{
		A[i] = rand() % 25 - 10;
	}

	for (int i = 0; i < siz; i++)
	{
		B[i] = rand() % 25 - 10;
	}

	cout << endl;
	cout << "����� � ������������� � �������: " << endl;
	cout << "�������� ������ �: ";
	displayArray(A, siz);
	cout << endl;

	cout << "�������� ������ �: ";
	displayArray(B, siz);
	cout << endl << endl;
	

	for (size_t i = 0; i < siz; i++)
	{
		int tmp;
		bool found = search(B[i], A, siz, tmp);
		if (found)
		{
			cout << "������� �� � � 2� ������� ���������: " 
			<< tmp << endl;	
		}
	}
	
	delete[] A;
	delete[] B;
}