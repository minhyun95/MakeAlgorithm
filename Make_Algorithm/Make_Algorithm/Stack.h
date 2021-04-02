#pragma once
#include <iostream>
using namespace std;
template <typename T>
class CStackNode
{
	template <typename T>
	friend class CStack;

private:
	CStackNode()
	{
		m_pPrev = nullptr;
	}
	~CStackNode()
	{
	}

public:
	T	m_Data;
private:
	CStackNode<T>* m_pPrev;

};

template <typename T>
class CStack
{
public:
	CStack()
	{
		Init();
	}
	~CStack()
	{
		clear();
		cout << "소멸자 isEmpty :" << isEmpty() << endl;
	}

private:
	typedef CStackNode<T> NODE;
	typedef CStackNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pPeek;

private:
	void Init()
	{
		m_pBegin = new NODE;
		m_pPeek = new NODE;

		m_pPeek->m_pPrev = m_pBegin;
	}
	void clear()
	{

		PNODE pNode = m_pPeek->m_pPrev;

		while (pNode != m_pBegin)
		{
			PNODE pPrev = pNode->m_pPrev;
			delete pNode;
			pNode = pPrev;
		}
		m_pPeek->m_pPrev = m_pBegin;
	}
public:
	bool isEmpty()
	{
		if (m_pPeek->m_pPrev == m_pBegin)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(const T& data)
	{
		PNODE newNODE = new NODE;
		newNODE->m_Data = data;
		cout << "push : " << data << endl;
		newNODE->m_pPrev = m_pPeek->m_pPrev;
		m_pPeek->m_pPrev = newNODE;
	}
	T& pop()
	{
		if (isEmpty())
		{
			cout << "(pop)스택이 비었습니다";
			return m_pBegin->m_Data;
		}
		T data = m_pPeek->m_pPrev->m_Data;

		PNODE pPrev = m_pPeek->m_pPrev->m_pPrev;
		delete m_pPeek->m_pPrev;
		m_pPeek->m_pPrev = pPrev;


		return data;
	}
	T& peek()
	{
		if (!isEmpty())
			return m_pPeek->m_pPrev->m_Data;

		cout << "(peek)스택이 비었습니다";
		return m_pBegin->m_Data;
	}

private:
	T	m_Data;
};
