#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#define rows 15
#define cols 15
using namespace std;

int swapCount = 0, stepCount = 0;

void zap(int arr[rows][cols], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = (rand() % 19 + 10);
		}
	}
}

void display(int arr[rows][cols], int size) {
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	ofstream outFile;
	outFile.open("File_1.txt");

	for (int i = 0; i < rows; i++)
	{
		outFile << endl;
		for (int j = 0; j < cols; j++)
		{
			outFile << " " << arr[i][j];
		}
	}
}

int getMax(int arr[rows][cols], int size, int str) 
{
	int i, m = arr[0][str]; 

	for (i = 1; i < size; i++) 
	{
		if (arr[i][str] > m) 
		{
			m = arr[i][str];
		}
	}
	return m;
}

void bucketSort(int arr[rows][cols], int size, int str) {
	int max, bucket = 10, divider, i, j, k;

	//10 "pockets"
	vector<int> B[10];
	max = getMax(arr, size, str);

	divider = ceil(float(max + 1) / bucket);

	//put item in pocket
	for (i = 0; i < size; i++) 
	{
		j = floor(arr[str][i] / divider);
		B[j].push_back(arr[str][i]);
		stepCount++;
	}

	//sort items in your pockets
	for (i = 0; i < bucket; i++)
	{
		sort(B[i].begin(), B[i].end());
		swapCount++;
	}
	
	//add items from your pockets
	k = 0;
	for (i = 0; i < bucket; i++) 
	{
		for (j = 0; j < B[i].size(); j++) 
		{
			arr[str][k++] = B[i][j];
		}
	}

	ofstream outFile;
	outFile.open("File_2.txt");

	outFile << " Number of comparisons: " << stepCount << endl;
	outFile << " Number of permutations: " << swapCount << endl;
	for (int i = 0; i < size; i++)
	{
		outFile << endl;
		for (int j = 0; j < size; j++)
		{
			outFile << " " << arr[i][j];
		}
	}
}

int main() 
{
	srand(time(NULL));
	int arr[rows][cols];

	string File1 = "info.txt";
	string File2 = "info_2.txt";

	int n = sizeof(arr) / sizeof(arr[0]);
	zap(arr,n);

	//print unsorted items
	cout << "Not sorted array:" << endl;
	display(arr,n);

	//sort items
	bucketSort(arr, n, 0);
	int array1[rows]; int array2[cols];
	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		bucketSort(arr,n,i);
	}

	cout << "Sorted array:" << endl;
	display(arr,n);
	cout << endl << " Number of comparisons: " << stepCount << endl << " Number of permutations: " << swapCount << endl;

	return 0;
}

