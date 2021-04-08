#pragma once

#ifndef __HASHTABLE_ARRAY_H__
#define __HASHTABLE_ARRAY_H__

#include <iostream>

enum class eTableState { EMPTY, FULL, INSUE };

typedef struct _tagStu
{
	_tagStu() : iNumber(0), iMath(0), iEng(0) {}
	_tagStu(int _num, int math, int eng)
	{
		iNumber = _num;
		iMath = math;
		iEng = eng;
	}
	int iNumber;
	int iMath;
	int iEng;
	eTableState eState;
};
inline int hash_func(int key)
{
	return key % 100;
}

class HashTableArray
{
public:
	HashTableArray() : m_iSize(100), m_MaxSearchTime(100) { Find_Minority(); }
	HashTableArray(int iSize)
		: m_iSize(iSize), m_MaxSearchTime(100)
	{
		m_pStudent = new _tagStu[m_iSize];
		for (int i = 0; i < m_iSize; i++)
		{
			m_pStudent[i].eState = eTableState::EMPTY;
		}
		Find_Minority();
	}
	~HashTableArray()
	{
		delete[] m_pStudent;
		m_pStudent = nullptr;
	}

private:
	int			m_iSize;
	_tagStu*	m_pStudent;
	int			m_MaxSearchTime;
	int			m_Minority;

private:
	int DoubleHash_First(int key, int time)
	{
		
		// 1번 : 중앙값에 가까운 소수
		int FirstHash = 1 + key % m_Minority;

		// 2번 : 아무 작은 소수
		//int FirstHash = 1 + key % 17;
		int SecondHash = FirstHash * time;

		return (FirstHash + SecondHash) % m_iSize;
	}
	void Find_Minority()
	{
		bool* MinArr = new bool[m_iSize];
		memset(MinArr, 0, m_iSize);
		int half;

		// 에라스토체네스의 체
		for (int i = 2; i < m_iSize / 2; i++)
		{
			if (MinArr[i] == false)
			{
				for (int g = i * 2; g < m_iSize / 2; g += i)
				{
					MinArr[g] = true;
				}
			}
			
		}
		half = (m_iSize / 2) - 1;
		while (true)
		{
			if (MinArr[half] == false)
				break;
			--half;
		}
		cout << "중앙 소수 : " << half << endl;
		m_Minority = half;
		delete[] MinArr;
	}
public:
	void Insert(int _key, int math, int eng)
	{
		int value;
		for (int i = 0; i < m_MaxSearchTime; ++i)
		{
			value = DoubleHash_First(_key, i);
			if (m_pStudent[value].eState == eTableState::EMPTY)
			{
				cout << "key : " << _key << ", 이중해쉬 value : " << value << endl;
				m_pStudent[value].iNumber = _key;
				m_pStudent[value].iEng = eng;
				m_pStudent[value].iMath = math;
				m_pStudent[value].eState = eTableState::FULL;
				break;
			}
			else if (m_pStudent[value].eState == eTableState::FULL)
			{
				cout << "이중 해시 충돌" << endl;
			}
		}
	}
	void Delete(int _key)
	{
		int value;
		for (int i = 0; i < m_MaxSearchTime; ++i)
		{
			value = DoubleHash_First(_key, i);
			if (m_pStudent[value].iNumber == _key &&
				m_pStudent[value].eState == eTableState::FULL)
			{
				m_pStudent[value].eState = eTableState::INSUE;
				break;
			}
		}
	}
	bool Search(int _key)
	{
		int value;
		for (int i = 0; i < m_MaxSearchTime; ++i)
		{
			value = DoubleHash_First(_key, i);
			if (m_pStudent[value].iNumber == _key &&
				m_pStudent[value].eState == eTableState::FULL)
			{
				return true;
			}
		}
		return false;
	}

	void ShowAll()
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_pStudent[i].eState == eTableState::FULL)
			{
				cout << "학생 번호 : " << m_pStudent[i].iNumber << endl;
				cout << "수학 : " << m_pStudent[i].iMath << endl;
				cout << "영어 : " << m_pStudent[i].iEng << endl;
			}
			else if (m_pStudent[i].eState == eTableState::INSUE)
			{
				cout << "삭제된 학생 번호 : " << m_pStudent[i].iNumber << endl;
			}
		}
	}

	void Show_Frequency()
	{
		int fre = 10;
		for (int g = 0; g < fre; g++)
		{
			for (int i = 0; i < m_iSize / fre; i++)
			{
				cout << m_pStudent[g * 10 + i].iNumber << " ";
			}
			cout << endl;
		}
	}
	
};

#endif // !__HASHTABLE_ARRAY_H__