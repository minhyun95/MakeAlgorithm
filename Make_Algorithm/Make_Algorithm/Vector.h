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

// iterator ����
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

		// �ʱ�ȭ
		// End�� Begin���� ���ļ� + 2 ��ŭ 
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
		// �޸� ����
		delete[]	m_pArray;
	}

private :
	typedef VectorNode<T>	NODE;
	typedef VectorNode<T>*	PNODE;
	typedef Vectoriterator<T> iterator;

private :
	PNODE m_pArray;
	unsigned int	m_iSize;
	unsigned int	m_iCapasity; // �迭�� �� ���� (2�辿 �þ)

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
};