#pragma once

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <list>
#include <stack>
#include <iostream>
using namespace std;

typedef struct _ual
{
	list<int> adjList;
}ALGraph;


class CGraph
{
public:
	CGraph()
	{
	}
	~CGraph()
	{
		GraphDestroy();
	}


private:
	ALGraph* m_Graph;
	int*	m_pVisit;
	int		m_inumV;
	int		m_inumE;

public:
	// �׷����� �ʱ�ȭ
	void GraphInit(int nv)
	{
		m_Graph = new ALGraph[nv];
		m_pVisit = new int[nv];
		m_inumV = nv;
		m_inumE = 0;
	}


	// ������ �߰�
	void AddEdge(int fromV, int toV) 
	{
		m_Graph[fromV].adjList.push_back(toV);
		m_Graph[toV].adjList.push_back(fromV);
		++m_inumE;
	}

	// ������ ���� ���
	void ShowGraphEdgeInfo()
	{
		cout << "�������������������������������������������� �������� ���  ��������������������������������������������������" << endl;
		cout << "����� char ������ �Ѵ�." << endl;
		for (int i = 0; i < m_inumV; i++)
		{
			cout << "---" << endl;
			list<int>::iterator iter = m_Graph[i].adjList.begin();
			list<int>::iterator iterEnd = m_Graph[i].adjList.end();
			cout << static_cast<char>(i + 65) << "�� ����� ����: ";
			for (iter = m_Graph[i].adjList.begin(); iter != iterEnd; ++iter)
			{
				cout << static_cast<char>(*iter + 65) << "  ";
			}
			cout << endl;
		}
	}

	
	// DFS ���� �׷����� ���� ���� ���
	void DFSShowGraphVertex(int startV)
	{
		cout << endl;
		cout << "����������������������������������������������������������������������������������������������������" << endl;
		cout << "DFS : ���� ���� " << static_cast<char>(startV + 65) << endl;
		memset(m_pVisit, 0, sizeof(&m_pVisit) * m_inumV);

		stack<int> vStack;
		int visitV = startV;
		DFS(visitV, vStack);
		while (!vStack.empty())
		{
			int top = vStack.top();
			vStack.pop();
		}
		cout << endl;
		cout << "����������������������������������������������������������������������������������������������������" << endl;
	}

	


private:
	// �׷����� ���ҽ� ����
	void GraphDestroy()
	{
		for (int i = 0; i < m_inumV; i++)
		{
			m_Graph[i].adjList.clear();
		}
		delete[] m_Graph;
		m_Graph = nullptr;
		delete[] m_pVisit;
		m_pVisit = nullptr;
		m_inumE = 0;
		m_inumV = 0;
	}
	// ������ �湮 ����
	int VisitVertex(int visitV)
	{
		if (m_pVisit[visitV] == 0) // ù �湮�϶��� 
		{
			m_pVisit[visitV] = 1;  // �̹� �湮�� ���� ���
			printf("%c\t", static_cast<char>(visitV + 65));
			return 1;  // �湮 ����
		}
		return 0;  // �̹� �湮�� ��
	}

	// ��������� �����ؼ� �湮���� ���� ��� Ž��
	void DFS(int startV, stack<int>& a)
	{
		if (VisitVertex(startV) == true)
		{
			a.push(startV);
			list<int>::iterator iter;
			list<int>::iterator iterEnd = m_Graph[startV].adjList.end();
			for (iter = m_Graph[startV].adjList.begin(); iter != iterEnd; ++iter)
			{
				DFS(*iter, a);
			}
		}
		else
		{
			return;
		}
	}
};


#endif // !__GRAPH_H__