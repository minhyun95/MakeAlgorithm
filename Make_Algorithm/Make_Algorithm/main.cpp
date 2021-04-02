#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include <queue>
using namespace std;

typedef struct _tagStudent
{
	string strName;
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iSum;
	float	fAvg;


}STUDENT, *PSTUDENT;

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
int main()
{
	//StackTest();
	QueueTest();
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