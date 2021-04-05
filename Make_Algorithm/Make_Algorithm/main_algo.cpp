
#include "Default.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

int iArr[100] = { };

void BubbleTest();
void QuickTest();
void MergeTest();
void RadixTest();

void PrintArray(int Arr[], int iSize);
void RandomSwap(int iArr[], int iSize);

int main()
{
	srand(unsigned(time(NULL)));
	RandomSwap(iArr, sizeof(iArr) / sizeof(int));
	MergeTest();
}


void BubbleTest()
{
	BubbleSort(iArr, sizeof(iArr) / sizeof(int));

	//PrintArray(iArr, sizeof(iArr) / sizeof(int));
	cout << "BubbleSort ¿¬»ê È½¼ö : " << BubbleSortTimes << endl;
}

void QuickTest()
{
	QuickSort(iArr, 0, sizeof(iArr)/ sizeof(int) - 1);

	//PrintArray(iArr, sizeof(iArr) / sizeof(int));
	cout << "Quick ¿¬»ê È½¼ö : " << QuickSortTimes << endl;
}

void MergeTest()
{
	MergeSort(iArr, 0, sizeof(iArr) / sizeof(int) - 1);

	PrintArray(iArr, sizeof(iArr) / sizeof(int));
	cout << "MergeSort ¿¬»ê È½¼ö : " << MergeSortTimes << endl;
}

void RadixTest()
{
	Radix_LSD_Sort(iArr, sizeof(iArr) / sizeof(int), 3);

	PrintArray(iArr, sizeof(iArr) / sizeof(int));
	cout << "Radix_LSD_Sort ¿¬»ê È½¼ö : " << RadixSortTimes << endl;
}

void PrintArray(int Arr[], int iSize)
{
	cout << "Ãâ·Â ½ÃÀÛ" << endl;

	for (int i = 0; i < iSize; i++)
	{
		cout << "iArr[" << i<< "] : " << Arr[i] << endl;
	}
}

void RandomSwap(int iArr[], int iSize)
{
	for (int i = 0; i < iSize; i++)
	{
		iArr[i] = rand() % iSize + 1;
	}
}
