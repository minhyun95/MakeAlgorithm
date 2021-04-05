#pragma once


#ifndef __RADIXSORT_H__
#define __RADIXSORT_H__
#include "Queue.h"

#define BUCKET_NUM 10

static int RadixSortTimes = 0;
void Radix_LSD_Sort(int arr[], int num, int maxLen)
{
	// �Ű����� maxLen���� ���Ĵ�� �� ���� �� �������� ���� ������ ����
	Queue<int> buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (int i = 0; i < maxLen; ++i)
	{
		// ���Ĵ���� �� ��ŭ �ݺ�
		for (int j = 0; j < num; ++j)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[j] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����;
			buckets[radix].Enqueue(arr[j]);

			++RadixSortTimes;
		}

		// ��Ŷ �� ��ŭ �ݺ�
		for (int k = 0,di = 0; k < BUCKET_NUM; ++k)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
			while(!buckets[k].isEmpty())
				arr[di++] = buckets[k].Dequeue();

		}

		// N ��° �ڸ��� ���� ������ ���� �������� ����
		divfac *= 10;
	}

}
#endif // !__RADIXSORT_H__