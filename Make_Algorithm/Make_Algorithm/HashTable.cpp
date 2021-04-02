#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// Hashtable to implemant 905, Jimmy

class HashTable
{
private :
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups]; // List 1, Indexo 0, List 2, Index 1

public :
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i = 0; i < hashGroups; ++i)
	{
		sum += table[i].size();
	}

	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key)
{
	  
}