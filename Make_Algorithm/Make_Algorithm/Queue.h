#pragma once


template <typename T>
class QueueNode
{
	template <typename T>
	friend class Queue;

public :
	QueueNode()
	{
		m_pNext = nullptr;
	}
	~QueueNode()
	{
		
	}

private :
	T		m_Data;
	QueueNode*  m_pNext;
};


template <typename T>
class Queue
{
public :
	Queue()
	{
		m_pBegin = nullptr;
		m_pEnd = nullptr;

		m_iSize = 0;
	}
	~Queue()
	{
		clear();
	}

private :
	typedef QueueNode<T>	NODE;
	typedef QueueNode<T>*	PNODE;

private :
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

private :
	void clear()
	{
		if (m_iSize == 0)
			return;

		PNODE Node = m_pBegin;

		while (Node != m_pEnd)
		{
			PNODE pNext = Node->m_pNext;
			delete Node;
			Node = pNext;
		}

		if (m_pEnd)
			delete m_pEnd;
		m_iSize = 0;
	}

public :
	bool isEmpty()
	{
		if (m_iSize == 0)
			return true;
		else
			return false;
	}
	void Enqueue(const T& data)
	{
		PNODE newNode = new NODE;
		newNode->m_Data = data;

		if (m_iSize == 0)
		{
			m_pBegin = newNode;
			m_pEnd = newNode;
		}
		else
		{
			m_pEnd->m_pNext = newNode;
			m_pEnd = newNode;
		}

		++m_iSize;
	}
	T Dequeue()
	{
		if (isEmpty())
		{
			// 에러 발생해야 정상 현재는 테스트를 위해 return 0
			return m_pBegin->m_Data;
		}
		
		T data = m_pBegin->m_Data;
		PNODE pNext = m_pBegin->m_pNext;
		delete m_pBegin;
		m_pBegin = pNext;
		--m_iSize;
		return data;
	}
	T& front()
	{
		if (isEmpty())
		{
			// 에러 발생해야 정상 현재는 테스트를 위해 return 0
			assert(false);
		}

		return m_pBegin->m_Data;
	}

	int size() const
	{
		return m_iSize;
	}
};