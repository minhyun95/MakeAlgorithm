#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	unordered_map<int, string> idNames;
	// unordered_multimap = 같은 키값이여도 중복을 허용한다.

	idNames.emplace(1, "이름1");
	idNames.emplace(2, "이름2");
	idNames.emplace(3, "이름3");

	// 중복은 적용안됌
	idNames.emplace(1, "4");


	// [] 연산자를 사용하면 replace 가능
	// 없는 키를 사용하면 생성되기때문에 주의해서 사용해야 한다.
	idNames[1] = "빙고";



	for (const auto& idname : idNames)
	{
		cout << idname.first << " " << idname.second << endl;
	}

	return 0;
}