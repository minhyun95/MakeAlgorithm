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


void StackTest();
void VectorTest();
void LinkedTest();
void QueueTest();
void HeapTest();
void TreeTest();
int main()
{
	TreeTest();

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

	cout << "vec.push_back(5); 뒤에 5를 추가" << endl;
	cout << "vec.push_front(9);  앞에 9를 추가 (vec.size()만큼 이동시켜야함)" << endl;
	vec.push_back(9);
	vec.push_front(1);
	cout << "vec.at(0) : " << vec.at(0) << endl;
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;

	cout << endl << endl;
	// 초기화 후 2로 5칸을 만든다.
	cout << "vec.assign(5,2) - 초기화 후 resize로 5칸을 2로 초기화한다." << endl;
	vec.assign(5, 2);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "vec[" << i << "] : " << vec[i] << endl;
	}
	cout << "size		: " << vec.size() << endl;
	cout << "capasity	: " << vec.capasity() << endl;
	cout << endl << endl;

	cout << "vec.push_back(5); 뒤에 5를 추가" << endl;
	cout << "vec.push_front(9);  앞에 9를 추가 (vec.size()만큼 이동시켜야함)" << endl;
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
	cout << "모든 값을 초기화 하지만 capasity는 그대로" << endl;
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
		tstudent->strName = "무작위";
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
		cout << "학생 이름 : " << (*iter).strName << endl;
		cout << "학번 : " << (*iter).iNumber << endl;
		cout << "국어 점수 : " << (*iter).iKor << endl;
		cout << "영어 점수 : " << (*iter).iEng << endl;
		cout << "수학 점수 : " << (*iter).iMath << endl;
		cout << "총 점수 : " << (*iter).iSum << endl;
		cout << "평균 점수 : " << (*iter).fAvg << endl;
	}

	tStudentList.sort(StudentSort);
	cout << "정렬" << endl;
	for (iter = tStudentList.begin(); iter != iterEnd; ++iter)
	{
		cout << "-------------------------" << endl;
		cout << "학생 이름 : " << (*iter).strName << endl;
		cout << "학번 : " << (*iter).iNumber << endl;
		cout << "국어 점수 : " << (*iter).iKor << endl;
		cout << "영어 점수 : " << (*iter).iEng << endl;
		cout << "수학 점수 : " << (*iter).iMath << endl;
		cout << "총 점수 : " << (*iter).iSum << endl;
		cout << "평균 점수 : " << (*iter).fAvg << endl;
	}
}

void TreeTest()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1); // bt1에 1 저장
	SetData(bt2, 2); // bt1에 2 저장
	SetData(bt3, 3); // bt1에 3 저장
	SetData(bt4, 4); // bt1에 4 저장

	MakeLeftSubTree(bt1, bt2);		// bt2를 bt1의 왼쪽 자식 노드로
	MakeRightSubTree(bt1, bt3);		// bt3를 bt1의 오른쪽 자식 노드로
	MakeLeftSubTree(bt2, bt4);		// bt4를 bt2의 왼쪽 자식 노드로

	// 자식 출력
	////bt1의 왼쪽 자식 노드의 데이터 출력
	//printf("%d \n", GetData(GetLeftSubTree(bt1)));

	//// bt2의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
	//printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	InorderTraverse(bt1, ShowData);
	cout << "\n";
	PreorderTraverse(bt1, ShowData);
	cout << "\n";
	PostorderTraverse(bt1, ShowData);
}