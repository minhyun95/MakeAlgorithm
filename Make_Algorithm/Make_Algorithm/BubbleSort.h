#pragma once

#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

static long long BubbleSortTimes = 0;
void BubbleSort(int arr[], int end)
{
	if (end == 1)
		return;
	for (int j = 1; j < end; j++)
	{
		// ���� ū ���� ���� �ڷ� ������.
		++BubbleSortTimes;
		if (arr[j] < arr[j - 1])
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
	BubbleSort(arr, end - 1);
}
#endif // !__BUBBLESORT_H__