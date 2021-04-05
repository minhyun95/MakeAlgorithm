#pragma once

#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "Default.h"
static int MergeSortTimes = 0;
void Merge(int arr[], int left, int mid, int right)
{
	++MergeSortTimes;
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = new int[right + 1];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		++sIdx;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}
	else
	{
		for (int i = fIdx; i <= mid; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}
	
	for (int i = left; i <= right; i++)
	{
		arr[i] = sortArr[i];
	}

	delete[] sortArr;
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		// �߰� ������ ����Ѵ�.
		mid = (left + right) / 2;
		
		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		Merge(arr, left, mid, right);
	}
}

#endif // !__MERGESORT_H__