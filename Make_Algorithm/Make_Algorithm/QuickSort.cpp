#include <iostream>
#include <vector>
using namespace std;

void QuickSort(int arr[],int start, int end);

int main()
{
	int iArr[5] = { 4,1,5,2,3 };
	QuickSort(iArr, 0, 5 - 1);

	for (int i = 0; i < 5; i++)
	{
		cout << iArr[i] << " ";
	}
}

void QuickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int i = start;
	int j = end;
	int pivot = arr[(i + j) / 2];


	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	QuickSort(arr, start, j);
	QuickSort(arr, i, end);
}