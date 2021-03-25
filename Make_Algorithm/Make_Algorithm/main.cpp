#include "LinkedList.h"
#include <iostream>
#include <time.h>
#include <string>
#include "Vector.h"
#include <vector>
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

void LinkedTest();
int main()
{
	vector<int> a;
	a.assign;
	a.at;
	a.back;
	a.begin;
	a.capacity;
	a.cbegin;
	a.cend;
	a.clear;
	a.crbegin;
	a.crend;
	a.data;
	a.emplace;
	a.emplace_back;
	a.empty;
	a.end;
	a.erase;
	a.front;
	a.insert;
	a.max_size;
	a.pop_back;
	a.push_back;
	a.rbegin;
	a.rend;
	a.reserve;
	a.resize;
	a.size;
	a.swap;


	Vector<int> vec;

	vec.reserve(100);
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;;
	}
	cout << vec.capasity() << endl;

	return 0;
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