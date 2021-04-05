#pragma once
#pragma once

#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
using namespace std;

#define HEAP_SIZE 256
class Heap
{
public:
	Heap()
	{
		Init();
	}
	~Heap()
	{
		delete[] m_Arr;
		m_Arr = nullptr;
	}

private:
	int*	m_Arr;
	int		m_iSize;
	int		m_iCapasity;

private:
	void Init()
	{
		m_iSize = 0;
		m_iCapasity = HEAP_SIZE;
		m_Arr = new int[m_iCapasity];
	}
	void resize(int num)
	{
		m_iCapasity = num;
	}

public:

	int HeapDelete()
	{
		if (isEmpty())
		{
			// 비었을 때
			return INT_MIN;
		}
		int iTopData = m_Arr[1];

		m_Arr[1] = m_Arr[m_iSize];
		--m_iSize;

		int iIndex = 1;
		while (iIndex * 2 <= m_iSize && m_Arr[iIndex] < m_Arr[iIndex * 2])
		{
			int temp;
			if (
				iIndex * 2 + 1 <= m_iSize &&
				m_Arr[iIndex] < m_Arr[iIndex * 2 + 1] &&
				m_Arr[iIndex * 2 + 1] > m_Arr[iIndex * 2]
				)
			{
				temp = m_Arr[iIndex];
				m_Arr[iIndex] = m_Arr[iIndex * 2 + 1];
				m_Arr[iIndex * 2 + 1] = temp;

				iIndex = iIndex * 2 + 1;
			}
			else
			{
				temp = m_Arr[iIndex];
				m_Arr[iIndex] = m_Arr[iIndex * 2];
				m_Arr[iIndex * 2] = temp;

				iIndex = iIndex * 2;
			}
		}
		return iTopData;
	}
	void HeapPush(const int& data)
	{
		if (isFull())
		{
			cout << "Full!" << endl;
			return;
		}

		++m_iSize;
		m_Arr[m_iSize] = data;
		int iIndex = m_iSize;

		// 맥스힙 큰게 위로
		while (iIndex > 1 && m_Arr[iIndex] > m_Arr[iIndex / 2])
		{
			int temp = m_Arr[iIndex];
			m_Arr[iIndex] = m_Arr[iIndex / 2];
			m_Arr[iIndex / 2] = temp;

			iIndex /= 2;
		}
	}
	bool isEmpty()
	{
		if (m_iSize == 0)
			return true;

		return false;
	}
	bool isFull()
	{
		if (m_iSize >= m_iCapasity - 1)
			return true;

		return false;
	}

	void ShowHeap()
	{
		for (int i = 1; i <= m_iSize; i++)
		{
			cout << i << "번째 : " << m_Arr[i] << endl;
		}
	}

};

#endif // !__HEAP_H__
