#pragma once

#ifndef __TABLECHANING_H__
#define __TABLECHANING_H__

#include <iostream>
#include <list>
#define SAFE_DELETE(p)	if(p)	{ delete p; p = nullptr; }
//
//inline int HashFunc1(int key, int _chainSize)
//{
//	cout << key % _chainSize << "�� �ؽ����̺� ����� " << endl;
//	return key % _chainSize;
//}




class HashTable
{
public:
	HashTable()
		: m_TableList(nullptr), hf(nullptr)
	{

	}
	~HashTable()
	{
		Release();
	}
	void Initialize(int _tableNum, int(*b)(int) )
	{
		hf = b;
		m_TableList = new list<int>[_tableNum];
		m_iChainSize = _tableNum;
	}
public:

	int(*hf)(int);

private:
	list<int>*		m_TableList;
	int				m_iChainSize;


private:
	void Release()
	{
		for (int i = 0; i < m_iChainSize; i++)
		{
			m_TableList[i].clear();
		}
	}

public:
	void Insert(int _data)
	{
		// �ߺ�
		if (Search(_data) != INT_MAX)
		{
			cout << "�ߺ��� �������Դϴ� ���̺� �Է� �Ұ���" << endl;
		}
		else
		{
			cout << _data << " �Է� ����" << endl;
			m_TableList[(*hf)(_data)].push_back(_data);
		}
		 
	}
	void Delete(int _data)
	{
		int Slot = (*hf)(_data);
		list<int>::iterator iter;
		list<int>::iterator iterEnd = m_TableList[Slot].end();
		for (iter = m_TableList[Slot].begin(); iter != iterEnd; ++iter)
		{
			if (_data == *iter)
			{
				cout << "Delete ���� : " << *iter << endl;
				m_TableList[Slot].erase(iter);
				break;
			}
		}
	}
	int Search(int _data)
	{
		bool Find = false;
		int Slot = (*hf)(_data);
		list<int>::iterator iter;
		list<int>::iterator iterEnd = m_TableList[Slot].end();
		for (iter = m_TableList[Slot].begin(); iter != iterEnd; ++iter)
		{
			if (_data == *iter)
			{
				cout << "Search ���� : " << *iter << endl;
				return *iter;
			}
		}
		return INT_MAX;
	}


};


#endif // ! __TABLECHANING_H__