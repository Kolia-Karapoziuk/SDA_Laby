#include <iostream>
#include <ctime>
#include <fstream>
#define  size 5
using namespace std;
int swapCount = 0, stepCount = 0;

void Zap(int** arr)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 20 + 10;
		}
	}

	ofstream outFile;
	outFile.open("File_1.txt");

	for (int i = 0; i < size; i++)
	{
		outFile << endl;
		for (int j = 0; j < size; j++)
		{
			outFile << " " << arr[i][j];
		}
	}
}

void quicksort_rows(int** matr, int i, int first, int last)
// ³ - the line number of which we sort
{
	int mid, count,sc=0;
	int f = first, l = last;
	mid = matr[i][(f + l) / 2]; //identifying the support element

	while (f <= l)
	{
		while (matr[i][f] > mid) f++;
		while (matr[i][l] < mid) l--;

		stepCount++;
		if (f <= l) //permutation of the element
		{
				count = matr[i][f];
				matr[i][f] = matr[i][l];
				matr[i][l] = count;
				swapCount++;

				f++;
				l--;
		}
	};


	if (first < l) 
		quicksort_rows(matr, i, first, l);

	if (f < last) 
		quicksort_rows(matr, i, f, last);


	ofstream outFile;
	outFile.open("File_2.txt");

	for (int i = 0; i < size; i++)
	{
		outFile << endl;
		for (int j = 0; j < size; j++)
		{
			outFile << " " << matr[i][j];
		}
	}
}

void print(int** arr)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}


int main()
{
	srand(time(NULL));

	int** arr = new int* [size];

	Zap(arr);

	print(arr);

	for (int i = 0; i < size; i++)
		quicksort_rows(arr, i, 0, size - 1);

	cout << "------------------------------------------------" << endl;
	
	print(arr);
	cout << endl << " Number of comparisons: " << stepCount << endl << " Number of permutations: " << swapCount << endl;
	delete[]arr;
	return 0;
}