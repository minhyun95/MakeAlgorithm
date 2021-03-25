#pragma once

template <typename T>
class VectorNode
{
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

// iterator 구현
template <typename T>
class Vectoriterator
{
	template <typename T>
	friend class Vector;

private :
	Vectoriterator()
	{

	}
	~Vectoriterator()
	{

	}

private :
	typedef VectorNode<T>* PNODE;

private :
	PNODE m_pNode;

public :
	bool operator ==(const Vectoriterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator !=(const Vectoriterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode + sizeof(T);
	}
};

template <typename T>
class Vector
{
public :
	Vector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		// 초기화
		// End와 Begin까지 합쳐서 + 2 만큼 
		m_pArray = new VectorNode<T>[m_iCapasity + 2];
	}
	Vector(int iSize)
	{
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~Vector()
	{
		// 메모리 해제
		delete[]	m_pArray;
	}

private :
	typedef VectorNode<T>	NODE;
	typedef VectorNode<T>*	PNODE;
	typedef Vectoriterator<T> iterator;

private :
	PNODE m_pArray;
	unsigned int	m_iSize;
	unsigned int	m_iCapasity; // 배열의 총 개수 (2배씩 늘어남)

public :
	void push_back(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		// 0번은 begin이다. 그런데 실제 1번인덱스부터 노드가
		// 추가되는데 처음 추가된 노드는 0번부터 인덱스를 주도록한다.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}
	
	void resize(int iSize)
	{
		// Begin End 노드 포함 + 2
		PNODE pArray = new NODE[iSize + 2];

		// 2배만큼 할당한 공간에 기존에 있는 데이터를
		// 기존의 공간만큼 복사한다.
		// 0번은 Begin이기때문에 0번부터 복사하지말고 1번부터 복사한다. ( +1 하는 이유 )
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		// 기존 노드를 삭제한다.
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;

	}

	unsigned int size() const
	{
		return m_iSize;
	}

	unsigned int capasity() const
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

	T operator [](int idx) const
	{
		// begin때문에 + 1
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}
};