#include "Headers.h"

bool StudentSort(const STUDENT& s, const STUDENT& s2)
{
	if (s.iMath < s2.iMath)
	{
		return true;
	}
	else if ((s.iMath == s2.iMath))
	{
		return s.iNumber > s2.iNumber;
	}

	return false;
}


/*	���� �׽�Ʈ			*/void StackTest();
/*	���� �׽�Ʈ			*/void VectorTest();
/*	��ũ�帮��Ʈ �׽�Ʈ	*/void LinkedTest();
/*	ť �׽�Ʈ			*/void QueueTest();
/*	�� �׽�Ʈ			*/void HeapTest();
/*	Ʈ�� �׽�Ʈ			*/void TreeTest();
/*	�׷��� �׽�Ʈ			*/void GraphTest();
/*	�ؽ����̺� �׽�Ʈ		*/void HashTable_TEST();
/*	�ؽþ�� �׽�Ʈ		*/void HashArray_TEST();

typedef int(*HashFunc)(int key);
int a(int k)
{
	return k;
}

HashFunc* b = (HashFunc*)a;
int main()
{
	HashArray_TEST();
	return 0;
}

void QueueTest()
{
	Queue<int> q;

	cout << "empty: " << q.isEmpty() << endl;

	cout << "push 5  push 10 " << endl;
	q.Enqueue(5);
	q.Enqueue(10);
	cout << "front: " << q.front() << endl;
	cout << "front: " << q.front() << endl;
	cout << "empty: " << q.isEmpty() << endl;
	cout << "size : " << q.size() << endl;
	cout << "Deque: " << q.Dequeue() << endl;
	cout << "front: " << q.front() << endl;
	cout << "Deque: " << q.Dequeue() << endl;
	cout << "front: " << q.front() << endl;
	cout << "size : " << q.size() << endl;
	cout << "empty: " << q.isEmpty() << endl;
}
void HeapTest()
{
	Heap hp;
	hp.HeapDelete();
	hp.HeapPush(5);
	hp.HeapPush(10);
	hp.HeapPush(12);
	hp.HeapPush(18);
	hp.HeapPush(24);
	hp.HeapPush(30);
	cout << "1" << endl;
	hp.ShowHeap();
	cout << "2" << endl;
	cout << "Delete : " << hp.HeapDelete() << endl;
	cout << "Delete : " << hp.HeapDelete() << endl;
	cout << "Delete : " << hp.HeapDelete() << endl;
	cout << "3" << endl;
	hp.ShowHeap();
	cout << "4" << endl;

}



void StackTest()
{
	CStack<int> stack;
	stack.push(5);
	cout << "isEmpty : " << stack.isEmpty() << endl;
	cout << "peek : " << stack.peek() << endl;
	stack.push(10);
	cout << "peek : " << stack.peek() << endl;
	cout << "pop : " << stack.pop() << endl;
	cout << "peek : " << stack.peek() << endl;
	cout << "pop : " << stack.pop() << endl;
	cout << "peek : " << stack.peek() << endl;
	cout << "pop : " << stack.pop() << endl;
	cout << "isEmpty : " << stack.isEmpty() << endl;

}
void VectorTest()
{
	Vector<int> vec;

	cout << "vec.push_back(5); �ڿ� 5�� �߰�" << endl;
	cout << "vec.push_front(9);  �տ� 9�� �߰� (vec.size()��ŭ �̵����Ѿ���)" << endl;
	vec.push_back(9);
	vec.push_front(1);
	cout << "vec.at(0) : " << vec.at(0) << endl;
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;

	cout << endl << endl;
	// �ʱ�ȭ �� 2�� 5ĭ�� �����.
	cout << "vec.assign(5,2) - �ʱ�ȭ �� resize�� 5ĭ�� 2�� �ʱ�ȭ�Ѵ�." << endl;
	vec.assign(5, 2);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "vec[" << i << "] : " << vec[i] << endl;
	}
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;
	cout << endl << endl;

	cout << "vec.push_back(5); �ڿ� 5�� �߰�" << endl;
	cout << "vec.push_front(9);  �տ� 9�� �߰� (vec.size()��ŭ �̵����Ѿ���)" << endl;
	vec.push_back(5);
	vec.push_front(9);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << "vec[" << i << "] : " << vec[i] << endl;
	}
	cout << endl << endl;
	cout << "back() : " << vec.back() << endl;
	cout << "front() : " << vec.front() << endl;

	cout << "---resize Test---" << endl;
	vec.resize(100);
	cout << "vec.resize(100) " << endl;
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;

	cout << "--- begin end (iterator) ---" << endl;
	cout << "*vec.begin() : " << *vec.begin() << endl;
	cout << "*vec.end() : " << *vec.end() << endl;

	cout << "--- clear ---" << endl;
	vec.clear();
	cout << "��� ���� �ʱ�ȭ ������ capasity�� �״��" << endl;
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;
	cout << "vec.empty() : " << vec.empty() << endl;

	cout << "--- reserve ---" << endl;
	cout << "vec.reserve(50)" << endl;
	vec.reserve(50);
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;
}
void LinkedTest()
{
	LinkedList<STUDENT> tStudentList;

	srand(unsigned(time(NULL)));

	for (int i = 0; i < 15; i++)
	{
		PSTUDENT tstudent = new STUDENT;
		tstudent->strName = "������";
		tstudent->iNumber = i + 1;
		tstudent->iKor = rand() % 11;
		tstudent->iEng = rand() % 11;
		tstudent->iMath = rand() % 11;
		tstudent->iSum = tstudent->iKor + tstudent->iEng + tstudent->iMath;
		tstudent->fAvg = tstudent->iSum / 3.f;

		tStudentList.push_back(*tstudent);
	}

	LinkedList<STUDENT>::iterator iter;
	LinkedList<STUDENT>::iterator iterEnd = tStudentList.end();

	for (iter = tStudentList.begin(); iter != iterEnd; ++iter)
	{
		cout << "-------------------------" << endl;
		cout << "�л� �̸� : " << (*iter).strName << endl;
		cout << "�й� : " << (*iter).iNumber << endl;
		cout << "���� ���� : " << (*iter).iKor << endl;
		cout << "���� ���� : " << (*iter).iEng << endl;
		cout << "���� ���� : " << (*iter).iMath << endl;
		cout << "�� ���� : " << (*iter).iSum << endl;
		cout << "��� ���� : " << (*iter).fAvg << endl;
	}

	tStudentList.sort(StudentSort);
	cout << "����" << endl;
	for (iter = tStudentList.begin(); iter != iterEnd; ++iter)
	{
		cout << "-------------------------" << endl;
		cout << "�л� �̸� : " << (*iter).strName << endl;
		cout << "�й� : " << (*iter).iNumber << endl;
		cout << "���� ���� : " << (*iter).iKor << endl;
		cout << "���� ���� : " << (*iter).iEng << endl;
		cout << "���� ���� : " << (*iter).iMath << endl;
		cout << "�� ���� : " << (*iter).iSum << endl;
		cout << "��� ���� : " << (*iter).fAvg << endl;
	}
}

void TreeTest()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1); // bt1�� 1 ����
	SetData(bt2, 2); // bt1�� 2 ����
	SetData(bt3, 3); // bt1�� 3 ����
	SetData(bt4, 4); // bt1�� 4 ����

	MakeLeftSubTree(bt1, bt2);		// bt2�� bt1�� ���� �ڽ� ����
	MakeRightSubTree(bt1, bt3);		// bt3�� bt1�� ������ �ڽ� ����
	MakeLeftSubTree(bt2, bt4);		// bt4�� bt2�� ���� �ڽ� ����

	// �ڽ� ���
	////bt1�� ���� �ڽ� ����� ������ ���
	//printf("%d \n", GetData(GetLeftSubTree(bt1)));

	//// bt2�� ���� �ڽ� ����� ���� �ڽ� ����� ������ ���
	//printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	InorderTraverse(bt1, ShowData);
	cout << "\n";
	PreorderTraverse(bt1, ShowData);
	cout << "\n";
	PostorderTraverse(bt1, ShowData);
}

void GraphTest()
{
	enum { A, B, C, D, E, F, G, H, I, J };
	CGraph graph;
	graph.GraphInit(10);
	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	graph.ShowGraphEdgeInfo();
	graph.DFSShowGraphVertex(A);
	graph.DFSShowGraphVertex(C);
	graph.DFSShowGraphVertex(E);
	graph.DFSShowGraphVertex(G);
}


void HashTable_TEST()
{
	HashTable tb;
	tb.Initialize(100, hash_func);
	for (int i = 0; i < 10; i++)
	{
		tb.Insert(i);
	}
	tb.Search(5);
	tb.Search(11);
	tb.Delete(3);
	tb.Delete(4);
	tb.Delete(5);
	tb.Delete(6);

}

void HashArray_TEST()
{
	HashTableArray htA(100);

	for (int i = 0; i < 25; i++)
	{
		htA.Insert(i + rand() % 1000, rand() % 100, rand() % 100);
	}

	htA.Search(1);
	htA.Delete(1);
	cout <<	htA.Search(1) << endl;

	htA.ShowAll();
	cout << endl;
	cout << endl;
	htA.Show_Frequency();
}