#include <iostream>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__ )
#endif

using namespace std;

int main()
{
	byte* buff = new byte[100];

	_CrtDumpMemoryLeaks();

	return 0;
}