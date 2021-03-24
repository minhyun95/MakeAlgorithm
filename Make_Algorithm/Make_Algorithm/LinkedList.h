#pragma once

#include <assert.h>

template <typename T>
class ListNode
{
	template <typename T>
	friend class LinkedList;
	template <typename T>
	friend class Listiterator;

private :
	ListNode()
	{
		m_pNext == nullptr;
		m_pPrev == nullptr;
	}
	~ListNode()
	{

	}

private :
	T				m_Data;
	ListNode<T>*	m_pNext;
	ListNode<T>*	m_pPrev;
};

template <typename T>
class Listiterator
{
	template <typename T>
	friend class LinkedList;

public :
	Listiterator()
	{
		m_pNode = nullptr;
	}
	~Listiterator()
	{

	}

private :
	typedef ListNode<T>*  PNODE;

private :
	PNODE	m_pNode;

public :
	bool operator == (const Listiterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const Listiterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}
	
	void operator ++()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator --()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	T& operator *()
	{
		return m_pNode->m_Data;
	}
};

template <typename T>
class LinkedList
{
	template <typename T>
	friend class ListNode;

public :
	LinkedList()
	{
		m_iSize = 0;
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}
	~LinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

private :
	typedef ListNode<T>		NODE;
	typedef ListNode<T>*	PNODE;

public :
	typedef Listiterator<T>	iterator;

private :
	int		m_iSize;
	PNODE	m_pBegin;
	PNODE	m_pEnd;

public :
	void push_back(const T& data)
	{
		PNODE newNode = new NODE;
		newNode->m_Data = data;
		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = newNode;
		m_pEnd->m_pPrev = newNode;

		newNode->m_pPrev = pPrev;
		newNode->m_pNext = m_pEnd;
		 
		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE newNode = new NODE;
		newNode->m_Data = data;
		PNODE pNext = m_pBegin->m_pNext;

		pNext->m_pPrev = newNode;
		m_pBegin->m_pNext = newNode;

		newNode->m_pNext = pNext;
		newNode->m_pPrev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		if (Empty())
		{
			assert(false);
		}

		PNODE deleteNode = m_pEnd->m_pPrev;
		PNODE pPrev = deleteNode->m_pPrev;

		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		delete deleteNode;

		--m_iSize;
	}

	void pop_front()
	{
		if (Empty())
		{
			assert(false);
		}

		PNODE deleteNode = m_pBegin->m_pNext;

		PNODE pNext = deleteNode->m_pNext;

		pNext->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNext;

		delete deleteNode;

		--m_iSize;
	}

	int size() const
	{
		return m_iSize;
	}

	// 비었으면 true 차있으면 false
	bool Empty()
	{
		return (0 == m_iSize);
	}

	void clear()
	{
		if (Empty())
		{
			assert(false);
		}

		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			PNODE pNext = pNode->m_pNext;

			delete pNode;
			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}

	T& front()
	{
		if (Empty())
		{
			assert(false);
		}
		return m_pBegin->m_pNext->m_Data;
	}

	T& back()
	{
		if (Empty())
		{
			assert(false);
		}
		return m_pEnd->m_pPrev->m_Data;
	}

public :
	iterator begin() const
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end() const
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	// 아래 함수는 인자로 들어온 iterator가 가지고 있는 노트를
	// 지워주고 그 다음노드를 가지고 있는 iterator를 만들어서
	// 반환한다.
	iterator erase(const iterator& iter)
	{
		if (m_pBegin == iter.m_pNode || m_pEnd == iter.m_pNode)
			assert(false);

		PNODE pPrev = iter.m_pNode->m_pPrev;
		PNODE pNext = iter.m_pNode->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete iter.m_pNode;

		--m_iSize;

		iterator result;
		result.m_pNode = pNext;
		return result;
	}

	iterator erase(const T& data)
	{
		iterator iter;
		iterator iterEnd = end();

		for (iter = begin(); iter != iterEnd; ++iter)
		{
			if (*iter == data)
			{
				return erase(iter);
			}
		}
	}

	void sort(bool(*pFunc)(const T&, const T&))
	{
		for (PNODE pFirst = m_pBegin->m_pNext; pFirst != m_pEnd->m_pPrev; pFirst = pFirst->m_pNext)
		{
			for (PNODE pSecond = pFirst->m_pNext; pSecond != m_pEnd; pSecond = pSecond->m_pNext)
			{
				if(pFunc(pFirst->m_Data, pSecond->m_Data))
				{
					T temp = pFirst->m_Data;
					pFirst->m_Data = pSecond->m_Data;
					pSecond->m_Data = temp;
				}
			}
		}
	}
};