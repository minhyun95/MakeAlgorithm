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
	// 그래프의 초기화
	void GraphInit(int nv)
	{
		m_Graph = new ALGraph[nv];
		m_pVisit = new int[nv];
		m_inumV = nv;
		m_inumE = 0;
	}


	// 간선의 추가
	void AddEdge(int fromV, int toV) 
	{
		m_Graph[fromV].adjList.push_back(toV);
		m_Graph[toV].adjList.push_back(fromV);
		++m_inumE;
	}

	// 간선의 정보 출력
	void ShowGraphEdgeInfo()
	{
		cout << "────────────────────── 간선정보 출력  ─────────────────────────" << endl;
		cout << "출력은 char 형으로 한다." << endl;
		for (int i = 0; i < m_inumV; i++)
		{
			cout << "---" << endl;
			list<int>::iterator iter = m_Graph[i].adjList.begin();
			list<int>::iterator iterEnd = m_Graph[i].adjList.end();
			cout << static_cast<char>(i + 65) << "에 연결된 정점: ";
			for (iter = m_Graph[i].adjList.begin(); iter != iterEnd; ++iter)
			{
				cout << static_cast<char>(*iter + 65) << "  ";
			}
			cout << endl;
		}
	}

	
	// DFS 실행 그래프의 정점 정보 출력
	void DFSShowGraphVertex(int startV)
	{
		cout << endl;
		cout << "──────────────────────────────────────────────────" << endl;
		cout << "DFS : 시작 정점 " << static_cast<char>(startV + 65) << endl;
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
		cout << "──────────────────────────────────────────────────" << endl;
	}

	


private:
	// 그래프의 리소스 해제
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
	// 정점의 방문 진행
	int VisitVertex(int visitV)
	{
		if (m_pVisit[visitV] == 0) // 첫 방문일때만 
		{
			m_pVisit[visitV] = 1;  // 이미 방문한 것을 기록
			printf("%c\t", static_cast<char>(visitV + 65));
			return 1;  // 방문 성공
		}
		return 0;  // 이미 방문한 곳
	}

	// 재귀적으로 실행해서 방문하지 않은 노드 탐색
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