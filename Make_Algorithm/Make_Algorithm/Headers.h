#pragma once

#ifndef __HEADERS_H__
#define __HEADERS_H__

#include "Default.h"
#include <time.h>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include <queue>
#include "BinaryTree.h"
#include "Heap.h"
#include "Graph.h"
#include "HashTable_Chaning.h"
#include "HashTable_Array.h"
#include "Tree_Complete.h"
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

#endif // !__HEADERS_H__