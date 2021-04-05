#pragma once

#ifndef __QUICHSORT_H__
#define __QUICHSORT_H__

static int QuickSortTimes = 0;
void QuickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int i = start;
	int j = end;
	int pivot = arr[(i + j) / 2];
	++QuickSortTimes;

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
#endif // !__QUICHSORT_H__