#include "LinkedList.h"
#include <iostream>
#include <time.h>
using namespace std;

bool func(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	LinkedList<int> intlist;

	srand(unsigned(time(NULL)));
	for (int i = 0; i < 100; i++)
	{
		//intlist.push_back(rand() % 100);
		intlist.push_back(i);
	}
	LinkedList<int>::iterator iter;
	LinkedList<int>::iterator iterEnd = intlist.end();

	for (iter = intlist.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}

	intlist.erase(5);
	cout << "--sort--" << endl;
	intlist.sort(func);

	for (iter = intlist.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}