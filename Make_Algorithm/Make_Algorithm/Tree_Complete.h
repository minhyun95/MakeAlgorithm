#pragma once

#ifndef __TREE_COMPLETE_H__
#define __TREE_COMPLETE_H__

#include "Default.h"
class CTree_Node
{
	friend class CTree_Binary;
public:
	explicit CTree_Node()
		: m_LeftSubTree(nullptr), m_RightSubTree(nullptr), m_Data(INT_MAX)
	{
	}
	explicit CTree_Node(int _data)
		: m_LeftSubTree(nullptr), m_RightSubTree(nullptr), m_Data(_data)
	{

	}
	~CTree_Node()
	{
	}
private:
	int			m_Data;
	CTree_Node* m_LeftSubTree;
	CTree_Node* m_RightSubTree;

public:
	const int Cout_Data_Function() const
	{
		return m_Data;
	}
	void PreOrder_Cout() /* ���� ��ȸ */
	{
		if (m_LeftSubTree != nullptr)
			m_LeftSubTree->PreOrder_Cout();
		if (m_RightSubTree != nullptr)
			m_RightSubTree->PreOrder_Cout();
		cout << m_Data << endl;
	}
	void PostOrder_Cout() /* ���� ��ȸ*/
	{
		cout << m_Data << endl;
		if (m_LeftSubTree != nullptr)
			m_LeftSubTree->PostOrder_Cout();
		if (m_RightSubTree != nullptr)
			m_RightSubTree->PostOrder_Cout();
	}
	void InOrder_Cout() /* ���� ��ȸ */
	{

		if (m_LeftSubTree != nullptr)
			m_LeftSubTree->InOrder_Cout();
		cout << m_Data << endl;
		if (m_RightSubTree != nullptr)
			m_RightSubTree->InOrder_Cout();
	}
};

class CTree_Binary
{
public:
	CTree_Binary()
	{
		m_Root = nullptr;
	}
	~CTree_Binary()
	{
	}

private:
	typedef CTree_Node  NODE;
	typedef CTree_Node* PNODE;

private:
	PNODE m_Root;

public:
	void BT_Insert(int _data)
	{
		if (m_Root == nullptr) /* ���� Insert */
		{
			m_Root = new NODE;
			m_Root->m_Data = _data;
		}
		else /* ��Ʈ��Ʈ�� ������� ���� ��  */
		{
			PNODE Nownode = m_Root;
			PNODE ParentNode = nullptr;
			while (Nownode != nullptr)
			{
				if (Nownode->m_Data == _data) /* �ߺ� ��� ���� */
				{
					cout << "�ߺ��� : " << _data << endl;
					return;
				}

				if (Nownode->m_Data > _data) /* ���� ���� Ʈ���� �̵� (���� �� Input)*/
				{
					ParentNode = Nownode;
					Nownode = Nownode->m_LeftSubTree;
					if (Nownode == nullptr)
					{
						Nownode = new NODE(_data);
						cout << "�θ� (" << ParentNode->m_Data << ")�� ���� ����Ʈ���� ����� : " << _data << endl;
						ParentNode->m_LeftSubTree = Nownode;
						return;
					}
				}
				else /* ������ ���� Ʈ���� �̵� (ū �� Input) */
				{
					ParentNode = Nownode;
					Nownode = Nownode->m_RightSubTree;
					if (Nownode == nullptr)
					{
						Nownode = new NODE(_data);
						cout << "�θ� (" << ParentNode->m_Data << ")�� ������ ����Ʈ���� ����� : " << _data << endl;
						ParentNode->m_RightSubTree = Nownode;
						return;
					}
				}
			}
		}
	}
	bool BT_Search(int _Searchdata)
	{
		PNODE NowNode = m_Root;
		while (NowNode != nullptr)
		{
			if (NowNode->m_Data == _Searchdata)
				return true;
			if (NowNode->m_Data > _Searchdata)
			{
				NowNode = NowNode->m_LeftSubTree;
			}
			else
			{
				NowNode = NowNode->m_RightSubTree;
			}
		}

		return false;
	}
	void Delete(int num)
	{
		m_Root = BT_Delete(m_Root, num);
	}
	void Output()
	{
		if (m_Root)
		{
			m_Root->InOrder_Cout();
		}
	}

private:
	PNODE BT_Delete(PNODE root,int _Deletedata)
	{
		PNODE p = root;
		PNODE parent = nullptr;
		while ((p != nullptr) && (p->m_Data != _Deletedata))
		{
			parent = p;
			if (p->m_Data < _Deletedata)
				p = p->m_RightSubTree;
			else
				p = p->m_LeftSubTree;

			if (p == nullptr)
			{
				return root;
			}
		}

		if (p->m_LeftSubTree == nullptr && p->m_RightSubTree == nullptr)
		{
			if (parent == nullptr) /* ��Ʈ��Ʈ�� �����Ǵ� ��� */
				root = nullptr;
			else
			{
				if (parent->m_LeftSubTree == p)
					parent->m_LeftSubTree = nullptr;
				else
					parent->m_RightSubTree = nullptr;
			}
		}
		else if (p->m_LeftSubTree == nullptr || p->m_RightSubTree == nullptr)
		{
			PNODE child = (p->m_LeftSubTree != nullptr) ? p->m_LeftSubTree : p->m_RightSubTree;

			if (parent == nullptr) /* ��Ʈ��Ʈ�� �����Ǵ� ��� */
				root = child;
			else
			{
				if (parent->m_LeftSubTree == p)
					parent->m_LeftSubTree = child;
				else
					parent->m_RightSubTree = child;
			}
		}
		else 
		{
			PNODE succ_parent = p;
			PNODE succ = p->m_RightSubTree;

			while (succ->m_LeftSubTree != nullptr)
			{
				succ_parent = succ;
				succ = succ->m_LeftSubTree;
			}
			p->m_Data = succ->m_Data;
			if(succ_parent->m_LeftSubTree == succ)
				succ_parent->m_LeftSubTree = succ->m_RightSubTree;
			else
				succ_parent->m_RightSubTree = succ->m_RightSubTree;

			p = succ;
		}


		delete p;
		return root;
	}

};

#endif // !__TREE_COMPLETE_H__