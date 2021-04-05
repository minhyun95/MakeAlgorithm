#pragma once


#ifndef __RADIXSORT_H__
#define __RADIXSORT_H__
#include "Queue.h"

#define BUCKET_NUM 10

static int RadixSortTimes = 0;
void Radix_LSD_Sort(int arr[], int num, int maxLen)
{
	// 매개변수 maxLen에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
	Queue<int> buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 가장 긴 데이터의 길이만큼 반복
	for (int i = 0; i < maxLen; ++i)
	{
		// 정렬대상의 수 만큼 반복
		for (int j = 0; j < num; ++j)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[j] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터 저장;
			buckets[radix].Enqueue(arr[j]);

			++RadixSortTimes;
		}

		// 버킷 수 만큼 반복
		for (int k = 0,di = 0; k < BUCKET_NUM; ++k)
		{
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while(!buckets[k].isEmpty())
				arr[di++] = buckets[k].Dequeue();

		}

		// N 번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}

}
#endif // !__RADIXSORT_H__