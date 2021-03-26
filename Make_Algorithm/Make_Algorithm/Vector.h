#pragma once
#include <assert.h>
template <typename T>
class VectorNode
{
	template <typename T>
	friend class Vector;
	template <typename T>
	friend class Vectoriterator;
private :
	VectorNode()
	{

	}
	~VectorNode()
	{

	}

private :
	template <typename T>
	friend class Vector;

private :
	T		m_Data;
	int		m_iIndex;
};

// iterator ����
template <typename T>
class Vectoriterator
{
	template <typename T>
	friend class Vector;

public :
	Vectoriterator()
	{

	}
	~Vectoriterator()
	{

	}

private :
	typedef VectorNode<T>* PNODE;

private :
	PNODE Pos;

public :
	bool operator ==(const Vectoriterator<T>& iter)
	{
		return Pos->m_Data == iter.Pos->m_Data;
	}

	bool operator !=(const Vectoriterator<T>& iter)
	{
		return Pos->m_Data != iter.Pos->m_Data;
	}

	void operator ++()
	{
		Pos = Pos + 1;
	}

	void operator --()
	{
		Pos = Pos - 1;
	}

	T operator *()
	{
		return Pos->m_Data;
	}

	unsigned int operator -(const Vectoriterator<T>& iter)
	{
		return Pos->m_iIndex - iter.Pos->m_iIndex;
	}

};

template <typename T>
class Vector
{
	template <typename T>
	friend class VectorNode;
	template <typename T>
	friend class Vectoriterator;
public :
	Vector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		// �ʱ�ȭ
		// End�� Begin���� ���ļ� + 2 ��ŭ 
		m_pArray = new VectorNode<T>[m_iCapasity + 2];
		m_pBegin = new VectorNode<T>;
		m_pBegin->m_iIndex = 0;
	}
	Vector(int iSize)
	{
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~Vector()
	{
		// �޸� ����
		delete[]	m_pArray;
	}

private :
	typedef VectorNode<T>	NODE;
	typedef VectorNode<T>*	PNODE;

public :
	typedef Vectoriterator<T> iterator;

private :
	PNODE m_pArray;
	PNODE m_pBegin;
	PNODE m_pEnd;
	int	m_iSize;
	int	m_iCapasity; // �迭�� �� ���� (2�辿 �þ)

public :
	void push_back(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		// 0���� begin�̴�. �׷��� ���� 1���ε������� ��尡
		// �߰��Ǵµ� ó�� �߰��� ���� 0������ �ε����� �ֵ����Ѵ�.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	
	void resize(int iSize)
	{
		// Begin End ��� ���� + 2
		PNODE pArray = new NODE[iSize + 2];

		// 2�踸ŭ �Ҵ��� ������ ������ �ִ� �����͸�
		// ������ ������ŭ �����Ѵ�.
		// 0���� Begin�̱⶧���� 0������ ������������ 1������ �����Ѵ�. ( +1 �ϴ� ���� )
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		// ���� ��带 �����Ѵ�.
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;

	}

	int size() const
	{
		return m_iSize;
	}

	int capasity() const
	{
		return m_iCapasity;
	}

	bool full()
	{
		return m_iSize == m_iCapasity;
	}

	bool empty()
	{
		return m_iSize == 0;
	}

	void clear()
	{
		// ���� ���� �� capasity�� �״�� �ΰ�
		// m_iSize �� 0���� �ʱ�ȭ�Ѵ�.
		for (int i = 0; i < m_iSize; i++)
		{
			m_pArray[i + 1].m_Data = 0;
		}

		m_iSize = 0;
	}

	T operator [](int idx) const
	{
		// begin������ + 1
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}

	void assign(int iSize, const T& data)
	{
		reserve(iSize);
		for (int i = 0; i < iSize; ++i)
		{
			push_back(data);
		}
	}

	T at(int iSize) const
	{
		// [] ���� �������� ������ �����ؼ�.
		if (size() >= iSize + 1)
		{
			return m_pArray[iSize + 1].m_Data;
		}
		else
		{
			assert(false);
		}
		return m_pBegin->m_Data;
	}

	T back()
	{
		if (empty())
			assert(false);

		return m_pArray[m_iSize].m_Data;
	}

	T front()
	{
		if (empty())
			assert(false);

		return m_pArray[1].m_Data;
	}

	int index(int idx)
	{
		return m_pArray[idx + 1].m_iIndex;
	}

	void push_front(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		for (int i = m_iSize + 1; i > 1; --i)
		{
			m_pArray[i].m_Data = m_pArray[i - 1].m_Data;
		}

		m_pArray[1].m_Data = data;
		m_pArray[1].m_iIndex = 1;

		++m_iSize;
	}

	void pop_back()
	{
		if (empty())
		{
			assert(false);
		}
		m_pArray[m_iSize].m_Data = 0;
		m_pArray[m_iSize].m_iIndex = 0;
		--m_iSize;
	}

	void pop_front()
	{
		erase(0);
	}

	void erase(int num)
	{
		if (empty())
		{
			assert(false);
		}
		else
		{
			for (int i = num + 1; i < m_iSize; i++)
			{
				m_pArray[i - 1].m_Data = m_pArray[i].m_Data;
			}
			--m_iSize;
		}
		
	}


public :
	iterator begin()
	{
		iterator iter;
		iter.Pos = &m_pArray[1];
		return iter;
	}

	iterator end()
	{
		iterator iter;
		iter.Pos = &m_pArray[m_iSize];
		return iter;
	}

};