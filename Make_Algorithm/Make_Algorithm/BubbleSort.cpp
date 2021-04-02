#include <iostream>

using namespace std;

void BubbleSort(int arr[], int end);

int main()
{
	int iArr[5] = { 5,4,3,2,1 };
	BubbleSort(iArr, sizeof(iArr) / sizeof(int) );

	for (int i = 0; i < sizeof(iArr) / sizeof(int); i++)
	{
		cout << iArr[i] << endl;
	}
}

void BubbleSort(int arr[], int end)
{
	if (end == 1)
		return;
	for (int j = 1; j < end; j++)
	{
		// 가장 큰 수를 가장 뒤로 보낸다.
		if (arr[j] < arr[j - 1])
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
	BubbleSort(arr, end - 1);
}